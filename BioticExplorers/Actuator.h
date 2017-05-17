#ifndef Actuator_h
#define Actuator_h

#include <Arduino.h>
#include "ServoTimer2.h"

extern int minPos;
extern int maxPos;
extern int otherMax;
extern bool platform;
extern bool flipper;

class Actuator
{
	public:
		Actuator();
		void init(int interval, int _pin, bool _dir);
		void attach(int pin);
		void detach();
		void move(int _pos);
		void update();
		void write(int degree);
	private:
		ServoTimer2 servo;         	// the servo
		int pos;              		// current servo position 
		int increment;        		// increment to move for each interval
		int  updateInterval;      	// interval between updates
		unsigned long lastUpdate; 	// last update of position
		int pin;              		// the pin
		bool direction;


};

#endif