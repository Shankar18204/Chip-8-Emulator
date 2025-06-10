# CHIP-8 Emulator with Opcode-Level Profiling

This is a C++ CHIP-8 emulator built with a focus on **performance analysis** and **opcode-level profiling**.  
It allows you to visualize how much time each instruction takes, find performance bottlenecks, and understand the CPU's execution profile while running real CHIP-8 ROMs.

## Features

-  Full CHIP-8 instruction set support
-  Opcode-level profiler with:
  - Execution counts
  - Timing (min, max, average per opcode)
  - CSV logging (`profile.csv`)
-  Clean, modular C++ design
-  Optional terminal summary output
-  Easy to extend for future features (e.g., real-time UI, SDL rendering)

##  Running the Emulator

### Prerequisites:
- C++17 or higher
- A standard compiler (G++, Clang++, MSVC)

Build the project:
```bash
./build_script.sh
```
Navigate to the builds directory:
```bash
cd builds
```
Run the emulator with a ROM:
```bash
./chip8 10 1 ../ROMs/ <any chip8 ROM>
```
Replace <any chip8 ROM> with the actual filename of the CHIP-8 ROM you want to run.

### Viewing Analysis Data
After execution, a CSV file profile.csv is generated containing profiling data.
Open it with any spreadsheet software or plot the data for analysis.

Example snapshot:
| Opcode | Call Count | Avg Time (μs) | Min Time (μs) | Max Time (μs) |
|--------|------------|----------------|----------------|----------------|
| 1248   | 1          | 2.712          | 2.712          | 2.712          |
| F633   | 1          | 3.010          | 3.010          | 3.010          |
| F065   | 1          | 2.010          | 2.010          | 2.010          |
| A3E9   | 1          | 2.478          | 2.478          | 2.478          |
| F155   | 1          | 3.352          | 3.352          | 3.352          |
| 6130   | 1          | 1.848          | 1.848          | 1.848          |
| 6000   | 1          | 3.017          | 3.017          | 3.017          |
| 4607   | 1          | 2.679          | 2.679          | 2.679          |
| 3207   | 1          | 1.807          | 1.807          | 1.807          |
| 660F   | 1          | 2.511          | 2.511          | 2.511          |
| 46C0   | 1          | 3.478          | 3.478          | 3.478          |
| 8xyE   | 1          | 0.092          | 0.092          | 0.092          |
| 47EC   | 1          | 2.577          | 2.577          | 2.577          |
| 8765   | 1          | 3.721          | 3.721          | 3.721          |
| 8xy5   | 1          | 0.133          | 0.133          | 0.133          |
| 6930   | 1          | 2.127          | 2.127          | 2.127          |
| 6689   | 1          | 3.508          | 3.508          | 3.508          |
| 8xy6   | 1          | 0.074          | 0.074          | 0.074          |
| 682C   | 1          | 2.186          | 2.186          | 2.186          |
| 8764   | 1          | 3.088          | 3.088          | 3.088          |
| 866E   | 1          | 4.104          | 4.104          | 4.104          |
| 8xy4   | 1          | 0.089          | 0.089          | 0.089          |
| 678C   | 1          | 1.961          | 1.961          | 1.961          |
| 4718   | 2          | 2.9615         | 2.853          | 3.070          |
| A23A   | 2          | 2.7925         | 2.314          | 3.271          |
| 5xy0   | 1          | 0.113          | 0.113          | 0.113          |



## Credits

Inspired by [Austin Morlan’s CHIP-8 tutorial](https://austinmorlan.com/posts/chip8_emulator/).  
This implementation adds extensive performance profiling and analysis features beyond the original.

