#include <assert.h>
#include <iostream>

#include "CPU.h"

int main()
{
    CPU cpu;
    cpu.init();

    //TODO: add makeInstruction utility function

    ///JMP
    //JMP 2
    cpu.setMemory(0, 0b001010000010);
    cpu.setMemory(1, 0b111111111111);
    //JMP 1
    cpu.setMemory(2, 0b001010000001);

    cpu.cycle();
    assert(cpu.PC == 2);
    cpu.cycle();
    assert(cpu.PC == 1);

    //reset CPU
    cpu.init();

    ///TAD
    cpu.setMemory(127, 10);
    //TAD I X 127
    cpu.setMemory(0, 0b011111111111);
    cpu.cycle();

    assert(cpu.ACC == 10);

    cpu.init();

    ///DPA
    cpu.setMemory(127, 50);
    //TAD I Z 127
    cpu.setMemory(0, 0b011111111111);
    //DPA 10
    cpu.setMemory(1, 0b010000001010);

    cpu.cycle();
    cpu.cycle();
    assert(cpu.getMemory(10) == 50);

    cpu.init();

    ///JSR
    //JMP 10
    cpu.setMemory(0, 0b001000001010);
    cpu.setMemory(10, 0b100001111111);

    cpu.cycle();
    cpu.cycle();

    assert(cpu.Z == 10);
    
    std::cout << "Tests finished succesfully!\n";
    return(0);
}
