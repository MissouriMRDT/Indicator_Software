//Voltage Indicator function
//Timothy Bain

//To be copy pasted into BMS?
//Call this in main loop
//packVoltage, cellVoltages in volts, packCurrent in amps
//cellVoltages must be length NUM_CELLS (24)
void voltagesToLCD(const float packVoltage, const float packCurrent, const float cellVoltages[])
{
  
  Serial7.begin(9600);
  Serial.begin(9600); //Start serial communication at 9600
  
  Serial7.begin(9600); //Start communication with Serial7
  
  const int NUM_CELLS = 8; //this should be in header?
  bool LCD_Update = false;
  int time1 = 0;

  if(LCD_Update == false)
  {
    time1 = millis();
    LCD_Update = 1;
  }

  if(millis() >= (time1 + 2000))
  {
    //Send the clear command to the display - this returns the cursor to the beginning of the display
    Serial7.write('|'); //Setting character
    Serial7.write('-'); //Clear display
  
    Serial7.print("Pack:");
    Serial7.print(packVoltage, 1); //packVoltage from BMS, in V?
    Serial7.print("V");
    Serial7.print(" Cur:");
    Serial7.print(packCurrent, 2); //packCurrent from BMS, in A?
    Serial7.print("A");
  
    for(int i = 0; i < NUM_CELLS; i++)
    {
      Serial7.print(i);
      Serial7.print(":");
      Serial7.print(cellVoltages[i+1], 1); //cellVoltage from BMS in V?  shows one decimal place
      Serial7.print("V ");
    }
  }

  LCD_Update = false;
}
