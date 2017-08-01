#pragma once

#include <stdint.h>
#include "CPU.h"

class Panel
{
public:
    
    CPU *cpu;
    
    //Misc functions
    void init(CPU *cpu_);
    void update();
    void updateFromInput();
    
    //Drawing functions
    void drawDebugInfo();
    void drawPanel(int xoff, int yoff);
    void drawSwitchAt(int x, int y, bool state);
    void drawFlickSwitchAt(int x, int y, int state);
    void drawLightAt(int x, int y, bool state);
    
    //Set data functions
    void toggleSwitch(int set);
    void toggleStartSwitch();
    void setSwitch(int set, bool state);
    void setIndividualDataLight(int light, bool state);
    void setIndividualAddressLight(int light, bool state);
    void setDataLightsFromWord(word set);
    void setAddressLightsFromWord(word set);
    
    //Get data functions
    word getWordFromSwitches();
    
private:
    //Arrays to handle drawing and input
    bool switchArray[18]       = { false };
    bool addressLightArray[18] = { false }; 
    bool dataLightArray[18]    = { false };
    //Switch states
    bool startSwitch = false;
    int singleStepSwitch = 0;
    
};
