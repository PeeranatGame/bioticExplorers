#include "BioticExplorers.h"

Explorer::Explorer() {
	previousMillis = 0;
	waitMillis = 1000;
	phValue = 3.21;

	charLength = 6;
	charMargin = 1;

	disp = 0;

	display0.init(I2C_ADDRESS, TCAADDR, 0, 1000, charLength, charMargin, 3000, 9000);
	display1.init(I2C_ADDRESS, TCAADDR, 1, 2000, charLength, charMargin, 12000, 4000);
	display2.init(I2C_ADDRESS, TCAADDR, 2, 3000, charLength, charMargin, 12000, 4000);

	led1.init(13, 123, 400);
	
}

void Explorer::begin() {
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
}