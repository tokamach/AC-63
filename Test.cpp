#include <assert.h>
#include <vector>
#include <string>
#include <iostream>

#include "CPU.h"
#include "asm.hpp"

using std::vector;

//
// This file contains tests for all instructions
//

int main()
{
    CPU cpu;
    cpu.init();

    //test assembler
    assert(assemble(mkop("ADD", "", 0, 50))   == 0b101100000000110010);
    assert(assemble(mkop("ADD", "IZ", 0, 30)) == 0b101111000000011110);

    vector<Operation> va = {
	mkop("ADD", "", 0, 50),
	mkop("ADD", "", 0, 30),
	mkop("DAM", "", 0, 9),
	mkop("LDR", "", 1, 9)
    };
    auto vr = assemble(va);

    loadProgIntoMem(vr, &cpu);
    cpu.cycle();
    cpu.cycle();
    cpu.cycle();
    cpu.cycle();
    cpu.cycle();
    cpu.cycle();
    cpu.printCPU();
    cpu.dumpMem(0, 10);
    
    std::cout << "Tests finished succesfully!\n";
    return(0);
}
