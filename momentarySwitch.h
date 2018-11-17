/*
  momentarySwitch.h - Library for reading momentary switches
  Created by Olav Kallhovd, Nov 14, 2018.
*/

#ifndef momentarySwitch_h
#define momentarySwitch_h

#include "Arduino.h"

#define SWITCH_HOLD_INCR_INTERVAL 1000 // hold button time increment interval in ms

class momentarySwitch
{
	uint8_t _swPin;
	bool _internalPullUp;
	int _debounceValue;
	bool lastSwState = 1;
	unsigned long lastSwTime = 0;
	bool SwHold = 0;
	int SwHoldTime = 0;
	bool switchActiveState = 0;
	
public:
    momentarySwitch(const uint8_t swPin, const boolean internalPullUp, const int debounceValue);
    bool begin();
	int getSw();
	int getSwHoldTime();
	void setSwPinActiveHigh();
};

#endif