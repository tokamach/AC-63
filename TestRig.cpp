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
	timeout(1);
    cbreak();
    noecho();
    intrflush(stdscr, false);
    keypad(stdscr, true);

	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED , COLOR_BLACK);

	while(true)
	{
		terminal.update();
	}
	endwin();
}
