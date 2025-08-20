#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE); // dht is name

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println(F("Demo Code for DHT11"));
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float t=dht.readTemperature();
float h=dht.readHumidity();
float f=dht.readTemperature(true);

if(isnan(t)|| isnan(h)||isnan(f))
{
  Serial.println("Failed to read the sensor");
  return;
}
Serial.print("Temperature = ");
Serial.print(t);
Serial.println("°C ");

Serial.print("Temperature = ");
Serial.print(f);
Serial.println("°F ");

Serial.print("Humidity = ");
Serial.print(h);
Serial.println("% ");
delay(3000);
}
