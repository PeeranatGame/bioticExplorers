#ifndef Sender_h
#define Sender_h

#include "VirtualWire.h"

// needs for sender and receiver a state that tells what kind of platform this is
// forward bool platform from main sketch until here!

class Sender {
	public:
		// Constructor - creates a Flasher 
		// and initia8lizes the member variables and state
		Sender();
		void init(int led_pin, int transmit_pin, bool platform);
		void begin();
		void update();
		void encode(int val, byte *encoded);
		void send(byte *message);
		void setState(bool state);
		bool getState();
	private:
		// Class Member Variables
		// These are initialized at startup
		int led_pin;
		int transmit_pin;
		byte encodedVal[2];

		int platform;
		bool sendState;

		// These maintain the current state
		int ledState;                 // ledState used to set the LED
		unsigned long previousMillis;   // will store last time LED was updated
		unsigned long sendInterval;

		unsigned long previousTimeout;
		unsigned long timeoutInterval;
};

#endif