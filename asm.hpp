#include <vector>
#include <map>
#include <string>
#include "CPU.h"

using std::vector;
using std::string;
using std::map;

struct Operation
{
    string op;
    string iz;
    byte reg;
    word arg;
};

Operation mkop(string _op, string _iz, byte _reg, word _arg)
{
    Operation ret;
    ret.op = _op;
    ret.iz = _iz;
    ret.reg = _reg;
    ret.arg = _arg;
    return ret;
}

word assemble(Operation op_arg)
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
    
    map<string, byte> indirect_page_map = {
	{""  , 0},
	{"Z" , 1},
	{"I" , 2},
	{"IZ", 3}};
    
    result |= (opmap[op_arg.op] << 14);
    result |= (indirect_page_map[op_arg.iz] << 12);
    result |= (op_arg.reg << 10);
    result |= op_arg.arg;
    
    return result;
}

vector<word> assemble(vector<Operation> op_arg)
{
    vector<word> ret;
    for(auto &elem : op_arg)
    {
	ret.push_back(assemble(elem));
    }

    return ret;
}

void loadProgIntoMem(vector<word> prog, CPU *cpu)
{
    int iter = 0;
    for(auto w : prog)
    {
	cpu->setMemory(iter, w);
	iter++;
    }
}
