# Momentary-Switch

***
Update 04.10.2019: 
Returned value for "no change" has been changed from -1 to 0, returned value for "button was released" has been changed from 0 to -1
***

Arduino library for reading momentary button switches

   The getSw() function returns current switch status:
   - returned value 0: no change
   - returned value -1: switch button was released
   - returned value 1: switch button was pressed
   - returned value >1: switch button pressed and held for returned value-1 seconds
   
   Switch bounce is measured before the change rather than after. For example; if the switch pin has been
   stable HIGH for as long as the given debounce time, a change to LOW is registred as a valid change.
   The switch response is immediate, and not depending on the given debounce time.
