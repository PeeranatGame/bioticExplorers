#ifndef DoubleActuator_h
#define DoubleActuator_h

#include <Arduino.h>
#include "ServoTimer2.h"

extern int minPos;
extern int maxPos;
extern int otherMax;
extern bool platform;
extern bool flipper;

class DoubleActuator
{
	public:
		DoubleActuator();
		void init(long interval, int _pin1, int _pin2, bool _dir1, bool _dir2);
		void attach(int pin);
		void detach();
		void move(int _pos);
		void update();
		void write(int degree, int order);
	private:
		ServoTimer2 servo1;         	// the servo
		ServoTimer2 servo2;         	// the servo
		int pos1;              		// current servo position 
		int pos2;              		// current servo position 
		int increment;        		// increment to move for each interval
		long  updateInterval;      	// interval between updates
		unsigned long lastUpdate; 	// last update of position
		int pin1;              		// the pin
		int pin2;              		// the pin
		bool direction1;
		bool direction2;
		


};

#endif