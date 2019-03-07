//Indicator.cpp
//Indicator_Software
//Timothy Bain
//2019

#include Indicator.h
using namespace std;


Indicator::Indicator(HardwareSerial& serial, int baud) : _HardSerial(serial)//idk about this HardSerial business
{
	LCD_Update = false;
	time1 = 0;
	
	Serial.begin();
	serial.begin();
}

//batteryValues meant to fit properly on the 20x4 display
Indicator::batteryValues(int32_t mainCurrent, uint16_t cellVoltages[], const int NUM_CELLS) : _HardSerial(serial)
{
	float packVoltage = 0; //V not mV
	float packCurrent = 0;//A not mA

	packVoltage = (static_cast<float>(cellVoltages[0]) / 1000);
	packCurrent = (static_cast<float>(mainCurrent) / 1000);

	if(LCD_Update == false)
	{
		Serial.println("Waiting to Update LCD...");
		time1 = millis();
		LCD_Update = true;
	}


	Serial.println("Updating Pack Voltage & Current...");
	//Send the clear command to the display - this returns the cursor to the beginning of the display
	serial.write('|'); //Setting character
	serial.write('-'); //Clear display
  
	serial.print("Pack:");
	serial.print(packVoltage, 1); //packVoltage from BMS, in V
	serial.print("V");
	serial.print(" Cur:");
	serial.print(packCurrent, 2); //packCurrent from BMS, in A
	serial.print("A");
  
	for(int i = 0; i < NUM_CELLS; i++)
	{
		float temp_cell_voltage = 0;
		temp_cell_voltage = (static_cast<float>(cellVoltages[i]) / 1000);
		Serial.println("Updating Cell Voltage");
		serial.print(i+1);
		serial.print(": ");
		serial.print(temp_cell_voltage, 1); //shows one decimal place
		if((i+1)%3 == 0)
		{
			serial.print("V");
		}     
		else
		{
			serial.print("V ");
		}
	} 
  LCD_Update = false;
}