#include "Panel.h"
#include <ncurses.h>
#include <iostream>

int main()
{
	Panel panel;
	CPU cpu;
	cpu.init();
	panel.init(&cpu);

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
		panel.update();
	}
	endwin();
}
