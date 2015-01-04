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

	myiShield.SevenSegmentsSetChar('1');
	delay(1000);
		myiShield.SevenSegmentsSetChar('2');
	delay(1000);
		myiShield.SevenSegmentsSetChar('3');
	delay(1000);
		myiShield.SevenSegmentsSetChar('4');
	delay(1000);
		myiShield.SevenSegmentsSetChar('5');
	delay(1000);
		myiShield.SevenSegmentsSetChar('6');
	delay(1000);
		myiShield.SevenSegmentsSetChar('7');
	delay(1000);
		myiShield.SevenSegmentsSetChar('8');
	delay(1000);
		myiShield.SevenSegmentsSetChar('9');
	delay(1000);
		myiShield.SevenSegmentsSetChar('0');
	delay(1000);
	
}