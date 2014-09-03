#include "CPU.h"
#include<iostream>

void CPU::init()
{
	X = 0x00;
	Y = 0x00;
	Z = 0x00;
	PC = 0x00;
	P = 0x00;
	for(int i = 0; i < 4096; i++)
	{
		ram[i] = 0x00;
    }
}

void CPU::setMemory(short address, byte data)
{
	
}

byte CPU::getMemory(short address)
{
	
}

int CPU::cycle()
{
	if(PC > 4095)
		PC = 0;

    opCode = ram[PC];
      
      //  Big switch statement BEGINS NOW 
    switch(opCode)
	{
		//JMP: goto address specified
		case 0x01:
			PC = ram[++PC];
			break;	

		default:
//			std::cout << "Opcode:" << opCode;
			break;
	  }
		//Big switch statement ENDS NOW
     PC++; 
}
