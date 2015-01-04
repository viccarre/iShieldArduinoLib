#ifndef iShield_h
#define iShield_h

#include <Arduino.h>
#include <boards.h>
#include "Boards.h"
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>

//iShield Libraries
//#include "buttonSwitches.h"
//#include "keypad.h"
#include "sliders.h"
#include "RGB.h"
#include "gamepad.h"
#include "thermometer.h"
#include "LED.h"
#include "sevenSegment.h"
#include "analogSignals.h"
#include "accelerometer.h"

class iShield{
	
public:
	iShield();
	void getInbox();
	char getOutbox();
	//button Buttons;
	//switches Switches;
	//keypad Keypad;
	sliders Sliders;
	RGB rgb;
	gamepad Gamepad;
	thermometer Thermometer;
	LED led;
	sevenSegment SevenSegment;
	analogSignals AnalogSignals;
	accelerometer Accelerometer;
	void readConsole();
	void printDataConsole();
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
	char getData();
	bool keypadWasPressed();
	

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
	//Console
	String messageIn;
};

#endif