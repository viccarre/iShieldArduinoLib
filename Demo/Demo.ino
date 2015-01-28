#include <boards.h>
#include <SPI.h>
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
        myiShield.getInbox();

    //Buttons
      if(myiShield.isButton1Pressed()){
    Serial.println("1, button pressed");
    }
      if(myiShield.isButton2Pressed()){
    Serial.println("2, button pressed");
    }
      if(myiShield.isButton3Pressed()){
    Serial.println("3, button pressed");
    }
      if(myiShield.isButton4Pressed()){
    Serial.println("4, button pressed");
    }
      if(myiShield.isButton5Pressed()){
    Serial.println("5, button pressed");
    }
      if(myiShield.isButton6Pressed()){
    Serial.println("6, button pressed");
    }
}
