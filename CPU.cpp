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

    reg[0] = 0x00000;
    reg[1] = 0x00000;
    reg[2] = 0x00000;

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

void CPU::dumpMem(int start, int end)
{
    std::cout << "=== CPU Memory Dump ===" << std::endl;
    for(int i = start; i < end; i++)
    {
	std::cout << std::bitset<18>(getMemory(i)) << "\n";
    }
}

void CPU::printCPU()
{
    std::cout << "=CPU State=\n"
	      << "PC: " << std::bitset<18>(PC) << "\n"
	      << "ACC: " << std::bitset<18>(ACC) << "\n"
	      << "curword: " << std::bitset<18>(getMemory(PC)) << "\n"
	      << "GP0: " << std::bitset<18>(reg[0]) << "\n"
	      << "GP1: " << std::bitset<18>(reg[1]) << "\n"
	      << "GP2: " << std::bitset<18>(reg[2]) << "\n"
	      << std::endl;
}

void CPU::cycle()
{
    word curWord = getMemory(PC);

    byte opCode       = (OPCODE_MASK  & curWord) >> 15;
    bool indirect_bit = (INDIR_MASK   & curWord) >> 14;
    bool zero_bit     = (ZERO_MASK    & curWord) >> 13;
    byte regsel       = (REG_MASK     & curWord) >> 11;
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
    case 0: //DAM R A
	setMemory(arg, ACC);
	ACC = 0;
	PC++;
	break;

    case 1: //LDR R A
	reg[regsel-1] = arg;
	PC++;
	break;

    case 2: //DPR R A
	setMemory(arg, reg[regsel-1]);
	PC++;
	break;

    case 3: //JMP R A
	if(regsel != 0)
	    reg[regsel] = PC;

	PC = arg;
	break;

    case 4: //JEZ R A
	if(ACC == 0)
	{
	    if(regsel != 0)
		reg[regsel] = PC;

	    PC = arg;
	}
	else
	    PC++;
	break;

    case 5: //JNZ R A
	if(ACC != 0)
	{
	    if(regsel != 0)
		reg[regsel] = PC;

	    PC = arg;
	}
	else
	    PC++;
	break;

    case 6: //SHL A
	ACC = arg << 1;
	PC++;
	break;

    case 7: //SHR A
	ACC = arg >> 1;
	PC++;
	break;

    case 8: //AND A
	ACC &= arg;
	PC++;
	break;

    case 9: //OR A
	ACC |= arg;
	PC++;
	break;

    case 10: //ADD R A
	ACC += arg;

	if(regsel != 0)
	    ACC += reg[regsel];

	PC++;
	break;

    case 11: //SUB R A
	ACC -= arg;

	if(regsel != 0)
	    ACC -= reg[regsel];

	PC++;
	break;

    case 12: //POP A
	setMemory(arg, getMemory(SP));
	SP--;
	PC++;
	break;

    case 13: //PSH A
	setMemory(getMemory(SP), arg);
	SP++;
	PC++;
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
