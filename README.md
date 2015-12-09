# arduino-bikesignal-tutorial
####IMM Sheridan Technology Studio Project - Chanelle F., Caitlin H., Lucey K.
![bike signal with blink](https://github.com/caitlinhaaf/arduino-bikesignal-tutorial/blob/master/Media/IMG_20151203_161531171.jpg)

######Supply list:
* 1 [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno)
* 1 type B USB cable
* 2 breadboards
* 2 8x8 LED Matrices with attached driver chip - we used [these](https://www.creatroninc.com/product/8x8-led-matrix-board/)
* 2 pushbuttons
* aprox. 20 wires (we also used some female wire to extend

1. Ensure that the [Arduino software](https://www.arduino.cc/en/Main/Software) is installed.

2. Install the LED Matrix Library, The library we used to work with the LED matrices (LedControlMS) was made by [Makespace Madrid](http://makespacemadrid.org/). We pulled the library from this [Instructables page] (http://www.instructables.com/id/LED-Matrix-with-Arduino/). We've also included the library here. You will have to place the library folder into the Program Files > Arduino > Libraries.

3. Refer to included Fritzing diagram for wiring instructions. The pins we used were:
 * Push button 1 - pin 2
 * Push button 2 - pin 3 
 * LED Matrix DataIn - pin 12
 * LED Matrix CLK - pin 11
 * LED Matrix LOAD - pin 10
 * Single LED 1 (used for testing functionality) - pin 6
 * Single LED 2 (used for testing functionality) - pin 7

4. In the Arduino sketch, you will need to include the LED library (#include "LedControlMS.h")  

