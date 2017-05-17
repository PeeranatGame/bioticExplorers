#ifndef Receiver_h
#define Receiver_h

#include "VirtualWire.h"

class Receiver {
	public:
		Receiver();
		void init(int led_pin, int receive_pin);
		void begin();
		void update();
		void readMessage();
		void tryGetMessage(int times);
		void decode(byte * encoded, int & decoded);
	private:
		int led_pin;
		int receive_pin;
		// a buffer to store the incoming messages 
		byte message[VW_MAX_MESSAGE_LEN]; 
		 // the size of the message
		byte messageLength = VW_MAX_MESSAGE_LEN;
		// Value decoded from message
		int decodedVal;
		int mappedVal;

		int MIN_PULSE_WIDTH = 800;
		int MAX_PULSE_WIDTH = 2200;

		unsigned long previousMillis;
		unsigned long receiveInterval;
};

#endif