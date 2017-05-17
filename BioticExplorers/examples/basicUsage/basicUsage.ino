#include "BioticExplorers.h"

bool platform = true;
Explorer machine(platform);
int previousRandom = 0;



void setup() {	
	while (!Serial) { }; // for Leos
	Serial.begin(9600);

	machine.begin(); // start the machine
}

void loop() {
	machine.update();
}
