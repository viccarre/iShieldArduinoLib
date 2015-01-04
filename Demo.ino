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
		if(myiShield.isButton1Pressed()){
	Serial.println("true, button pressed");
	}
		if(myiShield.isButton2Pressed()){
	Serial.println("2, button pressed");
	}
		if(myiShield.isButton3Pressed()){
	Serial.println("3, button pressed");
	}
		if(myiShield.isButton4Pressed()){
	Serial.println("4, button pressed");
	}
		if(myiShield.isButton5Pressed()){
	Serial.println("5, button pressed");
	}
		if(myiShield.isButton6Pressed()){
	Serial.println("6, button pressed");
	}
	
		if(myiShield.isSwitch1On() == true){
	Serial.println("true, switch1 is On");
	}
		if(myiShield.isSwitch2On() == true){
	Serial.println("true, switch2 is On");
	}
		if(myiShield.isSwitch3On() == true){
	Serial.println("true, switch3 is On");
	}
		if(myiShield.isSwitch4On() == true){
	Serial.println("true, switch4 is On");
	}
		if(myiShield.isSwitch5On() == true){
	Serial.println("true, switch5 is On");
	}
		if(myiShield.isSwitch6On() == true){
	Serial.println("true, switch6 is On");
	}
	

}