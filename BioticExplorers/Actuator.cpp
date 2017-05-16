#include "Actuator.h"

Actuator::Actuator() {
	
}

void Actuator::init(int interval, int _pin, bool _dir) {
	updateInterval = interval;
	increment = 1;
	pin = _pin;
	direction = _dir;
}

void Actuator::attach(int pin) {
	servo.attach(pin);
}

void Actuator::detach() {
	servo.detach();
}

void Actuator::move(int _pos) {
	attach(pin);
	digitalWrite(pin, HIGH);
	if (direction) servo.write(_pos);
	else servo.write(map(_pos, 0, maxPos, otherMax, otherMax-maxPos));

	direction = !direction;
	delay(250);
	digitalWrite(pin, LOW);
	detach();
}

void Actuator::update() {
	if((millis() - lastUpdate) > updateInterval) { // time to update
		lastUpdate = millis();
		if(platform == flipper) {
			Serial.println("servo'd");
			move(minPos);
			move(maxPos);
		}
		flipper = !flipper;
		Serial.print("flipp'd: ");
		Serial.println(flipper);
	}
}