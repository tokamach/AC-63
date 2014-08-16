/*
 *DO NOT forget to stop ncurses or else jesus will eat your babies
 */

#include<Astro.h>
#include<iostream>

int main()
{
  Astro astro;
  astro.startCurses();
  astro.initShip();
  while(true)
    {
      astro.drawAll();

      //Icky science magic
      if(!astro.getMove())
		  break;
    }
  //Stop ncurses so the terminal won't aslode
  astro.stopCurses();
  std::cout << "Thats all folks!";
}
