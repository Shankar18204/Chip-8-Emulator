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
- (Optional) Makefile or build system if you prefer

### Compile with:
```bash
g++ -std=c++17 main.cpp chip8.cpp -o chip8_emulator
