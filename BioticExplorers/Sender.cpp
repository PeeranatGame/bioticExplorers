#include "Sender.h"

Sender::Sender() {

}

void Sender::init(int _pin, int _transmit_pin) {
	led_pin = _pin;
	transmit_pin = _transmit_pin;
	previousMillis = 0;
	sendInterval = 10;
}

void Sender::begin() {
	// Initialise the IO and ISR
	vw_set_tx_pin(transmit_pin);
	vw_setup(2000);       // Bits per sec

	// vw_set_tx_pin(transmit_pin);
	// vw_set_rx_pin(receive_pin);
	// vw_set_ptt_pin(transmit_en_pin);
	// vw_set_ptt_inverted(true); // Required for DR3100
	// vw_setup(2000);   // Bits per sec
}

void Sender::update() {
	if(millis() - previousMillis > sendInterval) {
		previousMillis = millis();
		// Read the pot
		int potVal = 123;
		// Convert int (PotVal) to byte array (encodedVal)
		encode(potVal, encodedVal);
		// Flash a light to show transmitting
		digitalWrite(led_pin, HIGH); 
		// Send the byte array using the transmitter
		send(encodedVal);
		digitalWrite(led_pin, LOW);
		// Wait a little bit before repeating
	}
}

// Convert int to a 2 byte array
void Sender::encode(int val, byte *encoded ) {
  encoded[0] = lowByte(val);
  encoded[1] = highByte(val);
}

// Send byte array
void Sender::send (byte *message) { 
    vw_send(message, sizeof(message)); 
    vw_wait_tx(); // Wait until the whole message is gone 
}