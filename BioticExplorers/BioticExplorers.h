#ifndef EXPLORER_H
#define EXPLORER_H

#include "Display.h"
#include "Flasher.h"
#include "DoubleActuator.h"
#include "Sender.h"
#include "Receiver.h"

/*
todo:
counter til next transmission
ph values random with perlin noise
more comments
adafruit gfx library?
*/

class Explorer {
	public:
		Explorer(bool _platform, int servo1, int servo2);
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

		bool machineState;

		bool platform;

		Display display0;
		Display display1;
		Display display2;

		Flasher led1;

		DoubleActuator actuator1;
		//Actuator actuator2;

		Sender sender;
		Receiver receiver;

		bool debug = true;
};

#endif