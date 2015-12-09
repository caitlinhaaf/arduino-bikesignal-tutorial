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

4. __Set the inputs/outputs in your Arduino sketch__ Note that we collected the button pin/led pin numbers into arrays. We have also set current (nowState[]), previous (oldState[]), and btn (btnStates[]) states (all to 0, or off) in arrays, and have collected the number of button inputs in a variable (int BTN_NUM). You can refer to included Fritzing diagram for the setup we used. The pins numbers we used were:
 * Push button 1 - pin 2
 * Push button 2 - pin 3 
 * LED Matrix DataIn - pin 12
 * LED Matrix CLK - pin 11
 * LED Matrix LOAD - pin 10
 * Single LED 1 (used for testing functionality) - pin 6
 * Single LED 2 (used for testing functionality) - pin 7

5. __Assign pinModes in the void setup()__ Since we collected the BTN and LED pin numbers in an array, we used a for loop to assign them as inputs/outputs. Assign each of the 3 LED matrix pins as outputs. 

6. __Set Up your void loop() function__ Our void loop() function maps the nowStates[] values to the readings received from the button inputs (nowStates[i] = digitalRead(btns[i]);). Meaning if you depress the btn at position 0 in the button array, the nowState at position 0 will be set to 1. Next, the function checks if the nowState[] as associated oldState[] are the same value (if(nowStates[i] != oldStates[i])), and if the nowState[] is 1 (if(nowStates[i] == 1))  - if both of these conditionals are true, this means the button has been pressed. The function then checks the associated button state in the btnState[] array, and if it's set to "OFF" (0), the btnState is then set to "ON" (if(btnStates[i] == 0{btnStates[i] = 1;}). Else, if the btnStates[] was equal to 1 (button was previously pressed), it will set the btnStates[i] to 0, or "OFF" (else{digitalWrite(btnStates[i] = 0;}). Lastly, the function sets the oldStates[i] to nowStates[i].

7. __Set up a void blink() function to set state__

8. __Set up void rightBlink() and void leftBlink() functions__

9. __Add conditional to void loop() to check right/left state and run right/left functions__ 



