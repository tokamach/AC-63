#pragma once

#include <stdint.h>

using byte = uint8_t;
using word = uint32_t;

const word MAX_VAL = 262143; // largest 18-bit number

class CPU
{
 public:
    void  init();
    void  cycle();
    void  setMemory(word address, word data);
    word getMemory(word address);

    void printCPU();

    word ram[MAX_VAL];
    word ACC;
    word  PC;
    word  SP;

    word reg[3]; //3 general purpose registers

 private:
    bool runCpu;
};
