#include "CPU.h"

#include<iostream>

const short OPCODE_MASK  = 0b111000000000;
const short INDIR_MASK   = 0b000100000000;
const short ZERO_MASK    = 0b000010000000;
const short OPERAND_MASK = 0b000001111111;

void CPU::init()
{
    //Bleep bloop
    ACC = 0x000;
    X   = 0x000;
    Y   = 0x000;
    Z   = 0x000;
    PC  = 0x000;
    SP  = 0xf00;
    FLG = 0x000;
    for(int i = 0; i < 4095; i++)
    {
	//It gets weird if you don't
	ram[i] = 0x000;
    }
}

void CPU::setMemory(short address, short data)
{
    if(address > 4095)
    {
	//Logic for Memory mapped I/O here
    }
    else
    {
	if(data > 4095)
	{
	    ram[address] = data;
	}
	else
	{
	    ram[address] = data && (0b1111000000000000)
	}
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

    

    switch(opCode)
    {
	//AND: bitwise and arg with ACC
    case 0:
	ACC &= 
	break;
	
	//Don't know what to do here
    default:
	//Lalalalalalala
	break;
	  }

    //Don't overflow past 12 bits pls
    if(PC > 4095)
    {
        PC = 0x00;
    }
}
