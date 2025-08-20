#include <DHT.h>
#include <DHT_U.h>


#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE); // dht is name

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(F("Demo Code for DHT11"));
pinMode(3,INPUT_PULLUP);

dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float t=dht.readTemperature();
float f=dht.readTemperature(true);
int button=digitalRead(3);
/*if(isnan(t)|| isnan(h)||isnan(f))
{
  Serial.println("Failed to read the sensor");
  return;
}*/
if(button==1)
{
Serial.print("Temperature = ");
Serial.print(t);
Serial.println("°C ");
}
else
{
Serial.print("Temperature = ");
Serial.print(f);
Serial.println("°F ");
}

delay(1000);
}

