```
    _____   _____  _____  _____  ______         
   //--//  /  __/ /_  _/ /    / / __  /
  //__//  / /__    / /  / ___/ / / / /
 //  //  /__  /   / /  / / \  / /_/ /
//  //  /____/   /_/  /_/ \_\/_____/ 

```


Congratulations on the purchase of your brand new Astro Computing Inc. AC-6 Vessel Control System!

This Manual will explain all about your new purchase, and its operational procedures. See the 
section reference for specific information. Should you  encounter any issues with your Astro 
Computing Inc. AC-6 Vessel Control System please see an Astro Computing Inc. Safety Representative 
immediately.

## Introduction
Astro Computing Inc. has manufactured computers since the first Apollo Guidance Computer, 
and has dominated the market with their Fantastic Customer Service Policy and Exceptional Customer 
Safety Agreement. Now, they produce Outstanding Vessel Guidance, Control, Management, Life Support and 
Cafeteria control systems. 

## CPU
The AC-6 CPU is the heart and soul of your spaceship control system. It features a 16-bit address bus,
meaning a whole 65536 individual addresses are accessible! The Data bus is a swift and clean 8-bits
wide, ideal for mission critical calculations to be made without delay.

### Registers
Register|Purpose        |Bits|Description
\--------|---------------|----|----------
ACC     |Accumulator   |16  |Stores results of operations.
PC      |Program Counter|16  |Current location in memory of CPU.
SP      |Stack Pointer  |16  |Allows function calls by storing address of the top of the stack
X, Y, Z |General        |8   |General purpose registers, useful for anything!
FLG     |Flags          |7   |Stores flags, for extending operations.


#### Flag Register Composition
* indirect flag
* X, Y, Z load flag

### Operation Codes

Operation|Hex |Oct|Description
\---------|----|---|------------
NOP      |0x00|000|No-Operation
JMP A    |0x01|001|Unconditionally jump to location 
LDA A    |0x02|002|Load address into ACC
ADD A    |0x03|003|Add A to ACC
SUB A    |0x04|004|Subtract A from ACC
MUL A    |0x05|005|Multiply ACC by A
	     |0x06|006|
JSR A    |0x07|007|Jump to subroutine A
RTS      |0x08|010|Return from subroutine to address 
BNE A    |0x09|011|Jump to A if P = 0
BEQ A    |0x0A|012|Jump to A if P = 1


## Interface

The Astro Computing Inc. AC-6 Vessel Control System is controlled at it's heart by an Astro
Computing Inc. TeleTerminal product. However, you may only have one of these units aboard your
ship, if so then you may find yourself spending a lot of time inspecting Astro Computing Inc. CPU and RAM
Inspection and Modification Panels, Abbreviated CRIMP. Here is a diagram of a CRIMP:

```

                4.
        | | |START|SINGLE|     |                                                      !                                                    | |
        | | |     |      |     |                                                      !                                                    | |
        | | | / \ | /_\  |     |                                                      !                                                    | |
        | | | \|/ | \ /  |     |                                                      !3.                                                  | |
        | | |  ^  |      |     |                                                      ! /#\   /#\   / \   / \   / \   / \   / \   /#\      | |
        | | |STOP |STEP  |     |                                                      ! \#/   \#/   \ /   \ /   \ /   \ /   \ /   \#/      | |
        | |                                                                           !                                                    | |
        | |                                                                           !                                                    | |
        | |                                                                           !                                                    | |
        | |                            2.                                             !                                                    | |
        | |                             /#\   /#\   / \   / \   / \   / \   / \   /#\ ! /#\   /#\   / \   / \   / \   / \   / \   / \      | |
        | |                             \#/   \#/   \ /   \ /   \ /   \ /   \ /   \#/ ! \#/   \#/   \ /   \ /   \ /   \ /   \ /   \ /      | |
        | |                                                                           !                                                    | |
        | |                                                                           !                                                    | |
        | |                                                                           !                                                    | |
        | |                            1.                                             !                                                    | |
        | |                             / \   / \   / \   / \   / \   / \   / \   / \ ! / \   / \   / \   / \   / \   / \   / \   / \      | |
        | |                             \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/ ! \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/      | |
        | |                              ^     ^     ^     ^     ^     ^     ^     ^  !  ^     ^     ^     ^     ^     ^     ^     ^       | |
        | |                                                                           !                                                    | |
        | |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | |++++Astro Computing Inc. AC-6+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | \________________________________________________________________________________________________________________________________/ |
        \____________________________________________________________________________________________________________________________________/


```

1. Main Switches
2. Address Lights
3. Data Lights
4. Control Switches

While at first the panel may seem overwhelming, it will soon become second nature to use. 

As stated in the legend, the bottom row are address/data control switches. These are your main 
interface with the CPU and RAM. A line seperates them, showing you the Most Signifcant Byte on the left and the 
Least Signifigant Byte on the right. 
