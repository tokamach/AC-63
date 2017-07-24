# AC-63 CPU spec
The AC-63 is an 18-bit CPU designed w
## Registers
Register|Purpose        |Bits|Description
--------|---------------|----|----------
ACC     |Accumumlator   |18  |Stores results of operations.
PC      |Program Counter|18  |Current location in memory of CPU.
SP      |Stack Pointer  |18  |Allows function calls by storing address of the top of the stack
GP      |General Purpose|18  |Four general purpose registers
FLG     |Flags          |6   |Stores flags, for results of operations.

## Word Layout

```
OOOOIZRRXXXXXXXXXX
```

**O**  
The 1st 4 bits of the word are the 4-bit opcode.

**I**  
The 4th bit is the *Addressing Mode* bit. It specifies which addressing mode is
used for this operation.

0. Direct: Use the 10-bits directly
1. Indirect: Use the 10-bits to construct a 18-bit address, which contains the operand

**Z**  
The 5th bit is the *Zero* bit. It specifies how the additional 8 bits needed
to make an 18 bit word are treated. This is essentially the paging bit.

0. Filled with zeros.
1. Uses the 8 high order bits of the PC.

**X**  
The remaining 10 bits are the operand. As per the previous flags these will
be used either directly, or to redirect

## Operation Codes
There are 16 basic instructions.

Operation|Dec|Bin|Description
---------|---|---|------------
AND A    |000|000|Bitwise And A with ACC
ADD A    |001|001|Add A to ACC
DPA A    |002|010|Deposit ACC into A and clear ACC
    A    |003|011|
JMP A    |004|100|Jump to A
JSR A    |005|101|Jump to A+1, store return address in A
PLC      |006|110|Placeholder for now
MIC      |007|111|Use microcode for instruction


# Panel Interface

```

                4.
        | | |START|SINGLE|                        !           !           !                                                                | |
        | | |     |      |                        !           !           !                                                                | |
        | | | / \ | /_\  |                        !           !           !                                                                | |
        | | | \|/ | \ /  |                        !           !1.         !                                                                | |
        | | |  ^  |      |  / \   / \   / \   / \ ! / \   / \ ! / \   / \ ! / \   / \   / \   / \   / \   / \   / \   / \   / \   / \      | |
        | | |STOP |STEP  |  \ /   \ /   \ /   \ / ! \ /   \ / ! \ /   \ / ! \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /      | |
        | |                                       !           !           !                                                                | |
        | |                                       !           !           !                                                                | |
        | |                                       !           !           !                                                                | |
        | |                                       !           !2.         !                                                                | |
        | |                 / \   / \   / \   / \ ! / \   / \ ! / \   / \ ! / \   / \   / \   / \   / \   / \   / \   / \   / \   / \      | |
        | |                 \ /   \ /   \ /   \ / ! \ /   \ / ! \ /   \ / ! \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /   \ /      | |
        | |                                       !           !           !                                                                | |
        | |                                       !           !           !                                                                | |
        | |                                       !           !           !                                                                | |
        | |                                       !           !3.         !                                                                | |
        | |                 / \   / \   / \   / \ ! / \   / \ ! / \   / \ ! / \   / \   / \   / \   / \   / \   / \   / \   / \   / \      | |
        | |                 \|/   \|/   \|/   \|/ ! \|/   \|/ ! \|/   \|/ ! \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/   \|/      | |
        | |                  ^     ^     ^     ^  !  ^     ^  !  ^     ^  !  ^     ^     ^     ^     ^     ^     ^     ^     ^     ^       | |
        | |                                       !           !           !                                                                | |
        | |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | |++++Astro Computing Inc. AC-63++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++| |
        | \________________________________________________________________________________________________________________________________/ |
        \____________________________________________________________________________________________________________________________________/


```

1. Address Lights
2. Data Lights
3. Main Switches
4. Control Switches

Notice the two vertical lines, these visually separate parts of the memory word into Instruction, Zero and Indirect bits, and Data segments respectively.

