#include "CPU.h"

#include <iostream>

const word OPCODE_MASK  = 0b111100000000000000;
const word INDIR_MASK   = 0b000010000000000000;
const word ZERO_MASK    = 0b000001000000000000;
const word REG_MASK     = 0b000000110000000000;
const word OPERAND_MASK = 0b000000001111111111;

const word EIGHTEEN_BIT_MASK = 0b111111111111111111;
const word PC_HIGH_BIT_MASK  = 0b111100000000000000;

//const word MAX_VAL = 262143; // largest 18-bit number

void CPU::init()
{
    //Bleep bloop
    ACC = 0x00000;
    PC  = 0x00000;
    SP  = 0x3FFFF;
    FLG = 0x00;

    REG[0] = 0x00000;
    REG[1] = 0x00000;
    REG[2] = 0x00000;
    REG[3] = 0x00000;

    for(int i = 0; i < MAX_VAL; i++)
    {
	//It gets weird if you don't
	ram[i] = 0x00000;
    }
}

void CPU::setMemory(word address, word data)
{
    if(address > MAX_VAL)
    {
	//Logic for Memory mapped I/O here
	printf("MMIO Write Call");
    }
    else
    {
	ram[address] = data;
    }
}

word CPU::getMemory(word address)
{
    if(address > MAX_VAL)
    {
	//Logic for MMIO here	

	printf("MMIO Read Call at: %i", address);
        return 0x00000; // dummy logic best logic
    }
    else
    {
	return ram[address];
    }
}

void CPU::printCPU()
{
    std::cout << "=CPU State=\n"
	      << "PC is: " << std::bitset<18>(PC) << "\n"
	      << "ACC is: " << std::bitset<18>(ACC) << "\n"
	      << "curword is: " << std::bitset<18>(getMemory(PC)) << "\n"
	//  << "opCode is: " << std::bitset<3>(opCode) << "\n"
	//  << "indirect bit is: " << indirect_bit << "\n"
	//  << "zero bit is: " << zero_bit << "\n"
	      << std::endl;
}

void CPU::cycle()
{
    word curWord = getMemory(PC);

    byte opCode       = (OPCODE_MASK  & curWord) >> 15;
    bool indirect_bit = (INDIR_MASK   & curWord) >> 14;
    bool zero_bit     = (ZERO_MASK    & curWord) >> 13;
    byte reg_sel      = (REG_MASK     & curWord) >> 11;
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

	//ADD: add ARG into ACC
    case 3:
	ACC += arg;
	PC += 1;
	break;

	//JMP: jump to arg
/*  case 4:
	PC = arg;
	break; */

    case 5:
	//JEZ: jump to arg+1 if PC+1 == 0, store return in arg
	if(getMemory(PC+1) == 0)
	{
	    setMemory(arg, PC);
	    PC = arg + 1;
	} else {
	    PC += 2;
	}
	break;
	
	//Don't know what to do here
    default:
	//Lalalalalalala
	break;
    }


    //Don't overflow past 18 bits
    if(PC >= MAX_VAL)
    {
        PC = 0x00000;
    }
}
