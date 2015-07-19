## iShield Arduino Library


### Overview

This repository containts the source code and configuration files of the iShield Arduino Library. iShield is an App to control your Arduino board using Bluetooth. It's very simple to use and only requires the BLE Shield to start creating awesome projects using virtual shields in the App.

### Instalation

1. Clone or download this repository.
2. Launch the **Arduino IDE**.
3. In the **Arduino IDE** open: sketch > Import Library menu > and find the folder “iShield Resources” and press import.
4. Close the **Arduino IDE** and reopen to load the new libraries. 
5. Go to File > Examples > iShield and then try to compile one of the examples.

###Using

You can find in the code of one of the example projects one object called `iShield myShield`. This is the most important variable in our project and it allow us to use all the methods of the library. You can declare the iShield object in the heap as a global variable.

In the `void setup()` init the BLE Library.

	void setup()
	{
	  // Init. and start BLE library.
 	 ble_begin();
	}

In the `void loop()` section we use the `getInbox()` to listen messages from the iOS device.

	void loop()
	{
    	myiShield.getInbox();
	}


### Documentation

You can find the documentation to use iShiel Arduino Lib in the ([Wiki](https://github.com/viccarre/iShieldArduinoLib/wiki)).

###Bugs or Issues

If you find a bug you can submit an issue here on github:

[https://github.com/viccarre/iShieldArduinoLib/issues](https://github.com/viccarre/iShieldArduinoLib/issues)

###About iShield

iShield was crafted with love by [@viccarre](https://twitter.com/viccarre). The objective of this project is to encourage makers and Arduino fans to build cool projects using their iPhone or iOS device. Feel free to give some feedback and please don't forget to share this project with others. 








