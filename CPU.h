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

		byte opCode;
		byte ram[4096];
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
