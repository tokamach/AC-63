#include "Player.h"

void Player::addToInventory(Item item)
{
  inventory[heldItems] = item;
}
