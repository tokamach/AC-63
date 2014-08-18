#include "CPU.h"
#include<iostream>

void CPU::init()
{
  A = 0x00;
  X = 0x00;
  Y = 0x00;
  SP = 0x00;
  PC = 0x00;
  P = 0x00;
  for(int i = 0; i < 4096; i++)
    {
      ram[i] = 0x00;
    }
}

int CPU::cycle()
{

    opCode = ram[PC];
      
      //  Big switch statement BEGINS NOW 
      /*switch(opCode)
	  {
		//ADC: add memory to A with carry
		case 0x69:
		 //todo Implement ADC
		break;
		
		//JMP: goto address specified
		case 0x4c:
			PC = ram[PC+1];
			break;

		default:
		*/std::cout << "Opcode:" << opCode;
		//break;
	  //}
		//Big switch statement ENDS NOW
     PC++; 
}

void CPU::toggleRun()
{
	runCpu = !runCpu;
}
