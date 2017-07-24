#include <ncurses.h>
#include  <iostream>
#include  <stdint.h>

#include "CPU.h"
#include "Panel.h"

void Panel::init(CPU *cpu_)
{
    cpu = cpu_;
}

void Panel::update()
{
    refresh();
    updateFromInput();
    if(startSwitch)
    {
	cpu->cycle();
    }	
    setAddressLightsFromWord(cpu->PC);
    setDataLightsFromWord(cpu->getMemory(cpu->PC));
}

void Panel::drawDebugInfo()
{
    //TODO: clear string length each preframe
    move(0, 0); clrtoeol();
    move(1, 0); clrtoeol();
    move(2, 0); clrtoeol();

//    mvaddstr(0, 0, std::to_string(cpu->X).c_str());
//    mvaddstr(1, 0, std::to_string(cpu->Y).c_str());
//    mvaddstr(2, 0, std::to_string(cpu->Z).c_str());
//
//    mvaddstr(0, 5, std::to_string(cpu->I).c_str());
//    mvaddstr(0, 5, std::to_string(cpu->J).c_str());
//    mvaddstr(0, 5, std::to_string(cpu->K).c_str());

    mvaddstr(0, 10, std::to_string(cpu->PC).c_str());
    mvaddstr(1, 10, std::to_string(cpu->ACC).c_str());
}

void Panel::drawPanel(int xoff, int yoff)
{
    attron(COLOR_PAIR(1));
    //Draw the outer casing.
    for(int i = 0;i < 121; i++)
    {
	//Draw the outer Lines
	for(int j = 0;j < 31; j++)
	{
	    move(j+yoff - 1, i+xoff - 2);
	    if((j == 0 && i > 0 && i < 120) || (j == 30 && i > 0 && i < 120))
	    {
		addch('_');
	    }
	    
	    if((j == 1 && i == 0) || (j == 30 && i == 120))
	    {
		addch('/');
	    }
	    
	    if((i == 0 && j > 1 && j < 30) || (i == 120 && j > 1 && j < 30))
	    {
		addch('|');
	    }
	    
	    if((j == 1 && i == 120) || (j == 30 && i == 0))
	    {
		addch('\\');
	    }	
	}
	//Draw the Inner lines
	for(int j = 0;j < 29; j++)
	{
	    move(j+yoff, i+xoff);
	    if((j == 0 && i > 0 && i < 116) || (j == 28 && i > 0 && i < 116))
	    {
		addch('_');
	    }
	    
	    if((j == 1 && i == 0) || (j == 28 && i == 116))
	    {
		addch('/');
	    }
	    if((i == 0 && j > 1 && j < 28) || (i == 116 && j > 1 && j < 28))
	    {
		addch('|');
	    }
	    
	    if((j == 1 && i == 116) || (j == 28 && i == 0))
	    {
		addch('\\');
	    }

	    // Decorations
	    if(j <= 3 && j > 0 && i > 86 && i < 116)
	    {
		addch('+');
	    }
	    
	    if(j > 9 && j < 28 && (i == 28 || i == 40 || i == 52))
	    {
		addch('!');
	    }

	    if(j == 9 && i >= 0 && i <= 115)
	    {
		addch('_');
	    }
	    
	    if(j > 1 && j < 8 && (i == 4 || i == 10 || i == 16 || i == 22))
	    {
		addch('|');
	    }
	}
    }
    attroff(COLOR_PAIR(1));
    
    attron(COLOR_PAIR(3));
    move(2 + yoff, 89 + xoff);
    addstr("Astro Computing Inc. AC-6");
    attroff(COLOR_PAIR(3));
    move(2 + yoff, 5 + xoff);
    addstr("START");
    move(7 + yoff, 5 + xoff);
    addstr("STOP");
    move(2 + yoff, 11 + xoff);
    addstr("SINGL");
    move(7 + yoff, 11 + xoff);
    addstr("STEP");
    
    //Draw the data lights
    for(int i = 0; i < 18; i++)
    {
	drawLightAt(108 + xoff - (i * 6), 12 + yoff, dataLightArray[i]);
    }
    
    //Draw the address lights
    for(int i = 0; i < 18; i++)
    {
	drawLightAt(108 + xoff - (i * 6), 18 + yoff, addressLightArray[i]);
    }
    
    //Draw the switches
    for(int i = 0; i < 18; i++)
    {
	drawSwitchAt(108 + xoff - (i * 6), 23 + yoff, switchArray[i]);
    }
    
    drawSwitchAt(6+xoff, 3+yoff, startSwitch);
    
    drawFlickSwitchAt(12+xoff, 3+yoff, singleStepSwitch);
    
    move(0, 0);
}

void Panel::drawLightAt(int x, int y, bool state)
{
    move(y, x);
    addch('/');
    move(y+1, x);
    addch('\\');
    move(y+1, x+2);
    addch('/');
    move(y, x+2);
    addch('\\');
    
    attron(COLOR_PAIR(2));
    if(state)
    {
	move(y, x+1);
	addch('#');
	move(y+1, x+1);
	addch('#');
    }
    else
    {
	move(y, x+1);
	addch(' ');
	move(y+1, x+1);
	addch(' ');
    }
    attroff(COLOR_PAIR(2));
}

void Panel::drawSwitchAt(int x, int y, bool state)
{
    for(int i = 0; i < 4; i++)
    {
	move(y+i, x + 1);
	addch(' ');
    }
    
    if(state)
    {
	move(y, x+1);
	addch('v');
	move(y+1, x+1);
	addch('|');
    }
    
    else
    {
	move(y+3, x+1);
	addch('^');
	move(y+2, x+1);
	addch('|');
    }
    
    move(y+1, x);
    addch('/');
    move(y+1, x+2);
    addch('\\');
    move(y+2, x);
    addch('\\');
    move(y+2, x+2);
    addch('/');
    
    
}

void Panel::drawFlickSwitchAt(int x, int y, int state)
{
    for(int i = 0; i < 4; i++)
    {
	move(y+i, x + 1);
	addch(' ');
    }
    if(state==1)
    {
	move(y, x+1);
	addch('v');
	move(y+1, x+1);
	addch('|');
    }
    else
    {
	move(y+2, x+1);
	addch('|');
	move(y+3, x+1);
	addch('^');
    }
    move(y+1, x);
    addch('/');
    move(y+1, x+2);
    addch('\\');
    move(y+2, x);
    addch('\\');
    move(y+2, x+2);
    addch('/');
}

void Panel::updateFromInput()
{
    int m = getch();
    
    //Input switch thingy
    switch(m)
    {
    case 27:
	//todo Implement exit mechanics
	break;

	//Data section of word
    case '0':
	toggleSwitch(0);
	break;
	
    case '9':
	toggleSwitch(1);
	break;
	
    case '8':
	toggleSwitch(2);
	break;
	
    case '7':
	toggleSwitch(3);
	break;
	
    case '6':
	toggleSwitch(4);
	break;
	
    case '5':
	toggleSwitch(5);
	break;
	
    case '4':
	toggleSwitch(6);
	break;
	
    case '3':
	toggleSwitch(7);
	break;
	
    case '2':
	toggleSwitch(8);
	break;
	
    case '1':
	toggleSwitch(9);
	break;

	//Register section
    case ';':
	toggleSwitch(10);
	break;

    case 'l':
	toggleSwitch(11);
	break;

	//Indirect/Paging
    case 'k':
	toggleSwitch(12);
	break;

    case 'j':
	toggleSwitch(13);
	break;

	//opcode section
    case 'f':
	toggleSwitch(14);
	break;

    case 'd':
	toggleSwitch(15);
	break;

    case 's':
	toggleSwitch(16);
	break;

    case 'a':
	toggleSwitch(17);
	break;

	//Control Keys
	//Read switch: r
    case 'r':
	cpu->PC = getWordFromSwitches();
	break;
	
	//Start switch: q
    case 'q':
	toggleStartSwitch();
	break;
	
	//Single step: e
    case 'e':
	cpu->cycle();
	singleStepSwitch = !singleStepSwitch;
	break;
	
	//Write: w
    case 'w':
	cpu->setMemory(cpu->PC, getWordFromSwitches());
	break;
	
	//Reset: t
    case 't':
	cpu->PC = 0x00;
	break;
	
    }
}

word Panel::getWordFromSwitches()
{
    word sum;
    for(int i = 17; i >= 0 ;i--)
    {
	sum += switchArray[i];
	if(i != 0)
	    sum <<= 1;
    }
    return sum;
}

void Panel::toggleSwitch(int set)
{
    if(set > 17)
	return;
    
    switchArray[set] = !switchArray[set];
}

void Panel::toggleStartSwitch()
{
    startSwitch = !startSwitch;
}

void Panel::setSwitch(int set, bool state)
{
    if(set > 17)
	return;
    
    switchArray[set] = state;
}

void Panel::setDataLightsFromWord(word set)
{
    for(int i = 0; i < 18; i++)
	dataLightArray[i] = (set >> i) & 1;
}

void Panel::setAddressLightsFromWord(word set)
{
    for(int i = 0; i < 18; i++)
	addressLightArray[i] = (set >> i) & 1;
}
