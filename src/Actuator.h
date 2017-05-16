#ifndef Actuator_h
#define Actuator_h

#include <Arduino.h>
#include <Servo.h>

extern int minPos;
extern int maxPos;
extern int otherMax;
extern bool platform;
extern bool flipper;

class Actuator
{
	public:
		Actuator(int interval, int _pin, bool _dir);
		void Attach(int pin);
		void Detach();
		void Move(int _pos);
		void Update();
	private:
		Servo servo;              	// the servo
		int pos;              		// current servo position 
		int increment;        		// increment to move for each interval
		int  updateInterval;      	// interval between updates
		unsigned long lastUpdate; 	// last update of position
		int pin;              		// the pin
		bool direction;


};

#endif