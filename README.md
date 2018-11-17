# Momentary-Switch
Arduino library for reading momentary button switches

   The getSw() function returns current switch status:
   - returned value -1: switch button was released
   - returned value 1: switch button was pressed
   - returned value >1: switch button pressed and held for returned value-1 seconds
   
   Switch bounce is measured before the change rather than after. For example; if the switch pin has been
   stable HIGH for as long as the given debounce time, a change to LOW is registred as a valid change.
   The switch response is immediate, and not depending on the given debounce time.
