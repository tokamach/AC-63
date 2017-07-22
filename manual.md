# AC-6 CPU spec
## Registers
Register|Purpose        |Bits|Description
--------|---------------|----|----------
ACC     |Accumumlator   |12  |Stores results of operations.
PC      |Program Counter|12  |Current location in memory of CPU.
SP      |Stack Pointer  |12  |Allows function calls by storing address of the top of the stack
FLG     |Flags          |7   |Stores flags, for results of operations.

## Word Layout

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

## Operation Codes
There are 7 basic instructions.

Operation|Dec|Bin|Description
---------|---|---|------------
AND A    |000|000|Bitwise And A with ACC
JMP A    |001|001|Unconditionally jump to location 
DPA A    |002|010|Deposit ACC into A and clear ACC
ADD A    |003|011|Add A to ACC
JMP A    |004|100|Jump to A
JEZ A    |005|101|Jump to A+1 if next word is Zero, store return address in A, otherwise increment PC by 2
PLC      |006|110|Placeholder for now
MIC      |007|111|Use microcode for instruction


# Panel Interface

```

                4.
        | | |START|SINGLE|     |                                          !           !                                                    | |
        | | |     |      |     |                                          !           !                                                    | |
        | | | / \ | /_\  |     |                                          !           !                                                    | |
        | | | \|/ | \ /  |     |                               1.         !           !                                                    | |
        | | |  ^  |      |     |                                / \   / \ ! / \   / \ ! / \   / \   / \   / \   / \   / \   / \   / \      | |
        | | |STOP |STEP  |     |                                \ /   \ / ! \ /   \ / ! \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /      | |
        | |                                                               !           !                                                    | |
        | |                                                               !           !                                                    | |
        | |                                                               !           !                                                    | |
        | |                                                    2.         !           !                                                    | |
        | |                                                     / \   / \ ! / \   / \ ! / \   / \   / \   / \   / \   / \   / \   / \      | |
        | |                                                     \ /   \ / ! \ /   \ / ! \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /      | |
        | |                                                               !           !                                                    | |
        | |                                                               !           !                                                    | |
        | |                                                               !           !                                                    | |
        | |                                                    3.         !           !                                                    | |
        | |                                                     / \   / \ ! / \   / \ ! / \   / \   / \   / \   / \   / \   / \   / \      | |
        | |                                                     \|/   \|/ ! \|/   \|/ ! \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/      | |
        | |                                                      ^     ^  !  ^     ^  !  ^     ^     ^     ^     ^     ^     ^     ^       | |
        | |                                                               !           !                                                    | |
        | |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | |++++Astro Computing Inc. AC-6+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | \________________________________________________________________________________________________________________________________/ |
        \____________________________________________________________________________________________________________________________________/


```

1. Address Lights
2. Data Lights
3. Main Switches
4. Control Switches

Notice the two vertical lines, these visually separate parts of the memory word into Instruction, Zero and Indirect bits, and Data segments respectively.

