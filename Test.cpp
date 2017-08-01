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
    assert(assemble(mkop("ADD", "", 0, 50)) == 0b101000000000110010);
    assert(assemble(mkop("ADD", "IZ", 0, 30)) == 0b101011000000011110);

    vector<Operation> va = {
	mkop("ADD", "", 0, 50),
	mkop("ADD", "IZ", 0, 30),
	mkop("ADD", "", 0, 50)
    };
    auto vr = assemble(va);

    for (auto v : vr)
    {
	std::cout << std::bitset<18>(v) << std::endl;
    }

    //DAM
    
    
    
    std::cout << "Tests finished succesfully!\n";
    return(0);
}
