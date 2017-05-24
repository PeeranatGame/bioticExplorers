#include "Receiver.h"

Receiver::Receiver() {}

void Receiver::init(int _led_pin, int _receive_pin, bool _platform) {
	led_pin = _led_pin;
	receive_pin = _receive_pin;
	mappedVal = 0;

	previousMillis = 0;
	receiveInterval = 10;

	Serial.print("[ /r ] ");
	Serial.println(_platform);

	platform = _platform;
	receiveState = _platform;
}

void Receiver::begin() {
	// Initialise the IO and ISR
    vw_set_rx_pin(receive_pin);
    vw_setup(2000);	 // Bits per sec
    Serial.println("[ /r ] receiver start");
    Serial.print("[ /r ] state: ");
  	Serial.println(getState());
}

void Receiver::update() {
	readMessage();
  	//operateServo();
}

void Receiver::readMessage() {
  vw_rx_start();
  //Serial.print("[ /r ] trying to get a message...");
  tryGetMessage(10);
  vw_rx_stop(); 
}

void Receiver::tryGetMessage(int times) {
  bool gotMessage = false;
  int i = 0;
  while(i++ < times && !gotMessage) {
  	//Serial.print(i);
  	//Serial.print(" ");
  	// if(millis() - previousMillis > receiveInterval) {
  	// 	previousMillis = millis();
	    if (vw_get_message(message, &messageLength)) { 
	      if (message[2] == 0) {
	        gotMessage = true;
	        // Flash a light to show received good message
	        digitalWrite(led_pin, HIGH); 
	        decode(message,  decodedVal);
	        // Map pot value 0-1023 to Servo
	        //mappedVal = map(decodedVal, 0, 1023, maxServo, minServo);
	        if(decodedVal != platform) setState(HIGH);
	        else setState(LOW);

	        Serial.print("[ /r ] messageState: ");
	        Serial.println(decodedVal);
	        digitalWrite(led_pin, LOW);
	      }
	    }
    // }
    delay(10);
  }
 // Serial.println();
}

// Convert the two bytes back to int
void Receiver::decode(byte * encoded, int & decoded ) {
  decoded = (short)(((encoded[1]) & 0xFF) << 8 | (encoded[0]) & 0xFF);
}

void Receiver::setState(bool _state) {
	receiveState = _state;
}

bool Receiver::getState() {
	return receiveState;
}