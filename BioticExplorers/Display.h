#ifndef Display_h
#define Display_h

#include <Wire.h>
#include <avr/pgmspace.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "Scientists.h"

extern int previousRandom;
extern float phValue;


class Display
{
  //oled.set2X();
  //oled.set1X();

  private:
    SSD1306AsciiWire oled;
    int I2C_ADDRESS;
    int TCAADDR;
    int number; // number if the display for use with multiplexer
    unsigned long previousMillis;
    unsigned long updateInterval;
    unsigned long previousMeasurementMillis;
    unsigned long measurementInterval; // to show ph value
    int charLength;
    int charMargin;
    char buffer[30];
    bool displayState;
    long OnTime;
    long OffTime;

  public:
    Display();
    void begin();
    void init(int i2c, int tca, int _number, int _update, int _charLength, int _charMargin, long on, long off);
    void update();
    void show(unsigned long currentMillis);
    void normalText();
    void phValue();
    void clear();
    void tcaselect(uint8_t i);
    int centerText(int charLength, int margin, String str);
    boolean lineBreak(int charLength, int margin, String str);
    int howManyLines(char sz[]);
    String breakText(char sz[], int line);
    String breakText2(char sz[], int line);
  
};

#endif
