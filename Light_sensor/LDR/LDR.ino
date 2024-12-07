int sensorValue;
int outputValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);

  outputValue = map(sensorValue, 0, 1023, 0, 100); // to get light intesity as pourcentage

  Serial.print("Sensor = ");
  Serial.println(sensorValue);
}
