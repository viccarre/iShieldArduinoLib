#ifndef accelerometer_h
#define accelerometer_h

#include <Arduino.h>
#include <boards.h>
#include "Boards.h"
#include <SPI.h>
#include <Nordic_nRF8001.h>
#include <RBL_nRF8001.h>

class accelerometer {

public:
	accelerometer();
	void processIncomingData(char data1, char data2);
	short getXAxis();
	short getYAxis();
	short getZAxis();

private:
	short XAxis;
	short YAxis;
	short ZAxis;
};

#endif