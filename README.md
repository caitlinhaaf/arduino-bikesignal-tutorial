# arduino-bikesignal-tutorial
####IMM Sheridan Technology Studio Project - Chanelle F., Caitlin H., Lucey K.
![bike signal with blink](https://github.com/caitlinhaaf/arduino-bikesignal-tutorial/blob/master/Media/IMG_20151203_161531171.jpg)

__The Idea:__
To build a prototype of a portable turn signal for cyclists. Pressing one of 2 buttons would initiate and blinking left signal or blinking right signal to appear on a LED matrix display. Pressing the same button again would cancel the signal.  

__So here's how we did it!__

__Supply list:__
* 1 [Arduino Uno](https://www.arduino.cc/en/Main/ArduinoBoardUno)
* 1 type B USB cable
* 2 breadboards
* 2 8x8 LED Matrices with attached driver chip - we used [these](https://www.creatroninc.com/product/8x8-led-matrix-board/)
* 2 pushbuttons
* ~ 20 wires (we also used some female wire to extend the length of some connections)
* 2 single LED bulbs (for testing pushbutton functionality)

1. __Ensure that the [Arduino software](https://www.arduino.cc/en/Main/Software) is installed__

2. __Install the LED Matrix Library__ The library we used to work with the LED matrices (LedControlMS) was made by [Makespace Madrid](http://makespacemadrid.org/). We pulled the library from this [Instructables page] (http://www.instructables.com/id/LED-Matrix-with-Arduino/). We've also included the library here. This library allowed us to map indiviudal LEDs on up to 8 matrices. The library also has functions for dispalying chars, looping through them, or scrolling strings across the length of the LED matrices. You will have to place the library folder into the Program Files > Arduino > Libraries.

3. __Link your LED Matrix library to the Project__ In the Arduino sketch, you will need to include the LED library (#include "LedControlMS.h"). The library also includes some functions to set intensity and display (see matrix declarations and function inside void setup()). If you use the settings we've included in the sketch, you should start with the LED matrices turned off, with medium brightness when turned on.

4. __Set the inputs/outputs in your Arduino sketch__ Note that we collected the button pin/led pin numbers into arrays. We have also set current (nowState[]), previous (oldState[]), and btn (btnStates[]) states (all to 0, or off) in arrays, and have collected the number of button inputs in a variable (int BTN_NUM). You can refer to included Fritzing diagram (.pngs) for the setup we used. The pins numbers we used were:
 * Push button 1 - pin 2
 * Push button 2 - pin 3 
 * LED Matrix DataIn - pin 12
 * LED Matrix CLK - pin 11
 * LED Matrix LOAD - pin 10
 * Single LED 1 (used for testing functionality) - pin 6
 * Single LED 2 (used for testing functionality) - pin 7

5. __Assign pinModes in the void setup()__ Since we collected the BTN and LED pin numbers in an array, we used a for loop to assign them as inputs/outputs. Assign each of the 3 LED matrix pins as outputs. 

6. __Set Up your void loop() function__ Our void loop() function maps the nowStates[] values to the readings received from the button inputs (_nowStates[i] = digitalRead(btns[i]);_). Meaning if you depress the btn at position 0 in the button array, the nowState at position 0 will be set to 1. Next, the function checks if the nowState[] as associated oldState[] are the same value (_if(nowStates[i] != oldStates[i])_), and if the nowState[] is 1 (_if(nowStates[i] == 1)_)  - if both of these conditionals are true, this means the button has been pressed. The function then checks the associated button state in the btnState[] array, and if it's set to "OFF" (0), the btnState is then set to "ON" (_if(btnStates[i] == 0{btnStates[i] = 1;}_). Else, if the btnStates[] was equal to 1 (button was previously pressed), it will set the btnStates[i] to 0, or "OFF" (_else{digitalWrite(btnStates[i] = 0;}_). Lastly, the function sets the oldStates[i] to nowStates[i].

7. __Set up a void blink() function to set state__ Next we wrote a function that would collect the position of the btn in the array (blink(i)) and based on this number, it would set a right or left state. To test this, we first serial printed a message when each button was pressed to be sure that the code could differentiate between the two (_if(x==0){Serial.println("BTN R PRESSED");}else{Serial.println("BTN L PRESSED")}_).

8. __Test pushbutton functionality by lighting single LED bulb__ You'll see that our void loop() function includes some lines that would turn the single LED bulbs on/off. We found that our LED Matrix components started to burn out fairly quickly, so instead of using these when figuring out the functionality of our pushbuttons, we used the LEDs. Feel free to skip this step in the code and setup, unless you are troubleshooting.

9. __Assemble the project and connect the Arduino to the computer__ Again, refer to our Fritzing diagram for wiring instructions. And again, if you are not using the single LED lights for testing, simply ommit them.
![picture of bike signal wiring](https://github.com/caitlinhaaf/arduino-bikesignal-tutorial/blob/master/Media/IMG_20151203_104801142_HDR%20(1).jpg)

10. __Set up void rightBlink() and void leftBlink() functions__ We used the LED Matrix library to map out our arrow shapes on the matrices. The lc.setLED() function collects 4 parameters: matrix number, column number, row number, and true/false (on/off). We set our right arrow LEDS to blink on/off in the rightBlink() function, and the left arrow LEDS to blink on/off in the leftBlink() function. 

11. __Have blink() function set right/left values__ Now that we've defined the functions we want to run when we signal right/left, we want to run those functions on a button press. At the top of our sketch, we've defined variables of right and left, and assigned both to 0. We assing the right/left buttons in the blink() function - when one of the buttons is pressed right = 1 and left = 0, and vice versa for the other button. We also wanted to have the blinks cancel when the button is pressed a second time (i.e. pressing the left button once will turn on the blink, and twice will turn off the blink), so in the void loop() where we check/assign btn states, if the button was previously set to ON, once pressed again the button will set to OFF, and right and left will be set to 0.

12. __Add conditional to void loop() to check right/left state and run right/left functions__ Since we want to continuously check the state of right/left, and run the associated blink functions continuously when turned ON, we check the right/left states in a conditional at the end of our void loop() function, and run the rightBlink() and leftBlink() functions based on these values.



