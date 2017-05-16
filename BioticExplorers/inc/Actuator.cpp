#include "Actuator.h"

Actuator::Actuator(int interval, int _pin, bool _dir) {
	updateInterval = interval;
	increment = 1;
	pin = _pin;
	direction = _dir;
}

void Actuator::Attach(int pin) {
	servo.attach(pin);
}

void Actuator::Detach() {
	servo.detach();
}

void Actuator::Move(int _pos) {
	Attach(pin);
	digitalWrite(pin, HIGH);
	if (direction) servo.write(_pos);
	else servo.write(map(_pos, 0, maxPos, otherMax, otherMax-maxPos));

	direction = !direction;
	delay(250);
	digitalWrite(pin, LOW);
	Detach();
}

void Actuator::Update() {
	if((millis() - lastUpdate) > updateInterval) { // time to update
		lastUpdate = millis();
		if(platform == flipper) {
			Serial.println("servo'd");
			Move(minPos);
			Move(maxPos);
		}
		flipper = !flipper;
		Serial.print("flipp'd: ");
		Serial.println(flipper);
	}
}