#include <Servo.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

Servo myServo;

void setup() 
{
  myServo.attach(6);
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  delay(2000);
  float f = dht.readTemperature(true); // in fahrenheit

  if (isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("%  Temperature: "));
  Serial.print(f);
  
  
  
  
  
  int fValue = digitalRead(2);

  Serial.print("2 => ");
  Serial.println(f);

  int servoPos =map(f, 70, 100, 0, 180);

  myServo.write(servoPos);
  delay(20);

  
  
}
