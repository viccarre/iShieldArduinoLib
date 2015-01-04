#include <boards.h>
#include "Boards.h"
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>
#include "iShield.h"

iShield myiShield;
	
void setup()
{
  	// Init. and start BLE library.
	ble_begin();
  	Serial.begin(9600); 
}

void loop()
{

	myiShield.getInbox();
	if(myiShield.isUpPressed() == true){
		Serial.println("true, Up pressed");
	}
			if(myiShield.isDownPressed() == true){
		Serial.println("true, Down pressed");
	}
			if(myiShield.isLeftPressed() == true){
		Serial.println("true, Left pressed");
	}
			if(myiShield.isRightPressed() == true){
		Serial.println("true, Right pressed");
	}
			if(myiShield.isAPressed() == true){
		Serial.println("true, A pressed");
	}
			if(myiShield.isBPressed() == true){
		Serial.println("true, B pressed");
	}
			if(myiShield.isXPressed() == true){
		Serial.println("true, X pressed");
	}
			if(myiShield.isYPressed() == true){
		Serial.println("true, Y pressed");
	}
	
}