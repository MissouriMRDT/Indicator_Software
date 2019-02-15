//Voltage Indicator function
//Timothy Bain

//To be copy pasted into BMS?
//Call this in main loop
//packVoltage, cellVoltages in volts, packCurrent in amps
//cellVoltages must be length NUM_CELLS (8)
void updateLCD(int32_t mainCurrent, uint16_t cellVoltages[])
{
  
  Serial.begin(9600); //Start serial communication at 9600
  
  Serial7.begin(9600); //Start communication with Serial7
  
  const int NUM_CELLS = 8; //this should be in header?
  bool LCD_Update = false;
  float time1 = 0;
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
    float temp_cell_voltage = 0;
    temp_cell_voltage = (static_cast<float>(cellVoltages[i]) / 1000);
    Serial.println("Updating Cell Voltage");
    Serial7.print(i+1);
    Serial7.print(": ");
    Serial7.print(temp_cell_voltage, 1); //cellVoltage from BMS in V?  shows one decimal place
    if((i+1)%3 == 0)
    {
      Serial7.print("V");
    }     
    else
    {
      Serial7.print("V "); 
    }
  } 
  LCD_Update = false;
  
}
