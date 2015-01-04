#include "iShield.h"

iShield::iShield(){};

/* iShield Methods*/



void iShield::getInbox(){
	
	ble_do_events();
	
	while(ble_available()){
		
	// read out command and data
	byte data0 = ble_read();
	byte data1 = ble_read();
	byte data2 = ble_read();
	
	switch(data0){
			case 0x01://Request from Button and Switches
			//Call the process Input for Button and Swithches
			buttonsProcessIncomingData(data1,data2);
			switchesProcessIncomingData(data1,data2);
		break;
			case 0x02:
			//Call the process Input for Keypad
			keypadProcessIncomingData(data1, data2);
		break;
			case 0x03:
			//Call the process Input for Sliders
			//Sliders.processIncomingData(data1, data2);
		break;
			case 0x04:
			//Call the process Input for RGB
			//rgb.processIncomingData(data1, data2);
		break;
			case 0x05:
			//Call the process Input for gamepad
			//Gamepad.processIncomingData(data1, data2);
		break;
			case 0x0A:
			//Call the process Input for accelerometer
			//Accelerometer.processIncomingData(data1, data2);
		break;
	}
	
	}
	
}
/* Buttons Methods*/
void iShield::buttonsProcessIncomingData(char data1,char data2){
	
	switch(data1){
			case 0x01://Request from Button1
			if(data2 == 0x01)
				button1 = true;
			else
				button1 = false;
		break;
			case 0x02://Request from Button1
			if(data2 == 0x01)
				button2 = true;
			else
				button2 = false;
		break;
			case 0x03://Request from Button1
			if(data2 == 0x01)
				button3 = true;
			else
				button3 = false;
		break;
			case 0x04://Request from Button1
			if(data2 == 0x01)
				button4 = true;
			else
				button4 = false;
		break;
			case 0x05://Request from Button1
			if(data2 == 0x01)
				button5 = true;
			else
				button5 = false;
		break;
			case 0x06://Request from Button1
			if(data2 == 0x01)
				button6 = true;
			else
				button6 = false;
		break;
	}
	
}
bool iShield::isButton1Pressed(){
	return button1;
}
bool iShield::isButton2Pressed(){
	return button2;
}
bool iShield::isButton3Pressed(){
	return button3;
}
bool iShield::isButton4Pressed(){
	return button4;
}
bool iShield::isButton5Pressed(){
	return button5;
}
bool iShield::isButton6Pressed(){
	return button6;
}
///////////////////

//Switches Methodos

void iShield::switchesProcessIncomingData(char data1, char data2){
	
	switch(data1){
			case 0x07://Request from Button1
			if(data2 == 0x01)
				switch1 = true;
			else
				switch1 = false;
		break;
			case 0x08://Request from Button1
			if(data2 == 0x01)
				switch2 = true;
			else
				switch2 = false;
		break;
			case 0x09://Request from Button1
			if(data2 == 0x01)
				switch3 = true;
			else
				switch3 = false;
		break;
			case 0x0A://Request from Button1
			if(data2 == 0x01)
				switch4 = true;
			else
				switch4 = false;
		break;
			case 0x0B://Request from Button1
			if(data2 == 0x01)
				switch5 = true;
			else
				switch5 = false;
		break;
			case 0x0C://Request from Button1
			if(data2 == 0x01)
				switch6 = true;
			else
				switch6 = false;
		break;
	}
}

bool iShield::isSwitch1On(){
	return switch1;
}
bool iShield::isSwitch2On(){
	return switch2;
}
bool iShield::isSwitch3On(){
	return switch3;
}
bool iShield::isSwitch4On(){
	return switch4;
}
bool iShield::isSwitch5On(){
	return switch5;
}
bool iShield::isSwitch6On(){
	return switch6;
}
//////////////////

void iShield::readConsole(){
	
	ble_do_events();
	if ( ble_available() )
  {	
  	messageIn = "";
    while ( ble_available() )
    {
		messageIn = messageIn + (char)(ble_read());
    }
  }
}

//Keypad Methods

void iShield::keypadProcessIncomingData(char data1, char data2){
	
	Serial.println(data1);
	Serial.println(data2);
	
	switch(data1){
			case 0x01:
				currentData = '1';
				keypadPressed = true;
		break;
			case 0x02:
				currentData = '2';
				keypadPressed = true;
		break;
			case 0x03:
				currentData = '3';
				keypadPressed = true;
		break;
			case 0x04:
				currentData = '4';
				keypadPressed = true;
		break;
			case 0x05:
				currentData = '5';
				keypadPressed = true;
		break;
			case 0x06:
				currentData = '6';
				keypadPressed = true;
		break;
			case 0x07:
				currentData = '7';
				keypadPressed = true;
		break;
			case 0x08:
				currentData = '8';
				keypadPressed = true;
		break;
			case 0x09:
				currentData = '9';
				keypadPressed = true;
		break;
			case 0x00:
				currentData = '0';
				keypadPressed = true;
		break;
			case 0x13:
				currentData = '.';
				keypadPressed = true;
		break;
			case 0x14:
				currentData = 'i';
				keypadPressed = true;
		break;
			case 0x15:
				currentData = 'e';
				keypadPressed = true;
		break;
			case 0x0A:
				currentData = 'a';
				keypadPressed = true;
		break;
			case 0x0B:
				currentData = 'b';
				keypadPressed = true;
		break;
			case 0x0C:
				currentData = 'c';
				keypadPressed = true;
		break;
		}
	
}

bool iShield::keypadWasPressed(){
	return keypadPressed;
}

char iShield::getKeypadData(){
	if(keypadPressed == true){
		keypadPressed = false;
		return currentData;
	}else{
		return '/';
		}
}

/////////////
void iShield::printDataConsole(){
    Serial.println(messageIn);
}

void iShield::writeConsole(String message){

	String tmp = message;
	char tab2[16];
	strncpy(tab2, tmp.c_str(), sizeof(tab2));
	tab2[sizeof(tab2) - 1] = 0;
	
	if (ble_connected())
  	{
  		for(int i=0; i<sizeof(tab2);i++){
  			ble_write(tab2[i]);
  		}
  	}

  	ble_do_events();
}





