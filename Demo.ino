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

	myiShield.SetSignal5(234);
	myiShield.SetSignal4(245);
	myiShield.SetSignal3(129);
	myiShield.SetSignal2(158);
	myiShield.SetSignal1(234);
	myiShield.SetSignal0(123);
	
	
}