#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
//#include <Adafruit_MQTT_FONA.h>

#include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>

#include "DHT.h"
#define DHTTYPE DHT11

#define dpin D4
DHT dht(dpin, DHTTYPE);

void setup() {

  dht.begin();
  Serial.begin(115200);
  Serial.println("\nHUMIDTY and TEMPERATURE/n/n");
  delay(700);
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Current Humidity = ");
  Serial.print(h);
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.println("`C");

  if(isnan(h)||isnan(t))
  {
    return ;
  }
  

  delay(30000);

}
