#include <stdint.h>

#ifndef __CPU_H__
#define __CPU_H__

using byte = uint8_t;

class CPU
{
 public:
    void init();
    void cycle();
    void setMemory(short address, byte data);
    byte getMemory(short address);

    short ram[4096]; //12 bit
    short ACC;
    byte X;
    byte Y;
    byte Z;
    short PC;
    short SP;
    byte FLG;

 private:
    bool runCpu;
};

#endif
