# AC-6

As of right now this repo is mostly for the AC-6 emulator I'm working
on, as well as the spec and guide in [manual.md](manual.md). The
CPU was originally 8-bit, although I'm just finishing up with making
it 12. It is heavily inspired by the DEC [PDP-8](https://en.wikipedia.org/wiki/PDP-8),
especially to do with opcode layout and memory paging.

I may add some more CPU designs, such as an obligatory 16-bit and
perhaps a PDP-10 style 36-bit.

CPU Goals include:

* Fully defined AC-6 spec and emulator to match.
* CPU state serializable to JSON, YAML, or perhaps a binary format.
* Independent emulation code, with multiple frontends.
* Reasonably useful IO system, for interfacing with peripherals.
* External assembler and command line AC-6 runner/debugger.

ncurses panel:
![image](demo.png)
