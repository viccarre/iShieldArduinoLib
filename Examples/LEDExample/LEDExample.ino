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
