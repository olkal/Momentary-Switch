/*
  momentarySwitch.h - Library for reading momentary switches
  Created by Olav Kallhovd, Nov 14, 2018.
*/

#include <momentarySwitch.h>

//constructor:
momentarySwitch::momentarySwitch(const uint8_t swPin, const boolean internalPullUp, const int debounceValue)
{
	_swPin = swPin;
	_internalPullUp = internalPullUp;
	_debounceValue = debounceValue;
}

bool momentarySwitch::begin() 
{
	if (_internalPullUp) {
	  pinMode(_swPin, INPUT_PULLUP);
	}
	else pinMode(_swPin, INPUT);
}

void momentarySwitch::setSwPinActiveHigh()
{
  switchActiveState = 1;
  lastSwState = 0;
}

int momentarySwitch::getSw() {
  int sw = 0;
  bool swstate = digitalRead(_swPin);
  if (swstate != lastSwState) {
    if ((lastSwTime + _debounceValue) < millis()) {
      if (swstate == switchActiveState) { //button has been pressed
        sw = 1;
        SwHold = true;
        SwHoldTime = 0;
      }
      else { //button has been released
        SwHold = false; {
          sw = -1;
        }
      }
      lastSwState = swstate;
      lastSwTime = millis();
    }
  }
  else if (SwHold) { //button is still pressed 
    unsigned long t = (millis() - lastSwTime);
    if ((SwHoldTime + SWITCH_HOLD_INCR_INTERVAL) < t) {
      sw = 1 + (t / SWITCH_HOLD_INCR_INTERVAL);
      SwHoldTime = t;
    }
  }
  return sw;
}
