#include "Player.h"
#include "CPU.h"
#include "Ship.h"

class Astro
{
 public:
  void drawAll();
  void startCurses();
  void stopCurses();
  void doMove();
  void initShip();
  int getMove();

 private:
  /*
   * Classes
   */
  Player player;
  Ship ship;
  /*
   * Functions
   */
  void fixPlayer();
  void drawPlayer();
  void drawStars(int width, int height);
  void drawStructure(int width, int height);
  /*
   * Variables
   */
  bool cursesStarted = false;
  bool firstRun = true;
  char structureArray[10][10];
};
