#include "Terminal.h"
#include <ncurses.h>
#include <iostream>

int main()
{
	Terminal terminal;

	initscr();
    cbreak();
    noecho();
    intrflush(stdscr, false);
    keypad(stdscr, true);

	while(true)
	{
		terminal.update();
		//terminal.updateFromInput();
		//terminal.drawPanel(10, 4);
		//refresh();
		
		//if(terminal.getStartSwitch())
		//	cpu.cycle();

			
	}
	endwin();
}
