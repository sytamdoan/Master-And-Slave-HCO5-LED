/*MASTER MODULE*/
/*
 Author: Tam Doan
 Description: This is code is used for the master HCO5 in the master and slave HC05 blue tooth connection. The master takes in
 the analog value of a potentiometer, maps that value from 1-255, then writes the mapped value as brightness to the slave HCO5 to use.
 NOTE: When starting this project, HCO5 bluetooth module are in default slave modules. One of the module has to be changed to be the master
 using AT command mode. This has to be done so the two HCO5 can communicate with eachother properly. It is also necessary that 
 the master HCO5 be manually paired to the address of the slave HCO5 after setting it to master.
 */
int sensor = A0; /* Takes in which analog in to be use as an output for the potentiometer*/
void setup() {

  Serial.begin(9600);
    
}

void loop() {
  int reading = analogRead(sensor); /* Takes in the reading of the analog pin(A0), the potentiometer. The value will be between 0-1023*/
  int brightness = map(reading,0,1023,1,255); /*The value taken from read will then be mapped from 1-255 to be sent out to the slave to be displayed in an LED*/
  Serial.write(brightness);
  delay(15);
}
