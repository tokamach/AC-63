#include<Astro.h>
#include<ncurses.h>
#include<iostream>
#include<stdlib.h>
#include<fstream>

#define STAR_GEN_CHANCE 2

//This does some stuff to fill the ship with goodies like air
void Astro::initShip()
{
  ship = new Ship();
}
/*
 *  The main function. Run it as while loop param, and it will return false on exit.
 */
void Astro::drawAll()
{
  int width;
  int height;
  getmaxyx(stdscr, width, height); 

  if(!cursesStarted)
    {
      std::cerr << "Start ncurses you idiot\n";
      return;
    }
  if(firstRun)
    {
      drawStars(width, height); 
      firstRun = false;
      curs_set(0);
    }

   drawStructure(width, height);
   drawPlayer();
   refresh();
   timeout(-1);
}

void Astro::fixPlayer()
{
  
}

/*
 *  Gets key input and moves the player accordingly.
 */
void Astro::getMove()
{
  int m = getch();
  switch(m)
    {
    case 27:
      return;
      break;

    case KEY_UP:
      playerx--;
      break;
      
    case KEY_DOWN:
      playerx++;
      break;
      
    case KEY_LEFT:
      playery--;
      break;

    case KEY_RIGHT:
      playery++;
      break;
    }
}

void Astro::drawPlayer()
{
    move(playerx, playery);
    addch('@');
}

void Astro::drawStructure(int width, int height)
{
  int hwidth = width/2;
  int hheight = height/2;
}

void Astro::drawStars(int width, int height)
{ 
  int i = 0;
      for(int x = 0; x < width; x++)
	{
	  for(int y = 0;y < height;y++)
	    {
	      move(x, y);
	      if(rand() % 100 < STAR_GEN_CHANCE)
		{
		  addch('*');
		}
	      if(rand() % 100 > STAR_GEN_CHANCE && rand() % 100 < STAR_GEN_CHANCE + 3)
		{
		  addch('.');
		}
	      i++;
	    }
	}
}

void Astro::startCurses()
{
  if(cursesStarted)
  {
    std::cout << "ncurses was started but some bozo started it agian, I'll just refresh the screen.\n";
    refresh();
  }
  else{
    initscr();
    cbreak();
    noecho();
    intrflush(stdscr, false);
    keypad(stdscr, true);
    cursesStarted = true;
  }
}

void Astro::stopCurses()
{
  if(cursesStarted && !isendwin())
    {
      curs_set(1);
      endwin();
    }
  else
    {
      std::cerr << "Start ncurses before stopping it, duh.\n";
    }
}
