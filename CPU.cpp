#include "CPU.h"

#include<iostream>

void CPU::init()
{
	//Bleep bloop
	X = 0x00;
	Y = 0x00;
	Z = 0x00;
	PC = 0x00;
	P = 0x00;
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
	}
	else
	{
		return ram[address];
	}
}

int CPU::cycle()
{
    opCode = getMemory(PC);

	byte mov = 0;
	byte ret = 0;

    switch(opCode)
	{
		//NOP: No Operation
		case 0x00:
			//Do nothing
			break;

		//JMP: goto address specified
		case 0x01:
			PC = getMemory(PC+1) - 1;
			break;

		//MOV: Move A to B, no questions asked
		case 0x02:
			mov = getMemory(PC + 1);
			setMemory(PC + 2, mov);
			PC += 3;
			break;

		//ADD: Add A to B
		case 0x03:
			if((getMemory(PC + 1) + getMemory(PC + 2)) > 255)
			{
				P = 1;
				ret = 255;
				setMemory(PC + 1, ret);
				break;
			}
			ret += getMemory(PC + 1);
			ret += getMemory(PC + 2);
			setMemory(PC + 1, ret);
			PC += 3;
			break;
			
		//Don't know what to do here
		default:
			//Lalalalalalala
			break;
	  }

     PC++; 
}
