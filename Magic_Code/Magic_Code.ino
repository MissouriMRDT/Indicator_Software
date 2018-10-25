byte contrast = 0; //Will roll over at 255



void setup()

{

  Serial.begin(9600); //Start serial communication at 9600 for debug statements

  Serial.println("Serial7 Example Code");

  

  Serial7.begin(9600); //Begin communication with Serial7



  //Turn on the backlight 100% so we can evaluate the contrast changes
  Serial7.write(18);
  Serial7.write('|'); //Put LCD into setting mode

  Serial7.write(128 + 29); //Set white/red backlight amount to 100%

  //Serial7.write(128 + 0); //TODO Remove - used for defective prototype

}



void loop()

{

  Serial.print("Contrast: ");

  Serial.println(contrast);

  

  //Send contrast setting

  Serial7.write('|'); //Put LCD into setting mode

  Serial7.write(24); //Send contrast command

  Serial7.write(contrast);



  contrast += 5;



  delay(1000); //Hang out for a bit

}


