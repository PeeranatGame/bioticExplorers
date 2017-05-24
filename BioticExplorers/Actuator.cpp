#include "Actuator.h"

Actuator::Actuator() {}

void Actuator::init(int interval, int _pin, bool _dir, int _order) {
	updateInterval = interval;
	increment = 1;
	pin = _pin;
	direction = _dir;
	order = _order;
}

void Actuator::attach(int pin) {
	servo.attach(pin);
}

void Actuator::detach() {
	servo.detach();
}

void Actuator::write(int degree) {
	int pulse = map(degree, 0, 180, 800, 2200);
	servo.write(pulse);
}

void Actuator::move(int _pos) {
	attach(pin);
	digitalWrite(pin, HIGH);
	if (direction) write(_pos);
	else write(map(_pos, 0, maxPos, otherMax, otherMax-maxPos));

	direction = !direction;
	delay(250);
	digitalWrite(pin, LOW);
	detach();
}

void Actuator::update() {
	if((millis() - lastUpdate) > updateInterval) { // time to update
		lastUpdate = millis();
		if(platform == flipper) {
			Serial.println("[ /m ] servo movement");
			move(minPos);
			move(maxPos);
		}
		if(order == 1) flipper = !flipper;
		Serial.print("[ /m ] flip status [");
		Serial.print(flipper);
		Serial.println("]");
	}
}