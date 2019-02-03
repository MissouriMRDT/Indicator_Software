//Indicator test code
//Timothy Bain

#include <Energia.h>

bool LCD_Update = false;
float time1 = 0;

//mock data
const int NUM_CELLS = 8; //this should be in header?
float packVoltage = 31.61; //second decimal shouldn't show
float packCurrent = 1.73; //second decimal should show
float cellVoltages[NUM_CELLS] = {2.11, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.88};

void setup()
{
  //Serial7.begin(9600);
  Serial.begin(115200); //Start serial communication at 9600
  Serial7.begin(9600); //Start communication with Serial7
  Serial.println("Setting up...");
}

void loop()
{
  if(LCD_Update == false)
  {
    Serial.println("Waiting to Update LCD...");
    time1 = millis();
    LCD_Update = true;
  }

  if(millis() >= (time1 + 5000))
  {
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
      Serial.println("Updating Cell Voltage");
      Serial7.print(i+1);
      Serial7.print(":");
      Serial7.print(cellVoltages[i], 1); //cellVoltage from BMS in V?  shows one decimal place
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
  Serial.println("Updated LCD");
}
