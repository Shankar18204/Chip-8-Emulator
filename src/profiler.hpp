#pragma once
#include <fstream>
#include <chrono>
#include <string>
#include <unordered_map>
#include <limits>
#include <iostream>


class Profiler {
    public:
        Profiler(bool enabled, const std::string& filename)
            : enabled(enabled), file(filename, std::ios::out)
        {
            if(enabled && file.is_open()) {
                file << "opcode, call_count, avg_time_microseconds, min_time_microseconds, max_time_microseconds\n";

            }
        }

        ~Profiler(){
            if(file.is_open()){
                DumpStatsToFile();
                file.close();
            }
            PrintStatsToConsole();
        }

        template<typename F>
        void ProfileOpcode(const std::string& opcodeStr, F&& func){
            if(!enabled) {
                func();
                return;
            }

        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration< double, std::micro> duration = end - start;

        double elapsed = duration.count();

        auto& stats = opcodeStats[opcodeStr];
        stats.callCount++;
        stats.totalTime += elapsed;
        if(elapsed < stats.minTime) stats.minTime = elapsed;
        if(elapsed > stats.maxTime) stats.maxTime = elapsed;
    }

    private:
        struct OpcodeStats {
            size_t callCount = 0;
            double totalTime = 0.0;
            double minTime = std::numeric_limits<double>::max();
            double maxTime = 0.0;
        };
        
        std::unordered_map<std::string, OpcodeStats> opcodeStats;
        bool enabled;
        std::ofstream file;

        void DumpStatsToFile() {
            for (const auto& [opcode, stats] : opcodeStats) {
                double avg = stats.callCount > 0 ? stats.totalTime / stats.callCount : 0.0;
                file << opcode << ","
                    << stats.callCount << ","
                    << avg << ","
                    << stats.minTime << ","
                    << stats.maxTime << "\n";
            }
        }

        void PrintStatsToConsole() {
            std::cout << "\nOpcode profiling summary: \n";
            std::cout << "Opcode \tCalls\tAvg(us)\tMin(us)\n";
            for(const auto& [opcode, stats] : opcodeStats) {
                double avg = stats.callCount > 0 ? stats.totalTime / stats.callCount : 0.0;
                std::cout << opcode << "\t"
                          << stats.callCount << "\t"
                          << avg << "\t"
                          << stats.minTime << "\t"
                          << stats.maxTime << "\n";
                          
            }
        }

};