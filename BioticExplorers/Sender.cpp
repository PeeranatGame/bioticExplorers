#include "Sender.h"

Sender::Sender() {}

void Sender::init(int _pin, int _transmit_pin, bool _platform) {
	led_pin = _pin;
	transmit_pin = _transmit_pin;
	previousMillis = 0;
	sendInterval = 10;

	platform = _platform;
	sendState = LOW;

	previousTimeout = 0;
	timeoutInterval = 2000;
}

void Sender::begin() {

	// Initialise the IO and ISR
	vw_set_tx_pin(transmit_pin);
	vw_setup(2000);       // Bits per sec
	
	Serial.println("[ /s ] sender start");

	// vw_set_tx_pin(transmit_pin);
	// vw_set_rx_pin(receive_pin);
	// vw_set_ptt_pin(transmit_en_pin);
	// vw_set_ptt_inverted(true); // Required for DR3100
	// vw_setup(2000);   // Bits per sec
}

void Sender::update() {
	//Serial.print("[ /s ] sender update: ");
	unsigned long currentMillis = millis();
	if(currentMillis - previousTimeout > timeoutInterval) {
		//Serial.print("? ");
		//if(currentMillis - previousMillis > sendInterval && (sendState == HIGH)) {
			Serial.println("[ /s ] send! ");
			//previousMillis = currentMillis;
			
			// Convert int (PotVal) to byte array (encodedVal)
			encode(platform, encodedVal);
			// Flash a light to show transmitting
			digitalWrite(led_pin, HIGH); 
			// Send the byte array using the transmitter
			send(encodedVal);
			digitalWrite(led_pin, LOW);
			// Wait a little bit before repeating
			delay(10);
		//}
	} //else Serial.print("no");
	//Serial.println();
}

// Convert int to a 2 byte array
void Sender::encode(int val, byte *encoded ) {
  encoded[0] = lowByte(val);
  encoded[1] = highByte(val);
}

// Send byte array
void Sender::send (byte *message) { 
    vw_send(message, sizeof(message));
    Serial.print("[ /s ] sending message: '");
    Serial.print(*message);
    Serial.println("'");
    vw_wait_tx(); // Wait until the whole message is gone 
}

void Sender::setState(bool _state) {
	sendState = _state;
	if(!sendState) previousTimeout = millis();
}

bool Sender::getState() {
	return sendState;
}