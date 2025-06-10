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
After running the emulator, you can open the generated CSV file with any compatible tool (like a spreadsheet program) to view the processed and analyzed instruction data.

Here's a snapshot of some of the instructions processed:
![image](https://github.com/user-attachments/assets/9e750575-3644-45ee-87e1-642862f47fa7)"

## Credits

Inspired by [Austin Morlan’s CHIP-8 tutorial](https://austinmorlan.com/posts/chip8_emulator/).  
This implementation adds extensive performance profiling and analysis features beyond the original.

