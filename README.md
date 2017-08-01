# AC-63

This repo is for a custom CPU design called the AC-63, it's emulator, as well as the spec in [manual.org](manual.org). The CPU was originally 8-bit, then 12-bit, and finally changed to 18-bit to avoid copying the PDP-8 too much.

CPU Goals include:

* Fully defined AC-63 spec and emulator to match.
* CPU state serializable to JSON, YAML, or perhaps a binary format.
* Independent emulation code, with multiple frontends.
* Reasonably useful IO system, for interfacing with peripherals.
* External assembler and command line AC-63 runner/debugger.

ncurses panel:
![image](demo.png)
