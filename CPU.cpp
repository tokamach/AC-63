#include "CPU.h"

#include<iostream>

void CPU::init()
{
	//Bleep bloop
	ACC = 0x00;
	X   = 0x00;
	Y   = 0x00;
	Z   = 0x00;
	PC  = 0x00;
	for(int i = 0; i < 4096; i++)
	{
		//It gets weird if you don't
		ram[i] = 0x00;
    }
}

void CPU::setMemory(short address, byte data)
{
	if(address > 4095)
	{
		//Logic for Memory mapped I/O here
	}
	else
	{
		ram[address] = data;
	}
}

byte CPU::getMemory(short address)
{
	if(address > 4095)
	{
		//Logic for MMIO here	

        return 0x00; // dummy logic best logic
	}
	else
	{
		return ram[address];
	}
}

void CPU::cycle()
{
    opCode = getMemory(PC);

	byte ret = 0;

    switch(opCode)
	{
		//NOP: No Operation
		case 0x00:
			//Do nothing
            PC += 2;
			break;

		//JMP: goto address specified
		case 0x01:
			PC = getMemory(PC+1);
			break;

		//LDA: load A into ACC
		case 0x02:
			ACC = getMemory(PC + 1);
			PC += 2;
			break;

		//ADD: Add A to ACC
		case 0x03:
            ACC += getMemory(PC + 1);
            PC += 2:
			break;

        //SUB: 
        case 0x04:
            ACC -= getMemory(PC + 1);
            PC += 2;
            break;
			
		//Don't know what to do here
		default:
			//Lalalalalalala
			break;
	  }

//     PC++; 
}
