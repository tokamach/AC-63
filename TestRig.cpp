#include "Terminal.h"
#include <ncurses.h>
#include <iostream>

int main()
{
	Terminal terminal;
	CPU cpu;
	cpu.init();
	terminal.init(&cpu);

	initscr();
    cbreak();
    noecho();
    intrflush(stdscr, false);
    keypad(stdscr, true);

	while(true)
	{
		terminal.update();
	}
	endwin();
}
