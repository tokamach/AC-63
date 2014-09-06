#Astro (I need a new name)

Astro is a game about running a spaceship, powered by a small and weak CPU. Debug and repair programs by toggling in and reading opcodes and data values from the front panel, and write cool
programs on your CRT Terminal. Store spaceship control programs on Punch Cards and fly the ship with said programs. 

##The AC-6

The AC-6 is your companion during your eternal flight aboard whatever vessel takes your fancy. 8-bit Data bus width and a Mermory Mapped IO 16-bit address bus require creative thinking, but
if NASA could send a Big Pointy Space Rocket to the moon and back with 16, I think you can fly your little vessel with 8. It is controlled with a combination of a front panel and a terminal.

###CPU
As previously specified, the CPU has a 16-bit address bus width. This allows addressing any number between 0 and 65535. Data is 8-bit wide. This means 0-255. That is a small number. Make do.
A small but functional instruction set is included, although I am adding as I go along.

|------|------|-----------------|
|Instruction|Hex|Oct|Description|
|NOP|0x00|000|No Operation|
|JMP|0x01|001|Jump to address|
|---|----|---|---------------|
