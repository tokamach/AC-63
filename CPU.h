#pragma once

#include <stdint.h>

using byte = uint8_t;

class CPU
{
 public:
    void init();
    void cycle();
    void setMemory(short address, short data);
    byte getMemory(short address);

    short ram[4096]; //12 bit
    short ACC;
    short X;
    short Y;
    short Z;
    byte I;
    byte J;
    byte K;
    short PC;
    short SP;
    byte FLG;

 private:
    bool runCpu;
};
