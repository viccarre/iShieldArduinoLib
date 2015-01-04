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
	Serial.print("Slider A value: ");
	Serial.println(myiShield.getSliderAValue());
	Serial.print("Slider B value: ");
	Serial.println(myiShield.getSliderBValue());
	Serial.print("Slider C value: ");
	Serial.println(myiShield.getSliderCValue());
	Serial.print("Slider D value: ");
	Serial.println(myiShield.getSliderDValue());
	Serial.print("Slider E value: ");
	Serial.println(myiShield.getSliderEValue());
	delay(200); 
	
}