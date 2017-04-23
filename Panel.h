#pragma once

#include <stdint.h>
#include "CPU.h"

class Panel
{
public:
    
    CPU *cpu;
    enum LightType { DATA, ADDRESS};
    
    //Misc functions
    void init(CPU *cpu_);
    void update();
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
    void setDataLightsFromWord(short set);
    void setAddressLightsFromShort(short set);
    
    //Get data functions
    short getAddressFromSwitches();
    short getAddressFromLights();
    short getDataFromSwitches();
    
private:
    //Arrays to handle drawing and input
    bool switchArray[12];
    bool addressLightArray[12]; 
    bool dataLightArray[12];
    //Switch states
    bool startSwitch = false;
    int singleStepSwitch = 0;
    
};
