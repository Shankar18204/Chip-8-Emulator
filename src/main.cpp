#include "Chip8.hpp"
#include "profiler.hpp"
#include "Platform.hpp"
#include <chrono>
#include <iostream>

Profiler* profiler = nullptr;


int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
        std::exit(EXIT_FAILURE);
    }

    
    int videoScale = std::stoi(argv[1]);       
    int cycleDelay = std::stoi(argv[2]);       
    char const* romFilename = argv[3];         

    static Profiler prof(true, "profile.csv");
    profiler = &prof; 


    std::cout << "[INFO] Scale: " << videoScale
              << ", Delay: " << cycleDelay
              << " ms, ROM: " << romFilename << "\n";

    // Initialize the SDL platform window
    std::cout << "[INFO] Initializing platform...\n";
    Platform platform("CHIP-8 Emulator",
                      VIDEO_WIDTH * videoScale,
                      VIDEO_HEIGHT * videoScale,
                      VIDEO_WIDTH,
                      VIDEO_HEIGHT);
    std::cout << "[INFO] Platform initialized.\n";

    
    Chip8 chip8;
    std::cout << "[INFO] Loading ROM...\n";
    chip8.LoadROM(romFilename);
    std::cout << "[INFO] ROM loaded.\n";

    int videoPitch = sizeof(chip8.video[0]) * VIDEO_WIDTH;


    auto lastCycleTime = std::chrono::high_resolution_clock::now();
    bool quit = false;

    std::cout << "[INFO] Entering main loop. Press ESC to exit.\n";

    while (!quit)
    {
        
        quit = platform.ProcessInput(chip8.keypad);
        
        
        
        auto currentTime = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float, std::chrono::milliseconds::period>(
                       currentTime - lastCycleTime).count();

        if (dt > cycleDelay)
        {
            lastCycleTime = currentTime;

            
            std::cout << "[DEBUG] Running one CPU cycle\n";
            chip8.Cycle();

            
            std::cout << "[DEBUG] Updating screen\n";
            platform.Update(chip8.video, videoPitch);
        }
    }

    std::cout << "[INFO] Exiting emulator.\n";
    return 0;
}
