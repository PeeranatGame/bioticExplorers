#ifndef Receiver_h
#define Receiver_h

#include "VirtualWire.h"

class Receiver {
	public:
		Receiver();
		void init(int led_pin, int receive_pin, bool platform);
		void begin();
		void update();
		void readMessage();
		void tryGetMessage(int times);
		void decode(byte * encoded, int & decoded);
		void setState(bool state);
		bool getState();
	private:
		int platform;

		int led_pin;
		int receive_pin;
		// a buffer to store the incoming messages 
		byte message[VW_MAX_MESSAGE_LEN]; 
		 // the size of the message
		byte messageLength = VW_MAX_MESSAGE_LEN;
		// Value decoded from message
		int decodedVal;
		int mappedVal;

		bool receiveState; // was the message ok | ok = not this platform

		int minServo = 800;
		int maxServo = 2200;

		unsigned long previousMillis;
		unsigned long receiveInterval;
};

#endif