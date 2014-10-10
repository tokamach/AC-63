#include "CPU.h"

#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player
{
	public:
		//void addToInventory(Item item);
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();

		int heldItems = 0;
		int playerx;
		int playery;
};

#endif
