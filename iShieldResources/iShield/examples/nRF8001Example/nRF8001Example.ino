/*
  Created by Victor Carreño, 2015.
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>
#include "iShield.h"

/*
Connect the breakout pins to the Arduino Pins:

SKC  -> 13
MISO -> 12
MOSI -> 11
REQ  -> 9
RDY  -> 8

*/

iShield myiShield;

int LED1 = 6;
int button = 7;

void setup()
{
  // Init. and start BLE library.
  ble_begin();
  Serial.begin(9600); 
  ble_set_name("Breakout");	
  pinMode(LED1, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  
  myiShield.getInbox();
	
    //digital Button
   if(myiShield.isButton1Pressed()){
       digitalWrite(LED1,HIGH);
  }else{
      digitalWrite(LED1,LOW);
  }

    //physical button
   if(digitalRead(button) == HIGH){
      myiShield.LEDOn();
  }else{
      myiShield.LEDOff();
  }
    
}
