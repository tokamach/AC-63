#include <stdint.h>

#ifndef __CPU_H__
#define __CPU_H__

using byte = uint8_t;
//#define byte uint8_t

class CPU
{
 public:
  void init();
  int cycle();
  void toggleRun();
  byte opCode;
  byte ram[4096];
  byte A;
  byte X;
  byte Y;
  byte SP;
  short PC;
  byte P;

 private:
  bool runCpu;
};

#endif
