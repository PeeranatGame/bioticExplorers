#include "BioticExplorers.h"

Explorer machine;
int previousRandom = 0;

void setup() {	
	while (!Serial) { }; // for Leos
	Serial.begin(9600);

	machine.begin(); // "real" constructor
}

void loop() {
	machine.update();
}
