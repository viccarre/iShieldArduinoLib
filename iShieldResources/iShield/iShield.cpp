/*

	iShield.cpp - Library iShield.
  Created by Victor Carreño, June 17, 2005.
	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#include "iShield.h"

iShield::iShield(){
	RedValue = 0x00;
	GreenValue = 0x00;
	BlueValue = 0x00;
	up = false;
	down = false;
	left = false;
	right = false;
	a = false;
	b = false;
	x = false;
	y = false;
	XAxis = 0x00;
	YAxis = 0x00;
	ZAxis = 0x00;
};

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
			slidersProcessIncomingData(data1, data2);
		break;
			case 0x04:
			//Call the process Input for RGB
			RGBProcessIncomingData(data1, data2);
		break;
			case 0x05:
			//Call the process Input for gamepad
			gamePadProcessIncomingData(data1, data2);
		break;
			case 0x0A:
			//Call the process Input for accelerometer
			accelerometerProcessIncomingData(data1, data2);
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
//Sliders Methods
void iShield::slidersProcessIncomingData(char data1,char data2){

	switch(data1){
			case 0x01://Request from SliderA
			sliderAValue = data2;
		break;
			case 0x02://Request from SliderA
			sliderBValue = data2;
		break;
			case 0x03://Request from SliderA
			sliderCValue = data2;
		break;
			case 0x04://Request from SliderA
			sliderDValue = data2;
		break;
			case 0x05://Request from SliderA
			sliderEValue = data2;
		break;
	}
}

short iShield::getSliderAValue(){
	return sliderAValue;
}

short iShield::getSliderBValue(){
	return sliderBValue;
}

short iShield::getSliderCValue(){
	return sliderCValue;
}

short iShield::getSliderDValue(){
	return sliderDValue;
}

short iShield::getSliderEValue(){
	return sliderEValue;
}
///////////

//RGB
void iShield::RGBProcessIncomingData(int data1,int data2){

	switch(data1){
			case 0x01://Request from Color Red
			RedValue = data2;
		break;
			case 0x02://Request from Color Greeb
			GreenValue = data2;
		break;
			case 0x03://Request from Color Blue
			BlueValue = data2;
		break;

	}
}

int iShield::getRedValue(){
	return RedValue;
}

int iShield::getGreenValue(){
	return GreenValue;
}

int iShield::getBlueValue(){
	return BlueValue;
}
///
//Gamepad
void iShield::gamePadProcessIncomingData(int data1, int data2){

	switch(data1){
			case 0x01:
			if(data2 == 0x01)
				left = true;
			else
				left = false;
		break;
			case 0x02:
			if(data2 == 0x01)
				right = true;
			else
				right = false;
		break;
			case 0x03:
			if(data2 == 0x01)
				down = true;
			else
				down = false;
		break;
			case 0x04:
			if(data2 == 0x01)
				up = true;
			else
				up = false;
		break;
			case 0x05:
			if(data2 == 0x01)
				a = true;
			else
				a = false;
		break;
			case 0x06:
			if(data2 == 0x01)
				b = true;
			else
				b = false;
		break;
			case 0x07:
			if(data2 == 0x01)
				x = true;
			else
				x = false;
		break;
			case 0x08:
			if(data2 == 0x01)
				y = true;
			else
				y = false;
		break;
	}

}

bool iShield::isUpPressed(){
	return up;
}

bool iShield::isDownPressed(){
	return down;
}
bool iShield::isLeftPressed(){
	return left;
}
bool iShield::isRightPressed(){
	return right;
}
bool iShield::isAPressed(){
	return a;
}
bool iShield::isBPressed(){
	return b;
}
bool iShield::isXPressed(){
	return x;
}
bool iShield::isYPressed(){
	return y;
}
//
//Weather
void iShield::setTemperature(int temp){
	if ( ble_connected() )
  {
      ble_write(0x06);
      ble_write(0x01);
      ble_write((char)temp);
  }

  ble_do_events();
}

void iShield::setHumidity(int hum){
	if ( ble_connected() )
  {
      ble_write(0x06);
      ble_write(0x02);
      ble_write((char)hum);
  }

  ble_do_events();
}
///////////

//LED
void iShield::LEDOn(){

	if ( ble_connected() )
  {
      ble_write(0x07);
      ble_write(0x01);
      ble_write(0x01);
  }

  ble_do_events();
}

void iShield::LEDOff(){

	if ( ble_connected() )
  {
      ble_write(0x07);
      ble_write(0x01);
      ble_write(0x00);
  }

  ble_do_events();
}
////
//SevenSegments
void iShield::SevenSegmentsSetChar(char myChar){

	if ( ble_connected() )
  {
      ble_write(0x08);
      ble_write(0x01);
      ble_write(myChar);
  }

  ble_do_events();
}
////
//Analog Signals
void iShield::SetSignal0(char myValue){

	if ( ble_connected() )
  {
      ble_write(0x09);
      ble_write(0x00);
      ble_write(myValue);
  }

  ble_do_events();

}

void iShield::SetSignal1(char myValue){

	if ( ble_connected() )
  {
      ble_write(0x09);
      ble_write(0x01);
      ble_write(myValue);
  }

  ble_do_events();

}

void iShield::SetSignal2(char myValue){

	if ( ble_connected() )
  {
      ble_write(0x09);
      ble_write(0x02);
      ble_write(myValue);
  }

  ble_do_events();

}

void iShield::SetSignal3(char myValue){

	if ( ble_connected() )
  {
      ble_write(0x09);
      ble_write(0x03);
      ble_write(myValue);
  }

  ble_do_events();

}

void iShield::SetSignal4(char myValue){

	if ( ble_connected() )
  {
      ble_write(0x09);
      ble_write(0x04);
      ble_write(myValue);
  }

  ble_do_events();

}

void iShield::SetSignal5(char myValue){

	if ( ble_connected() )
  {
      ble_write(0x09);
      ble_write(0x05);
      ble_write(myValue);
  }

  ble_do_events();

}
///

//Accelerometer
void iShield::accelerometerProcessIncomingData(char data1, char data2){

	switch(data1){
			case 0x01:
				XAxis = data2;
		break;
			case 0x02:
				YAxis = data2;
		break;
			case 0x03:
				ZAxis = data2;
		break;
	}

}

short iShield::getXAxis(){
	return XAxis;
}
short iShield::getYAxis(){
	return YAxis;
}
short iShield::getZAxis(){
	return ZAxis;
}
////
String iShield::incomingData(){
    return messageIn;
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

//Gauge
void iShield::setGaugeValue(int value){

	if ( ble_connected() )
  {
      ble_write(0x0C);
      ble_write(0x01);
      ble_write(value);
      Serial.print("value: ");
      Serial.println(value);
  }
  ble_do_events();
}
