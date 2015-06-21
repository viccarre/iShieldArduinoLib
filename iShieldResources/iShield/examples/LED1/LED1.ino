/*
  Created by Victor Carreño, June 17, 2005.
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>
#include "iShield.h"

iShield myiShield;

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;

void setup()
{
  	// Init. and start BLE library.
	ble_begin();
  	Serial.begin(9600); 
  	ble_set_name("BLEShield");
  	
  	pinMode(LED1, OUTPUT);
  	pinMode(LED2, OUTPUT); 
  	pinMode(LED3, OUTPUT); 
  	pinMode(LED4, OUTPUT);
  	
  	digitalWrite(LED1,LOW);
  	digitalWrite(LED2,LOW);
  	
}

void loop()
{
	myiShield.getInbox();
	
	//Buttons
	if(myiShield.isButton1Pressed()){
	    digitalWrite(LED1,HIGH);
    }else{
    	digitalWrite(LED1,LOW);
    }
      
    if(myiShield.isButton2Pressed()){
	    digitalWrite(LED2,HIGH);
    }else{
    	digitalWrite(LED2,LOW);
    }
    
    //Switches
	if(myiShield.isSwitch1On()){
    	digitalWrite(LED3,HIGH);
    }else{
    	digitalWrite(LED3,LOW);
    }
    
    if(myiShield.isSwitch2On()){
    	digitalWrite(LED4,HIGH);
    }else{
    	digitalWrite(LED4,LOW);
    }
    
    
}
