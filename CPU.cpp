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
	if(PC > 4095)
		PC = 0;

    opCode = ram[PC];
      
    switch(opCode)
	{
		//NOP: No Operation
		case 0x00:
			//Do nothing
			break;

		//JMP: goto address specified
		case 0x01:
			PC = ram[++PC];
			break;

		//Don't know what to do here
		default:
			//Lalalalalalala
			break;
	  }

     PC++; 
}
