#ifndef EXPLORER_H
#define EXPLORER_H

#include "Display.h"
#include "Flasher.h"
//#include "Display.h"

class Explorer {
	public:
		Explorer();
		void begin();
		void update();
	private:
		#define I2C_ADDRESS 0x3C
		#define TCAADDR 0x70

		long previousMillis;
		long waitMillis;
		float phValue;
		int charLength;
		int charMargin;
		int disp;

		Display display0;
		Display display1;
		Display display2;

		Flasher led1;
};

#endif