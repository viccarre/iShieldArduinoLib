#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>
#include "iShield.h"

iShield myiShield;

int redPin = 2;
int greenPin = 3;
int bluePin = 4;

int red, green, blue;

void setup()
{
  	// Init. and start BLE library.
	ble_begin();
  	Serial.begin(9600); 
  	ble_set_name("BLEShield");
  	
	pinMode(redPin, OUTPUT);
  	pinMode(greenPin, OUTPUT);
  	pinMode(bluePin, OUTPUT); 
  	
  	red = 0;
  	green = 0;
  	blue = 0;
  	
}

void loop()
{
	myiShield.getInbox();
	
	red = myiShield.getRedValue();
	green = myiShield.getGreenValue();
	blue = myiShield.getBlueValue();
	
	setColor(red, green, blue);

}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}