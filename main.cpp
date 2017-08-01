#include <ncurses.h>
#include <iostream>

#include "CPU.h"
#include "Panel.h"

int main(int argc, char **argv)
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
	panel.drawDebugInfo();
	panel.drawPanel(10, 4);
	panel.update();
    }
    endwin();
}
