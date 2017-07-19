#include "CPU.h"

#include<iostream>

const short OPCODE_MASK  = 0b111000000000;
const short INDIR_MASK   = 0b000100000000;
const short ZERO_MASK    = 0b000010000000;
const short OPERAND_MASK = 0b000001111111;

const short TWELVE_BIT_MASK  = 0b111111111111;
const short PC_HIGH_BIT_MASK = 0b111000000000;

void CPU::init()
{
    //Bleep bloop
    ACC = 0x000;
    X   = 0x000;
    Y   = 0x000;
    Z   = 0x000;
    I   = 0x00;
    J   = 0x00;
    K   = 0x00;
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
	puts("MMIO Write Call");
    }
    else
    {
	ram[address] = data;
    }
}

short CPU::getMemory(short address)
{
    if(address > 4095)
    {
	//Logic for MMIO here	

	puts("MMIO Read Call");
        return 0x00; // dummy logic best logic
    }
    else
    {
	return ram[address];
    }
}

void CPU::printCPU()
{
    std::cout << "=CPU State=\n"
	      << "PC is: " << std::bitset<12>(PC) << "\n"
	      << "ACC is: " << std::bitset<12>(ACC) << "\n"
	      << "curword is: " << std::bitset<12>(getMemory(PC)) << "\n"
	//  << "opCode is: " << std::bitset<3>(opCode) << "\n"
	//  << "indirect bit is: " << indirect_bit << "\n"
	//  << "zero bit is: " << zero_bit << "\n"
	      << std::endl;
}

void CPU::cycle()
{
    short curWord = getMemory(PC);

    byte opCode       = (OPCODE_MASK  & curWord) >> 9;
    bool indirect_bit = (INDIR_MASK   & curWord) >> 8;
    bool zero_bit     = (ZERO_MASK    & curWord) >> 7;
    short arg         = (OPERAND_MASK & curWord);

    if(indirect_bit)
    {
	if(zero_bit)
	{
	    //create new address from arg and zeroes for the 12 extra bits
	    arg = getMemory(arg);
	}
	else
	{
	    //create new address from arg and 5 higher order bits of PC
	    arg = getMemory((PC_HIGH_BIT_MASK & PC) + arg);
	}
    }

    switch(opCode)
    {
	//AND: bitwise and arg with ACC
    case 0:
	ACC &= arg;
	PC += 1;
	break;

	//JMP: unconditional jump to arg
    case 1:
	PC = arg;
	break;

	//DPA: deposit ACC into arg and clear ACC
    case 2:
	setMemory(arg, ACC);
	ACC = 0;
	PC += 1;
	break;

	//TAD: two's complement add ARG into ACC
    case 3:
	ACC += arg;
	PC += 1;
	break;

	//JSR: jump to subroutine arg, and deposit return address in Z
    case 4:
	Z  = PC;
	PC = arg;
	break;
	
	//Don't know what to do here
    default:
	//Lalalalalalala
	break;
    }


    //Don't overflow past 12 bits
    if(PC > 4095)
    {
        PC = 0x00;
    }
}
