# arduino-bikesignal-tutorial
####IMM Sheridan Technology Studio Project - Chanelle F., Caitlin H., Lucey K.
![bike signal with blink](https://github.com/caitlinhaaf/arduino-bikesignal-tutorial/blob/master/Media/IMG_20151203_161531171.jpg)

__Supply list:__
* 1 [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno)
* 1 type B USB cable
* 2 breadboards
* 2 8x8 LED Matrices with attached driver chip - we used [these](https://www.creatroninc.com/product/8x8-led-matrix-board/)
* 2 pushbuttons
* ~ 20 wires (we also used some female wire to extend
* 2 single LED bulbs for testing functionality

1. __Ensure that the [Arduino software](https://www.arduino.cc/en/Main/Software) is installed__

2. __Install the LED Matrix Library__ The library we used to work with the LED matrices (LedControlMS) was made by [Makespace Madrid](http://makespacemadrid.org/). We pulled the library from this [Instructables page] (http://www.instructables.com/id/LED-Matrix-with-Arduino/). We've also included the library here. You will have to place the library folder into the Program Files > Arduino > Libraries.

3. __Link your LED library to the Project__ In the Arduino sketch, you will need to include the LED library (#include "LedControlMS.h"). The library also includes some functions to set intensity and display (see matrix declarations and function inside void setup()). If you use the settings we've included in the sketch, you should start with the LED matrices turned off, with medium brightness when turned on.

4. __Set the inputs/outputs in your Arduino sketch__ Note that we collected the button pin/led pin numbers into arrays. We have also set current, previous, and btn states (all to 0, or off) in arrays, and have collected the number of button inputs in a variable (int BTN_NUM). You can refer to included Fritzing diagram for the setup we used. The pins numbers we used were:
 * Push button 1 - pin 2
 * Push button 2 - pin 3 
 * LED Matrix DataIn - pin 12
 * LED Matrix CLK - pin 11
 * LED Matrix LOAD - pin 10
 * Single LED 1 (used for testing functionality) - pin 6
 * Single LED 2 (used for testing functionality) - pin 7

5. __Assign pinModes__  


