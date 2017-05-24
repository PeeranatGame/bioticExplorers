#include "BioticExplorers.h"

bool platform = true;
int previousRandom = 0;

// needed for Actuator.h
int servo1pin = 2;
int servo2pin = 3;

int minPos = 0;
int maxPos = 90;
int otherMax = 180;
bool flipper = true;

Explorer machine(platform, servo1pin, servo2pin);


void setup() {	
	//while (!Serial) { }; // for Leos
	//Serial.begin(9600);
	Serial.println("/* - - - - - - - - - - - */");
	Serial.println("/* ~ Biotic Explorers  ~ */");
	Serial.println("/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */");

	machine.begin(); // start the machine
}

void loop() {
	machine.update();
}
