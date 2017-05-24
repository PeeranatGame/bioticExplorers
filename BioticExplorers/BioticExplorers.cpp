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

	if(debug) {
		display0.init(I2C_ADDRESS, TCAADDR, 0, 1000, charLength, charMargin, 3000, 9000);
		display1.init(I2C_ADDRESS, TCAADDR, 1, 2000, charLength, charMargin, 12000, 4000);
		display2.init(I2C_ADDRESS, TCAADDR, 2, 3000, charLength, charMargin, 12000, 4000);
	}

	led1.init(13, 123, 400);

	//actuator1.init(180000, servo1, servo2, true, true);
	actuator1.init(180000, servo1, servo2, true, true);
	//actuator2.init(10500, servo2, true, 1);

	sender.init(13, 12, platform);
	receiver.init(13, 11, platform);
	
}

void Explorer::begin() {
	Serial.println("[ /m ] machine start");
	Serial.print("[ /m ] state: ");
	Serial.println(platform);

	Wire.begin();
	if(debug) {
		display0.begin();
		display1.begin();
		display2.begin();
	}

	sender.begin();
	receiver.begin();
}

void Explorer::update() {
	if(debug) {
		display0.update();
	  	display1.update();
	  	display2.update();
	  	actuator1.update();
  		//actuator2.update();
  	}

  	led1.update();

  	

  	// Serial.print("[ /r ] state:");
  	// Serial.println(receiver.getState());
  	/*
  	sender.update();
  	receiver.update();
  	sender.setState(receiver.getState());
  	*/
}

/*
	create methods that read from receiver and change the status:
	then decide if to send or not and also move the motors
*/