/*
   momentarySwitch_Serial
   Created by Olav Kallhovd, Nov 14, 2018.
   
   The getSw() function returns the switch status:
   returned value -1: no change
   returned value 0: switch button was released
   returned value 1: switch button was pressed
   returned value >1: switch button pressed and held for returned value-1 seconds
   
   Switch bounce is measured before the change rather than after. For example; if the switch pin has been
   stable HIGH for as long as the given debounce time, a change to LOW is registred as a valid change.
   The switch response is immediate, and not depending on the given debounce time.
*/

#include <momentarySwitch.h>

//constructor momentarySwitch: uint8_t swPin, boolean internalPullUp, int debounceValue
momentarySwitch button_1(5, 1, 10); 
momentarySwitch button_2(6, 1, 10); 

void setup() {
  Serial.begin(9600);
  button_1.begin();
  button_2.begin();
}

void loop() {
  
  int switchval;
  //update switch 1
  switchval = button_1.getSw();
  if (switchval > -1) {
    Serial.print("switch 1 value: "); Serial.print(switchval);
    if (switchval == 0) {
      Serial.print(", button released");
    }
    else if (switchval == 1) {
      Serial.print(", button pressed");
    }
    else if (switchval > 1) {
      Serial.print(", button pressed for "); Serial.print(switchval-1); Serial.print(" sec."); 
    }
    Serial.println();
  }

  //update switch 2
  switchval = button_2.getSw();
  if (switchval > -1) {
    Serial.print("switch 2 value: "); Serial.print(switchval);
    if (switchval == 0) {
      Serial.print(", button released");
    }
    else if (switchval == 1) {
      Serial.print(", button pressed");
    }
    else if (switchval > 1) {
      Serial.print(", button pressed for "); Serial.print(switchval-1); Serial.print(" sec."); 
    }
    Serial.println();
  }
}


