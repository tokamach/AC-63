```
    _____   _____  _____  _____  ______
   //  //  /  __/ /_  _/ /    / / __  /
  //--//  / /__    / /  / ___/ / / / /
 //  //  /__  /   / /  / / \  / /_/ /
//  //  /____/   /_/  /_/ \_\/_____/ 

    _____   _____           _____
   //  //  / ___/          /  __/
  //--//  / /    ______   / /__
 //  //  / /__  /_____/  /    /
//  //  /____/          /____/

```
Copyright Astro Computing Inc. 1971
Congratulations on the purchase of your brand new Astro Computing Inc. AC-6 Vessel Control System!

This Manual will explain all about your new purchase, and its operational procedures. See the section reference for specific information. Should you encounter any issues with your Astro Computing Inc. AC-6 Vessel Control System please see an Astro Computing Inc. Safety Representative immediately.

## CPU
The AC-6 CPU is the heart and soul of your spaceship control system. It is a 12-bit wordlength computer. The largest representable number in 12 bits is 4095, 

### Registers
Register|Purpose        |Bits|Description
--------|---------------|----|----------
ACC     |Accumumlator   |12  |Stores results of operations.
PC      |Program Counter|12  |Current location in memory of CPU.
SP      |Stack Pointer  |12  |Allows function calls by storing address of the top of the stack
X, Y, Z |General        |12  |Big General purpose registers.
I, J, K |General        |8   |Small General purpose registers.
FLG     |Flags          |7   |Stores flags, for results of operations.

### Word Layout
The 12-bit word of the AC-6 is structured to allow more complex instructions to be performed.

```
OOOIZXXXXXXX
```

**O**  
The 1st three bits of the word are the 3-bit opcode.

**I**  
The 4th bit is the *Addressing Mode* bit. It specifies which addressing mode is
used for this operation.

0. Direct: Use the 7-bits directly
1. Indirect: Use the 7-bits to construct a 12-bit address, which contains the operand

**Z**  
The 5th bit is the *Zero* bit. It specifies how the additional 5 bits needed
to make a 12 bit word are treated.

0. Filled with zeros.
1. Uses the 5 high order bits of the PC.

**X**  
The remaining 7 bits are the operand. As per the previous flags these will
be used either directly, or to redirect

### Operation Codes
There are 7 basic instructions.

Operation|Dec|Bin|Description
---------|---|---|------------
AND A    |000|000|Bitwise And A with ACC
JMP A    |001|001|Unconditionally jump to location 
DPA A    |002|010|Deposit accumulator into A and clear
TAD A    |003|011|Two's complement add A to ACC
JSR A    |004|100|Jump to subroutine A, store return address in Z
         |005|101|
         |006|110|
MIC      |007|111|Use microcode for instruction


## Interface

The Astro Computing Inc. AC-6 Vessel Control System is controlled at it's heart by an Astro Computing Inc. TeleTerminal product. However, you may only have one of these units aboard your ship, if so then you may find yourself spending a lot of time inspecting Astro Computing Inc. CPU and RAM Inspection and Modifification Panels, Abbreviated CRIMP. Here is a diagram of a CRIMP:

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

As stated in the legend, the bottom row are address/data control switches. These are your main interface with the CPU and RAM. A line seperates them, showing you the Most Signifcant Byte on the left and the Least Signifigant Byte on the right. 

