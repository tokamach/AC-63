#include "CPU.h"
#include "SFML/Graphics.hpp"

class Terminal
{
	public:
		
	  CPU cpu;
	  enum LightType { DATA, ADDRESS};

	  //Misc functions
	  void init();
	  void update();
	  void updateWithRender(sf::RenderWindow *window);
	  void updateFromInput();
	
	  //Drawing functions
	  void drawPanel(int xoff, int yoff);
	  void drawToggleSwitchAt(int x, int y, bool state);
	  void drawFlickSwitchAt(int x, int y, int state);
	  void drawLightAt(int x, int y, int index, LightType type);

	  //Set data functions
	  void toggleSwitch(int set);
	  void toggleStartSwitch();
	  void setSwitch(int set, bool state);
	  void setIndividualDataLight(int light, bool state);
	  void setIndividualAddressLight(int light, bool state);
	  void setDataLightsFromByte(unsigned char set);
	  void setAddressLightsFromShort(short set);

	  //Get data functions
	  short getAddressFromSwitches();
	  short getAddressFromLights();
	  unsigned char getDataFromSwitches();
	  bool getStartSwitch();

	private:
	  //Arrays to handle drawing and input
	  //                     This bit is to stop the first bool being true
	  bool switchArray[16] = {false};
	  bool addressLightArray[16]; 
	  bool dataLightArray[8];
	  //Switch states
	  bool startSwitch = false;
	  int singleStepSwitch = 0;

};

