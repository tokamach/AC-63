#include <assert.h>
#include <string>
#include <iostream>

#include "CPU.h"
#include "asm.hpp"

//
// This file contains tests for all instructions
//

int main()
{
    CPU cpu;
    cpu.init();

    //test make instruction
    assert(assemble(mkop("ADD", "", 0, 50)) == 0b101000000000110010);
    assert(assemble(mkop("ADD", "IZ", 0, 30)) == 0b101011000000011110);

    //DAM
    
    
    
    std::cout << "Tests finished succesfully!\n";
    return(0);
}
