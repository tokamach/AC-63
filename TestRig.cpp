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
    use_default_colors();
    
    init_pair(1, COLOR_WHITE, -1);
    init_pair(2, COLOR_RED ,  -1);
    init_pair(3, COLOR_CYAN,  -1);
    
    while(true)
    {
	panel.drawPanel(10, 4);
	panel.update();
    }
    endwin();
}
