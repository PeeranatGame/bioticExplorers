#include "Display.h"

Display::Display() {
}
void Display::begin() {
  Serial.print("Display started: ");
  Serial.println(number);
  tcaselect(number);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.set400kHz();
  oled.setFont(X11fixed7x14B);
  clear();
  displayState = LOW;

  clear();
  oled.set2X();
  oled.setCursor((64 / 2) + 10, 3);
  oled.write(number);
  oled.set1X();

}

void Display::init(int _i2c, int _tca, int _number, int _update, int _charLength, int _charMargin, long on, long off) {
  I2C_ADDRESS = _i2c;
  TCAADDR = _tca;
  Serial.print("Display initialized: ");
  Serial.println(number);
  number = _number;
  previousMillis = 0;
  updateInterval = _update;
  previousMeasurementMillis = 0;
  measurementInterval = 10;
  charLength = _charLength;
  charMargin = _charMargin;
  OnTime = on;
  OffTime = off; 
}

void Display::update() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= updateInterval) {
    previousMillis = currentMillis;
    show(currentMillis);
  }
}

void Display::show(unsigned long currentMillis) {
  tcaselect(number);
  if ((displayState == HIGH) && currentMillis - previousMeasurementMillis >= OnTime) {
    displayState = LOW;
    previousMeasurementMillis = currentMillis;
  } else if ((displayState == LOW) && currentMillis - previousMeasurementMillis >= OffTime) {
    previousMeasurementMillis = currentMillis;
    displayState = HIGH;
  }

  if(displayState == HIGH && number != 1) {
    phValue();
  } else {
    normalText();
  }
  Serial.print("state: ");
  Serial.print(displayState);
  Serial.print("\t");

  Serial.print("show on number: ");
  Serial.println(number);
}

void Display::normalText() {
  int sizeOfArray = sizeof(string_table) / sizeof(int);
  randomSeed(analogRead(0));
  int mRandom = random(sizeOfArray);
  if (previousRandom != mRandom) {
    clear();
    previousRandom = mRandom;
    strcpy_P(buffer, (char*)pgm_read_word(&(string_table[mRandom])));
    //oled.set2X();
    if (lineBreak(charLength, charMargin, buffer)) {
      char buffer2[30];
      strcpy_P(buffer2, (char*)pgm_read_word(&(string_table[mRandom])));
      int lines = howManyLines(buffer2);
      for (int i = 0; i < lines; i++) {
        String brokenText = breakText2(buffer, i);
        char tempText[brokenText.length() + 2];
        brokenText.toCharArray(tempText, brokenText.length() + 2);
        int centerOffset = centerText(charLength, charMargin, tempText);
        oled.setCursor(64 - centerOffset, (i * 2) + 2);
        oled.write(tempText);
      }
    } else {
      int centerOffset = centerText(charLength, charMargin, buffer);
      oled.setCursor(64 - centerOffset, 3);
      oled.write(buffer);
    }
  }
}

void Display::phValue() {
  clear();

  oled.setCursor((64 / 2) + 21, 1);
  oled.write("pH");
  oled.set2X();
  oled.setCursor((64 / 2) + 10, 3);
  oled.write("1.1");
  oled.set1X();
}

void Display::clear() {
  oled.clear();
}

void Display::tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

/**
  charLength = normal length of a character in monospaced font
  str = we want to extract the String's length
  @return: offset by how much we need to move to the left
           from center point of 64 pixels
*/
int Display::centerText(int charLength, int margin, String str) {
  int monoSpace = charLength + margin; // 3 + 1 = 4
  return (str.length() * monoSpace) / 2; // 3 * 4 = 21
}

boolean Display::lineBreak(int charLength, int margin, String str) {
  int monoSpace = charLength + margin;
  return (str.length() * monoSpace) > 128;
}

int Display::howManyLines(char sz[]) {
  char *a = sz;
  char *stra;
  int counter = 0;
  while ((stra = strtok_r(a, ";", &a)) != NULL) {
    counter++;
  }
  return counter;
}

String Display::breakText(char sz[], int line) {
  char *p = sz;
  char *str;
  int counter = 0;
  String found = "";
  while ((str = strtok_r(p, ";", &p)) != NULL) {
    /*
      Serial.print(counter);
      Serial.print("-");
      Serial.println(str);
    */
    if (line == counter) found = str;
    counter++;
  }
  return found;
}

String Display::breakText2(char sz[], int line) {
  String input = sz;
  String output = "";
  for (int i = 0; i < input.length(); i++) {
    if (input.substring(i, i + 1) == ";") {
      if (line == 0) output = input.substring(0, i);
      else output = input.substring(i + 1);
      break;
    }
  }
  return output;
}