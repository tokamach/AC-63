#include <ncurses.h>
#include <iostream>

#include "Terminal.h"

void Terminal::init(CPU *cpu_)
{
	cpu = cpu_;
}

void Terminal::update()
{
	drawPanel(10, 4);
	refresh();
	updateFromInput();
	if(startSwitch)
	{
		cpu->cycle();
	}	
	setAddressLightsFromShort(cpu->PC);
	setDataLightsFromByte(cpu->ram[cpu->PC]);
}

void Terminal::drawPanel(int xoff, int yoff)
{

	//Draw the outer casing.
	for(int i = 0;i < 134; i++)
	{
		//Draw the outer Lines
		for(int j = 0;j < 29; j++)
		{
			move(j+yoff - 1, i+xoff - 2);
			if((j == 0 && i > 0 && i < 133) || (j == 28 && i > 0 && i < 133))
				addch('_');

			if((j == 1 && i == 0) || (j == 28 && i == 133))
				addch('/');

			if((i == 0 && j > 1 && j < 28) || (i == 133 && j > 1 && j < 28))
				addch('|');

			if((j == 1 && i == 133) || (j == 28 && i == 0))
				addch('\\');
				
		}
		//Draw the Inner lines
		for(int j = 0;j < 27; j++)
		{
			move(j+yoff, i+xoff);
			if((j == 0 && i > 0 && i < 129) || (j == 26 && i > 0 && i < 129))
				addch('_');

			if((j == 1 && i == 0) || (j == 26 && i == 129))
				addch('/');

			if((i == 0 && j > 1 && j < 26) || (i == 129 && j > 1 && j < 26))
				addch('|');

			if((j == 1 && i == 129) || (j == 26 && i == 0))
				addch('\\');
				
			if(j <= 25 && j >= 23 && i > 0 && i < 129)
				addch('+');

			if(j > 0 && j < 23 && i == 76)
				addch('!');

			if(j > 2 && j < 9 && (i == 2 || i == 8 || i == 15 || i == 21))
				addch('|');
		}
	}

	move(24 + yoff, 5 + xoff);
	addstr("Astro Computing Inc. AC-6");
	move(3 + yoff, 3 + xoff);
	addstr("START");
	move(8 + yoff, 3 + xoff);
	addstr("STOP");
	move(3 + yoff, 9 + xoff);
	addstr("SINGLE");
	move(8 + yoff, 9 + xoff);
	addstr("STEP");

	//Draw the switches
	for(int i = 0; i <= 15; i++)
		drawToggleSwitchAt(xoff - (i * 6) + 120, 18 + yoff, switchArray[i]);
	
	//Draw the data lights
	for(int i = 0; i <= 7; i++)
		drawLightAt(xoff - (i * 6) + 120, 7 + yoff, i, DATA);

	//Draw the address lights
	for(int i = 0; i <= 15; i++)
		drawLightAt(xoff - (i * 6) + 120, 13 + yoff, i, ADDRESS);

	drawToggleSwitchAt(4+xoff, 4+yoff, startSwitch);

	drawFlickSwitchAt(10+xoff, 4+yoff, singleStepSwitch);

	move(0, 0);
}

void Terminal::drawLightAt(int x, int y, int index, LightType type)
{
	//This function is ugly. It's awful. But it works.
	if(type == DATA)
	{
		if(index > 7)
			return;

		else
		{
			move(y, x);
			addch('/');
			move(y+1, x);
			addch('\\');
			move(y+1, x+2);
			addch('/');
			move(y, x+2);
			addch('\\');

			if(dataLightArray[index])
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
		}
	}

	if(type == ADDRESS)
	{
		if(index > 15)
			return;

		else
		{
			move(y, x);
			addch('/');
			move(y+1, x);
			addch('\\');
			move(y+1, x+2);
			addch('/');
			move(y, x+2);
			addch('\\');

			if(addressLightArray[index])
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
		}
	}
}

void Terminal::drawToggleSwitchAt(int x, int y, bool state)
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

void Terminal::drawFlickSwitchAt(int x, int y, int state)
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
	if(state==2)
	{
	move(y+2, x+1);
	addch('|');
	move(y+3, x+1);
	addch('^');
	}
	else
	{
	move(y+1, x+1);
	addch('_');
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

void Terminal::updateFromInput()
{
		int m = getch();

		//Input switch thingy
		switch(m)
		{
			case 27:
				//todo Implement exit mechanics
				break;

			//Equals: =
			case 61:
				toggleSwitch(0);
				break;

			case 45:
				toggleSwitch(1);
				break;

			case 48:
				toggleSwitch(2);
				break;

			case 57:
				toggleSwitch(3);
				break;

			case 56:
				toggleSwitch(4);
				break;

			case 55:
				toggleSwitch(5);
				break;

			case 54:
				toggleSwitch(6);
				break;

			case 53:
				toggleSwitch(7);
				break;

			case 52:
				toggleSwitch(8);
				break;

			case 51:
				toggleSwitch(9);
				break;

			case 50:
				toggleSwitch(10);
				break;

			case 49:
				toggleSwitch(11);
				break;
			//Read switch: r
			case 114:
				cpu->PC = getAddressFromSwitches();
				break;

			//Start switch: q
			case 113:
				toggleStartSwitch();
				break;

			//Single step: e
			case 101:
				cpu->cycle();
				singleStepSwitch = !singleStepSwitch;
				break;

			//Write: w
			case 119:
				cpu->ram[cpu->PC] = getDataFromSwitches();
				//setDataLightsFromByte();
				break;

			//Reset: t
			case 116:
				cpu->PC = 0x00;
				break;

		}
}

short Terminal::getAddressFromSwitches()
{
	short sum;
	for(int i = 15; i>0;i--)
	{
		sum += switchArray[i];
		if(i != 15)
		sum<<=1;
	}
	return sum;
}

unsigned char Terminal::getDataFromSwitches()
{
	unsigned char sum;
	for(int i = 7; i > 0; i--)
	{
		sum += switchArray[i];
		if(i != 7)
		 sum<<=1;
	}
	return sum;
}

void Terminal::toggleSwitch(int set)
{
	if(set>15)
		return;

	else
		switchArray[set] = !switchArray[set];
}

void Terminal::toggleStartSwitch()
{
	startSwitch = !startSwitch;
}

void Terminal::setSwitch(int set, bool state)
{
	if(set > 15)
		return;

	else
		switchArray[set] = state;
}

void Terminal::setDataLightsFromByte(unsigned char set)
{
	for(int i = 0; i<7; i++)
		dataLightArray[i] = (set >> i) & 1;
}

void Terminal::setAddressLightsFromShort(short set)
{
	for(int i = 0; i<16; i++)
		addressLightArray[i] = (set >> i) & 1;
}
