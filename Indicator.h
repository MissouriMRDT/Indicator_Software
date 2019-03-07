//Indicator.h
//Indicator_Software
//Timothy Bain
//2019

#include "HardwareSerial.h"

class Indicator(){
	HardwareSerial&  _HardSerial;//idk what to do with this
public:
	Indicator(HardwareSerial& serial, int baud);
	bool LCD_Update;
	float time1;
	void batteryValues(int32_t mainCurrent, uint16_t cellVoltages[]);
};

