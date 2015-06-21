/*

	iShield.h - Library iShield.
  Created by Victor Carreño, June 17, 2005.
	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#ifndef iShield_h
#define iShield_h

#include <Arduino.h>
#include <boards.h>
#include "Boards.h"
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>

class iShield{

public:
	iShield();
	void getInbox();
	char getOutbox();
	void readConsole();
	String incomingData();
	void writeConsole(String message);

	//Buttons
	void buttonsProcessIncomingData(char data1, char data2);
	bool isButton1Pressed();
	bool isButton2Pressed();
	bool isButton3Pressed();
	bool isButton4Pressed();
	bool isButton5Pressed();
	bool isButton6Pressed();
	//Switches
	void switchesProcessIncomingData(char data1, char data2);
	bool isSwitch1On();
	bool isSwitch2On();
	bool isSwitch3On();
	bool isSwitch4On();
	bool isSwitch5On();
	bool isSwitch6On();
	//Keypad
	void keypadProcessIncomingData(char data1, char data2);
	char getKeypadData();
	bool keypadWasPressed();
	//Sliders
	void slidersProcessIncomingData(char data1, char data2);
	short getSliderAValue();
	short getSliderBValue();
	short getSliderCValue();
	short getSliderDValue();
	short getSliderEValue();
	//RGB
	void RGBProcessIncomingData(int data1, int data2);
	int getRedValue();
	int getGreenValue();
	int getBlueValue();
	//Gamepad
	void gamePadProcessIncomingData(int data1, int data2);
	bool isUpPressed();
	bool isDownPressed();
	bool isLeftPressed();
	bool isRightPressed();
	bool isAPressed();
	bool isBPressed();
	bool isXPressed();
	bool isYPressed();
	//Weather
	void setTemperature(int temp);
	void setHumidity(int hum);
	//LED
	void LEDOn();
	void LEDOff();
	//SevenSegments
	void SevenSegmentsSetChar(char myChar);
	//Analog Signals
	void SetSignal0(char myValue);
	void SetSignal1(char myValue);
	void SetSignal2(char myValue);
	void SetSignal3(char myValue);
	void SetSignal4(char myValue);
	void SetSignal5(char myValue);
	//Accelerometer
	void accelerometerProcessIncomingData(char data1, char data2);
	short getXAxis();
	short getYAxis();
	short getZAxis();
	//Gauge
	void setGaugeValue(int value);

private:

	//Buttons
	bool button1;
	bool button2;
	bool button3;
	bool button4;
	bool button5;
	bool button6;
	//Switches
	bool switch1;
	bool switch2;
	bool switch3;
	bool switch4;
	bool switch5;
	bool switch6;
	//Keypad
	char currentData;
	bool keypadPressed;
	//Sliders
	short sliderAValue;
	short sliderBValue;
	short sliderCValue;
	short sliderDValue;
	short sliderEValue;
	//RGB
	int RedValue;
	int GreenValue;
	int BlueValue;
	//Gamepad
	bool up;
	bool down;
	bool left;
	bool right;
	bool a;
	bool b;
	bool x;
	bool y;
	//Accelerometer
	short XAxis;
	short YAxis;
	short ZAxis;
	//Console
	String messageIn;

};

#endif
