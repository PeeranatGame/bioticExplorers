#include "DoubleActuator.h"

DoubleActuator::DoubleActuator() {}

void DoubleActuator::init(long interval, int _pin1, int _pin2,  bool _dir1, bool _dir2) {
	updateInterval = interval;
	increment = 1;
	pin1 = _pin1;
	pin2 = _pin2;
	direction1 = _dir1;
	direction2 = _dir2;
	
}

void DoubleActuator::attach(int pin) {
	servo1.attach(pin1);
	servo2.attach(pin2);
}

void DoubleActuator::detach() {
	servo1.detach();
	servo2.detach();
}

void DoubleActuator::write(int degree, int o) {
	int pulse = map(degree, 0, 180, 800, 2200);
	if(o == 0) servo1.write(pulse);
	else servo2.write(pulse);
}

void DoubleActuator::move(int _pos) {
	attach(pin1);
	digitalWrite(pin1, HIGH);
	if (direction1) write(_pos, 0);
	else write(map(_pos, 0, maxPos, otherMax, otherMax-maxPos), 0);

	//direction = !direction;
	delay(250);
	digitalWrite(pin1, LOW);

	
	digitalWrite(pin2, HIGH);
	if (direction2) write(_pos, 1);
	else write(map(_pos, 0, maxPos, otherMax, otherMax-maxPos), 1);

	//direction = !direction;
	delay(250);
	digitalWrite(pin2, LOW);
	

	detach();


}

void DoubleActuator::update() {
	if((millis() - lastUpdate) > updateInterval) { // time to update
		lastUpdate = millis();
		if(platform == flipper) {
			Serial.println("[ /m ] servo movement");
			move(minPos);
			move(maxPos);
		}
		flipper = !flipper;
		Serial.print("[ /m ] flip status [");
		Serial.print(flipper);
		Serial.println("]");
	}
}