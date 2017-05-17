#include "BioticExplorers.h"

Explorer::Explorer(bool _platform, int servo1, int servo2) {
	machineState = _platform;

	previousMillis = 0;
	waitMillis = 1000;
	phValue = 3.21;

	charLength = 6;
	charMargin = 1;

	disp = 0;

	platform = _platform;

	display0.init(I2C_ADDRESS, TCAADDR, 0, 1000, charLength, charMargin, 3000, 9000);
	display1.init(I2C_ADDRESS, TCAADDR, 1, 2000, charLength, charMargin, 12000, 4000);
	display2.init(I2C_ADDRESS, TCAADDR, 2, 3000, charLength, charMargin, 12000, 4000);

	led1.init(13, 123, 400);

	actuator1.init(10000, servo1, true);
	actuator2.init(5000, servo2, true);
	
}

void Explorer::begin() {
	Serial.println("Machine start");

	Wire.begin();
	display0.begin();
	display1.begin();
	display2.begin();
}

void Explorer::update() {
	display0.update();
  	display1.update();
  	display2.update();

  	led1.update();

  	actuator1.update();
  	actuator2.update();
}

/*
	create methods that read from receiver and change the status:
	then decide if to send or not and also move the motors
*/