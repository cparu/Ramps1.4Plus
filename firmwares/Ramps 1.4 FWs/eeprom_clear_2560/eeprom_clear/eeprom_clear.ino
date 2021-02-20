/*
 * EEPROM Clear
 *
 * Sets all of the bytes of the EEPROM to 0.
 * This example code is in the public domain.
 * For 2560
 */

#include <EEPROM.h>
int failFlag=0;
int ledPin=13;  //for melzi ledPin=27   for ramps  ledPin=13
void setup()
{
  int i = 0;
  byte value = 0;
  int length = 4096;


  // Open serial communications and wait for port to open:
  //Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
  
  // write a 0 to all 4096 bytes of the EEPROM
  for (i = 0; i < length; i++)
  {
    if (i % 0x40 == 0)
    {
      //Serial.print("Write:\t");
      //Serial.println(i);
    }
    EEPROM.write(i, 0);
  }
  // read a 0 to all 4096 bytes of the EEPROM
  for (i = 0; i < length; i++)
  {
    if (i % 0x40 == 0)
    {
      //Serial.print("Read:\t");
     // Serial.println(i);
    }
    value = EEPROM.read(i);
    if (value != 0)
    {
     // Serial.print("Error:\t");
      //Serial.println(i);
      break;
    }
  }

  if (i < length)
  {
    //Serial.println("Fail");
    failFlag=0;
  }
  else
  {

    //Serial.println("Success");
    //digitalWrite(ledPin,HIGH);
    failFlag=1;
  }
}

void loop()
{
  if(failFlag > 0){
    delay(500);
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
  }else{
    delay(2000);
    digitalWrite(ledPin,HIGH);
    delay(200);
    digitalWrite(ledPin,LOW);  
  }
}
