#ifndef Sender_h
#define Sender_h

#include "VirtualWire.h"

class Sender {
	public:
		// Constructor - creates a Flasher 
		// and initializes the member variables and state
		Sender();
		void init(int led_pin, int transmit_pin);
		void begin();
		void update();
		void encode(int val, byte *encoded);
		void send(byte *message);
	private:
		// Class Member Variables
		// These are initialized at startup
		int led_pin;
		int transmit_pin;
		byte encodedVal[2];

		// These maintain the current state
		int ledState;                 // ledState used to set the LED
		unsigned long previousMillis;   // will store last time LED was updated
		unsigned long sendInterval;
};

#endif