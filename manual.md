```
    _____	_____  _____  _____  ______			
   //--//  /  __/ /_  _/ /    / / __  /
  //__//  / /__    / /  / ___/ / / / /
 //  //  /__  /   / /  / / \  / /_/ /
//  //	/____/   /_/  /_/ \_\/_____/ 

```


Congratulations on the purchase of your brand new Astro Computing Inc. AC-6 Vessel Control System!

This Manual will explain all about your new purchase, and its operational procedures. See the 
section reference for specific information. Should you  encounter any issues with your Astro 
Computing Inc. AC-6 Vessel Control System please see an Astro Computing Inc. Safety Representative 
immediately.

##Introduction
Astro Computing Inc. has manufactured computers since the first Apollo Guidance Computer, 
and has dominated the market with their Fantastic Customer Service Policy and Exceptional Customer 
Safety Agreement. Now, they produce Outstanding Vessel Guidance, Control, Managment, Life Support and 
Cafeteria control systems. 

##CPU
The AC-6 CPU is the heart and soul of your spaceship control system. It features a 16-bit address bus,
meaning a whole 65536 individual addresses are accessible! The Data bus is a swift and clean 8-bits
wide, ideal for mission critical calculations to be made without delay.

###Registers
Register|Purpose        |Bits|Description
--------|---------------|----|----------
ACC     |Accumumlator   |16  |Stores results of operations.
PC      |Program Counter|16  |Current location in memory of CPU.
SP      |Stack Pointer  |16  |Allows function calls by storing address of the top of the stack
X, Y, Z |General        |8   |General purpose registers, useful for anything!
FLG     |Flags          |7   |Stores flags, for extending operations.


####Flag Regiser Composition
The flag register is layed out as separate binary sections which alter the function of the CPU.

#####Indirect Address Flag
The first bit of the flag register controls how addressing works.

|0|operate directly on A|
|1|use address pointed to by A|

#####16-bit num mode
The second bit controls whether memory is accessed in 8 or 16 bit mode.

|0|use regular 8 bit|
|1|compound PC+1 and PC+2 into a 16-bit number|

#####Register select flags
The 3rd and 4th bits are the register select flags. They choose which register the LDA, ADD and SUB
intructions operate on.

|00|ACC|
|01|X  |
|10|Y  |
|11|Z  |


###Operation Codes

Operation|Hex |Oct|Description
---------|----|---|------------
NOP	     |0x00|000|No-Operation
JMP A    |0x01|001|Unconditionally jump to location 
LDA A    |0x02|002|Load address into ACC
ADD A    |0x03|003|Add A to ACC
SUB A    |0x04|004|Subtract A from ACC
         |0x05|005|
         |0x06|006|
JSR A    |0x07|007|Jump to subroutine A
RTS      |0x08|010|Return from subroutine to address 
BNE A    |0x09|011|Jump to A if P = 0
BEQ A    |0x0A|012|Jump to A if P = 1


##Interface

The Astro Computing Inc. AC-6 Vessel Control System is controlled at it's heart by an Astro
Computing Inc. TeleTerminal product. However, you may only have one of these units aboard your
ship, if so then you may find yourself spending a lot of time inspecting Astro Computing Inc. CPU and RAM
Inspection and Modifification Panels, Abbreviated CRIMP. Here is a diagram of a CRIMP:

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

