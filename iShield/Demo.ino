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
	myiShield.readConsole();
	String mensaje = myiShield.printDataConsole();
	Serial.println(mensaje);
	myiShield.writeConsole("Hola");
	delay(1000);
	myiShield.writeConsole("Hola1");
	delay(1000);
	myiShield.writeConsole("Hola2");
	delay(1000);
	
}