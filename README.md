# C-to-ASM
Langage C to ASM Compiler (Yacc/Lex) and Processor (VHDL)

**Keyword**: C Compiler, Lex, Yacc, ASM, Xilinx ISE, VHDL, FPGA

**Description**: We developped a compiler for C language that generates ASM code. Then, we created a processor using VHDL for an on chip system (FPGA) to execute the ASM code.

**Files**
- `C-Compiler/`
  - `C-Compiler/cly` C compiler to ASM
  - `C-Compiler/asmly` simulate ASM execution 
  - `C-Compiler/asm2oply` generate OP code from ASM code
  - `C-Compiler/test` some C test, if you want to compile your own customized C, you can have a look on some of our examples
- `ASM-Processor/`
  - lib: homepages.laas.fr/bmorgan/soc.tgz
  - `ASM-Processor/Configuration file` configuration file of our processor
  - `ASM-Processor/Entities files` main module `fpga.vhd` and sub-modules
  - `ASM-Processor/RAM files` files for init values of ROM 32 bits (`init32.hex`), RAM 16 bits (`init16.hex`)
  - `ASM-Processor/Test files` simulation of main module `fpgatest.vhd`, and some other test benches for sub-modules

# More detailed informations
## C code
- variable type
  - int, const int
- Declaration & Affectation
- Expression E
  - int, id
  - ADD, MUL, SUB, DIV
  - EQU, INF, INFE, SUP, SUPE
- If & While loop
- Pointer & Malloc
  - type: \*int
  - value: &a
- Function
  - EBP, base pointer
  - allow recursive function
  - allow return value
- Pre/Post incrementation
  - value: i++
  - new loop: for(Affectation,E,id++)

### ASM & OP code
| Operation | Code | OP | | | | Description |
| --- | --- | --- | --- | --- | --- | --- |
| Addition | 0x01 | ADD | Ri | Rj | Rk | [Ri] ← [Rj] + [Rk] |
| Multiplication | 0x02 | MUL | Ri | Rj | Rk | [Ri] ← [Rj] * [Rk] |
| Subtraction  | 0x03 | SUB | Ri | Rj | Rk | [Ri] ← [Rj] - [Rk] |
| Division | 0x04 | DIV | Ri | Rj | Rk | [Ri] ← [Rj] / [Rk] |
| Copy | 0x05 | COP | Ri | Rj | | [Ri] ← [Rj] |
| Assignment | 0x06 | AFC | Ri | j_h | j_l | [Ri] ← j (16bits, j_h & j_l) |
| Load | 0x07 | LOAD | Rbp | j | Ri | @[[Rbp]+j] ← [Ri] |
| Save | 0x08 | STORE | Ri | Rbp | j | [Ri] → @[[Rbp]+j] |
| Equal | 0x09 | EQU | Ri | Rj | Rk | [Ri] ← 1 if [Rj]=[Rk], else 0 |
| Inferior | 0xA | INF | Ri | Rj | Rk | [Ri] ← 1 si [Rj]<[Rk], else 0 |
| Inferior equal | 0xB | INFE | Ri | Rj | Rk | [Ri] ← 1 si [Rj]<=[Rk], else 0 |
| Superior | 0xC | SUP | Ri | Rj | Rk | [Ri] ← 1 si [Rj]>[Rk], else 0 |
| Superior equal | 0xD | SUPE | Ri | Rj | Rk | [Ri] ← 1 si [Rj]>=[Rk], else 0 |
| Jumping | 0xE | JMP | @i_h | @i_l | | Jump to address @i (16bits) |
| Conditional Jumping | 0xF | JMPC | @i_h | @i_l | Ri | Jump to address @i (16bits) if Ri = 0 |
| Jumping to Register | 0x10 | JMPR | Ri | | | Jump to address @[Ri] |


## VHDL code
### Overview
- Conception of a microprocessor,RISC type, with 5 level pipe-line architecture
- Input: `init32.hex`
  - Also works with generated outputs from the C compiler
- RAM Memory: `init16.hex`
  - Implement this file if you want to input values in the RAM memory
- Fréquences de fonctionnement: `92MHz` (A 100 MHz frequency is required, a requirement not satisfied in the actual state of the project)
- Project configurations  
  - Family: Spartan6
  - Device: XC6SLX16
  - Package: CSG324
  - Speed: -3
  - Synthesis Tool: XST (VHDL/Verilog)
  - Simulator: ISim (VHDL/Verilog)
  - Preferred Language: VHDL
  - VHDL Source Analysis Standard: VHDL-93

### Data path
| Instructions | Banc de registres(r) | UAL | Data memory |Banc de registres(w) |
| --- | --- | --- | --- | --- |
| Pointeur d'instruction `ip`| |Logic Controller `lcual`| Logic Controller `lcmem` | Logic Controller `lc` |
| ROM 32 bits `bram32`| Registres `regs/read` | UAL `ual` | RAM `bram16` + VGA `vga_top`| Registres `regs/write` |
| Décodeur `decode`| Multiplexer `mux` | Multiplexer `muxual` | | Multiplexer `muxdata` |

\* `pipeline` Data are transferred synchronously between the different levels of pipeline. Spread OP, A, B and C values on rising_edge(CLK). Also work asynchrously with NOP signal.

\*\* `ctlalea` Control data hazards is set when immediately reading after writing from the same register; Control of branching hazards is related to the Jump instruction.

### Explcation des unités
- IP
  - Synchronous on rising_edge(CLK)
  - Instruction pointer works as a counter and point on the next instruction that is going to be executed
  - When data hazard is detected, the IP stop counting in order to let the writing end
- ROM
  - Synchronous on rising_edge(CLK)
  - Memory of instructions to be executed
- Décode
  - Combinatory mode
  - Decoder that take a 32-bit instruction and split it, depending on the OP-code, in 16-bit A, B and C signals
- Registres
  - Synchronous on falling_edge(CLK)
    - Guarantee that each pipeline is done in one CLK tick
  - 32 syncronous registers of 16 bits 
  - Simultaneous writing and reading is allowed but writing is done first
- UAL
  - Combinatory mode
  - Allow the ADD, MUL and SUB operation (DIV isn't implemented yet)
- RAM
  - Synchronous on rising_edge(CLK)
  - Adresses between 0x0000 - 0x3FFFF
- VGA
  - Synchronous on rising_edge(CLK)
  - Adresses between 0x4000 - 0x7FFF
- LC logic controller
  - Combinatory mode
  - The Logic Controller goal is to detect a writing action (on register or in memory) and to detect arithmetical operations (in UAL)
- Multiplexer
  - Combinatory mode
  - Choose between a signal given by an entity or the value spread by the previous pipeline depending on the OP code

### Possible improvement
- Operating frequency
  -  Find the critical path in the code and try to optimize the operating frequency
- VGA
  - Should allow printing on VGA screen but isn't working at the moment
- Hazard detection
  - Blurry separation of the case READ x r 0 / READ x r r / READ x 0 r, c-à-d la lecture se fait sur quelle registre
  - As writing and reading is allowed we should be able to reduce waiting time when detecting a data hazard
- Not yet implemented operations: EQU, INF, INFE, SUP, SUPE
  - Possible improvements: in the UAL, do Rj-Rk, then affect Ri given the following rules
    - EQU = Z
    - INF = N
    - INFE = N or Z
    - SUP = not(N or Z)
    - SUPE = not(N)
- Memory access with bus connector 
  - Eventually, we coud use a in-between entity (`cores/conbus1x4.v`) to mul pour multiplex memory access. Depending on the different adresses, we can accessto the RAM, VGA Core Video, Peripherals and Timers.
