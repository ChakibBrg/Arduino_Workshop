#include <DHT.h>

// Define the DHT sensor type and the pin it's connected to
#define DHTPIN 2      
#define DHTTYPE DHT22  // DHT 22 (AM2302)

// Initialize the DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  delay(2000); // DHT22 needs a 2-second delay between readings

  // Read temperature as Celsius (the default)
  float tempC = dht.readTemperature();
  // Read temperature as Fahrenheit (optional)
  float tempF = dht.readTemperature(true);
  
  // Read humidity
  float humidity = dht.readHumidity();

  // Small error handeling code
  if (isnan(tempC) || isnan(tempF) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("°C ");
  Serial.print("(");
  Serial.print(tempF);
  Serial.println("°F)");
}
