bioticExplorers
======

![header](docs/img/header.jpg)

* Author: Julian Hespenheide (<http://www.julian-h.de>)
* Copyright (C) 2017 Julian Hespenheide.
* Released under the MIT license.

bioticExplorers is the code that is accompanying the likewise named installation of Julian Hespenheide.
It is a collection of code snippets and objects to make code more readable and especially maintanable.

Motivation
----------


Features
--------
* ​

Requirements
------------
* An Arduino — http://arduino.cc/
* 4 × Servo motors
* 2 × RF433 MHz Transmitters and Receivers
* 1 × TCA9548 Multiplexer
* 0 – 16 × OLED Displays (SSD1306)

Installation
------------
Download the ZIP archive, then open the Arduino IDE and choose Sketch > Include Library > Add .ZIP Library... and select your downloaded file.

You should now see in File > Examples > BioticExplorer the basicUsage example.

Code Examples
-------------
Here is the 'basic\_usage' example program, included in the download:




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
    

Documentation
-------------
**Explorer(bool platform)**
Creates a new Machine with identifier if it's the right or left platform

**void begin()**
Call this in your `setup` method to setup the button. All it does is start the machine.

**void update()**
Calls all update methods of the included objects.

To Do
---------------------------------

* Build a memory for the displays so they don't fall-back in the random mode to already mentioneded scientist sentences

License
-------
Copyright (c) 2017 Julian Hespenheide. http://www.julian-h.de

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

