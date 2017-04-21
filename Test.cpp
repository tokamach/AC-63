#include <assert.h>
#include <iostream>

#include "CPU.h"

int main()
{
    CPU cpu;
    cpu.init();

    //TODO: add makeInstruction utility function

    //JMP
    //jump to address 2
    cpu.setMemory(0, 0b001010000010);
    cpu.setMemory(1, 0b111111111111);
    //jump to address 1
    cpu.setMemory(2, 0b001010000001);

    cpu.cycle();
    //assert(cpu.PC == 2);
    cpu.cycle();
    //assert(cpu.PC == 1);

    //reset CPU
    cpu.init();
    std::cout << "Tests finished succesfully!\n";
    return(0);
}
