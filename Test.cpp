#include <assert.h>
#include <map>
#include <utility>
#include <string>
#include <iostream>

#include "CPU.h"

using std::string;
using std::map;
using std::pair;

//
// This file contains tests for all instructions
//

//fucking love modern C++
word makeInstruction(string op, bool indirect, bool zero, byte reg, word arg)
{
    word result = 0;
    map<string, byte> opmap = {
	{"DAM",  0},
	{"LDR",  1},
	{"DPR",  2},
	{"JMP",  3},
	{"JEZ",  4},
	{"JNZ",  5},
	{"SHL",  6},
	{"SHR",  7},
	{"AND",  8},
	{"OR" ,  9},
	{"ADD", 10},
	{"SUB", 11},
	{"POP", 12},
	{"PSH", 13}};

    map<pair<bool, bool>, byte> indirect_page_map = {
	{{false, false}, 0},
	{{false,  true}, 1},
	{{true , false}, 2},
	{{true ,  true}, 3}};

    pair<bool, bool> indir_bits = std::make_pair(indirect, zero);


    result |= (opmap[op] << 14);
    result |= (indirect_page_map[indir_bits] << 12);
    result |= (reg << 10);
    result |= arg;

    return result;
}

int main()
{
    CPU cpu;
    cpu.init();

    //test make instruction
    assert(makeInstruction("ADD", false, false, 0, 50) == 0b101000000000110010);
    assert(makeInstruction("ADD", false, false, 0, 30) == 0b101000000000011110);

    //DAM
    
    
    std::cout << "Tests finished succesfully!\n";
    return(0);
}
