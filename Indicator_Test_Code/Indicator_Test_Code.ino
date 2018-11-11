//Indicator test code
//Timothy Bain



void setup() 
{
  Serial.begin(9600); //Start serial communication at 9600 for debug statements

  Serial.println("Battery Indicator");

  Serial7.begin(9600); //Begin communication with Serial7
  
  Serial7.write(254);//send a command
  Serial7.write(1);//clear display
  
  Serial7.write(254);//send a command
  Serial7.write(128);//cursor home

}

void loop() 
{

  //mock data
  const int NUM_CELLS = 24;
  float packVoltage = 33.61; //second decimal shouldn't show
  float packCurrent = 1.23; //second decimal should show
  float cellVoltages[NUM_CELLS] = {2.11, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9, 4.0, 4.1, 4.2, 4.3, 4.4};
  //I know I didn't have to type them all out!

  
  Serial7.print("Pack:");
  Serial7.print(packVoltage, 1); //packVoltage from BMS, in V?
  Serial7.print("V");
  Serial7.print(" Cur:");
  Serial7.print(packCurrent, 2); //packCurrent from BMS, in A?
  Serial7.print("A");

  int cell = 0;
  for(int i = 0; i < 9; i++)
  {
    Serial7.print(cell+1);
    Serial7.print(":");
    Serial7.print(cellVoltages[cell], 1); //cellVoltage from BMS in V?  shows one decimal place
    Serial7.print("V");
    if(i != 2 && i != 5 & i != 8)
      Serial7.print(" ");
    cell++;
  }
  delay(4500);


  Serial7.write(254);//send a command
  Serial7.write(1);//clear display
  
  Serial7.write(254);//send a command
  Serial7.write(128);//cursor home
  
  for(int i = 0; i <= (NUM_CELLS - 10)/6; i++)
  {
    Serial7.print("Pack:");
    Serial7.print(packVoltage, 1); //packVoltage from BMS, in V?
    Serial7.print("V");
    Serial7.print(" Cur:");
    Serial7.print(packCurrent, 2); //packCurrent from BMS, in A?
    Serial7.print("A");
  
    for(int j = 0; j < 6; j++)
    {
      if(cell < NUM_CELLS)
      {
        Serial7.print(cell+1);
        Serial7.print(":");
        Serial7.print(cellVoltages[cell], 1); //cellVoltage from BMS in V?  shows one decimal place
        Serial7.print("V   ");
        cell++;
      }
    }
    
    delay(3000);
    
    Serial7.write(254);//send a command
    Serial7.write(1);//clear display
  
    Serial7.write(254);//send a command
    Serial7.write(128);//cursor home
    
  }
}
