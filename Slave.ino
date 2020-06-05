/* SLAVE MODULE */
/* 
 Author: Tam Doan
 Description: This code is for the slave HCO5 of the master and slave HCO5. This slave will take in serial data given from
 the master HCO5. More specifically, the data given is from the value of a potentiometer mapped to 1-255. The data is then
 used to light up the LED. The LED can be brighten or dimmed depending on the value of the potentiometer. 
*/
int bright = 0; /* Takes in the data given by the master HCO5 to light up the LED*/
void setup() {

  Serial.begin(9600);

}

void loop() {
  if(Serial.available() > 0) {
    bright = Serial.read();
  }
  Serial.println(bright);
  analogWrite(11,bright);
  delay(15);
}
