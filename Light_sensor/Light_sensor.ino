#include <Wire.h>   // Provides support for I²C communication, which is used to interact with the TSL2591 sensor.
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2591.h>

// Create an instance of the TSL2591
Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

void setup() {
  Serial.begin(9600);
  Serial.println("TSL2591 Light Sensor Test");

  if (!tsl.begin()) {
    Serial.println("No TSL2591 sensor found ... check your wiring?");
    while (1);
  }
  
  configureSensor();
}

void loop() {
  uint16_t broadband = tsl.getFullLuminosity() >> 16;     // >> 16 extracts the upper 16 bits (broadband light).
  uint16_t infrared = tsl.getFullLuminosity() & 0xFFFF;     // & 0xFFFF extracts the lower 16 bits (infrared light).

  Serial.print("Broadband Light: ");
  Serial.print(broadband);
  Serial.print("Infrared Light: ");
  Serial.print(infrared);
  Serial.print("Lux: ");
  Serial.println(tsl.calculateLux(broadband, infrared));

  delay(1000);
}

void configureSensor() {
  // Set gain: Controls the sensitivity of the sensor to light
  // TSL2591_GAIN_LOW, TSL2591_GAIN_MED, TSL2591_GAIN_HIGH, or TSL2591_GAIN_MAX
  tsl.setGain(TSL2591_GAIN_MED);

  // Set integration time: Determines how long the sensor collects light for each measurement
  // TSL2591_INTEGRATIONTIME_100MS, TSL2591_INTEGRATIONTIME_200MS, TSL2591_INTEGRATIONTIME_300MS, 
  // TSL2591_INTEGRATIONTIME_400MS, TSL2591_INTEGRATIONTIME_500MS, TSL2591_INTEGRATIONTIME_600MS
  tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);

  Serial.println("Sensor configuration complete");
}
