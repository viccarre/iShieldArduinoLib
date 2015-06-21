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
