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
	Serial.print("Red Value:");
	Serial.println(myiShield.getRedValue());
	Serial.print("Green Value:");
	Serial.println(myiShield.getGreenValue());
	Serial.print("Blue Value:");
	Serial.println(myiShield.getBlueValue());
	
}