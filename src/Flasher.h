#ifndef Flasher_h
#define Flasher_h

#include <Arduino.h>

class Flasher   {
	public:
		// Constructor - creates a Flasher 
		// and initializes the member variables and state
		Flasher(int pin, long on, long off);
		void Update();
	private:
		// Class Member Variables
		// These are initialized at startup
		int ledPin;      // the number of the LED pin
		long OnTime;     // milliseconds of on-time
		long OffTime;    // milliseconds of off-time

		// These maintain the current state
		int ledState;                 // ledState used to set the LED
		unsigned long previousMillis;   // will store last time LED was updated
};

#endif