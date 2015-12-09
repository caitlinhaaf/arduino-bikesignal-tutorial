//IMPORT LED MATRIX LIBRARY
#include "LedControlMS.h"

//BTN DECLARATIONS
int BTN_NUM = 2;
int btns[] = {2,3};

//LED DECLARATIONS (FOR TESTING)
int leds[] = {6,7};

//BTN STATE DECLARATIONS
int nowStates[] = {0,0};
int oldStates[] = {0,0};
int btnStates[] = {0,0};

//R/L VARIABLES
int right = 0;
int left = 0;

//LED MATRIX DECLARATIONS
const int DataIn = 12;       // the number of the output pin
const int CLK = 11; 
const int LOAD = 10;
#define NBR_MTX 2 
LedControl lc=LedControl(12,11,10, NBR_MTX);


void setup(){
// BEGIN SERIAL PRINTING
   Serial.begin (9600);
   Serial.println("Setup");

  //LED MATRICES SETTINGS
  for (int i=0; i< NBR_MTX; i++){
    lc.shutdown(i,false);
  //  /* Set the brightness to a medium values */
    lc.setIntensity(i,8);
  //  /* and clear the display */
    lc.clearDisplay(i);
  }

//  BTN AND LED INPUT/OUTPUT DECLARATIONS
  for(int i = 0; i<2; i++) {
    pinMode(btns[i],INPUT);
    pinMode(leds[i],OUTPUT);
  }

//  LED MATRICES OUTPUTS DECLARATIONS
    pinMode(DataIn, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(LOAD, OUTPUT);
}


//LOOP
void loop(){ 
  for(int i = 0; i < BTN_NUM; i++){
    nowStates[i] = digitalRead(btns[i]);    //setting current state to btn input
    if(nowStates[i] != oldStates[i]){       //comparing current state to previous state
      if(nowStates[i] == 1){                //if the current state is now ON...
        if(btnStates[i] == 0){              //and btn state is OFF
          digitalWrite(leds[i], HIGH);      //turn ON associated LED
          btnStates[i] = 1;                 //set the btn state to ON
          blink(i);                         //run blink() and pass in array position
        }else{                              //otherwise (if btn state is ON)
          digitalWrite(leds[i], LOW);       //turn OFF associated LED 
          btnStates[i] = 0;                 //set the btn state to OFF
          right = 0;                        //set right to 0 (rightBlink OFF)
          left = 0;                         //set left to 0 (leftBlink OFF)
        }
      }
      oldStates[i] = nowStates[i];          //set the associated oldState to the nowState
    }
  }
  delay(50);

// RUNNING THE BLINK LOOPS
  if(right==1){
    rightBlink();
  }else if(left==1){
    leftBlink();
  }
}



//SETTING RIGHT OR LEFT STATE BASED ON BTN INPUT # IN ARRAY
void blink(int x){
   if(x==0){
    Serial.println("BTN R PRESSED" );
      right = 1;
      left = 0;
   }else{
    Serial.println("BTN L PRESSED" );
      right = 0;
      left = 1;
   }
}



//RIGHT BLINK FUNCTION
void rightBlink(){
   //BLINK ON
     lc.setLed(1,3,0,true);
     lc.setLed(1,4,1,true);
     lc.setLed(1,5,2,true);
     lc.setLed(1,6,3,true);
     lc.setLed(1,6,4,true);
     lc.setLed(1,5,5,true);
     lc.setLed(1,4,6,true);
     lc.setLed(1,3,7,true);
    delay(500);
      
    //  BLINK OFF
     lc.setLed(1,3,0,false);
     lc.setLed(1,4,1,false);
     lc.setLed(1,5,2,false);
     lc.setLed(1,6,3,false);
     lc.setLed(1,6,4,false);
     lc.setLed(1,5,5,false);
     lc.setLed(1,4,6,false);
     lc.setLed(1,3,7,false);

  delay(500);
}

//LEFT BLINK FUNCTION
void leftBlink(){
//  BLINK ON
  lc.setLed(0,5,0,true);
  lc.setLed(0,4,1,true);
  lc.setLed(0,3,2,true);
  lc.setLed(0,2,3,true);
  lc.setLed(0,2,4,true);
  lc.setLed(0,3,5,true);
  lc.setLed(0,4,6,true);
  lc.setLed(0,5,7,true);
  
  delay(500);

//  BLINK OFF
  lc.setLed(0,5,0,false);
  lc.setLed(0,4,1,false);
  lc.setLed(0,3,2,false);
  lc.setLed(0,2,3,false);
  lc.setLed(0,2,4,false);
  lc.setLed(0,3,5,false);
  lc.setLed(0,4,6,false);
  lc.setLed(0,5,7,false);

  delay(500);
}

