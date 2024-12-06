const int ultrasonicPin = 9;
// const int buzzer = 11; 
const int ledPin = 13;

long duration;
int distance;

void setup() {
  pinMode(ultrasonicPin, OUTPUT);
  pinMode(ledPin, OUTPUT);       
  // pinMode(buzzer, OUTPUT);        
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, LOW);      // Turn off LED
  // digitalWrite(buzzer, LOW);      // Turn off buzzer

  // Send ultrasonic pulse
  pinMode(ultrasonicPin, OUTPUT); // Set pin as output to send pulse
  digitalWrite(ultrasonicPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPin, LOW);

  // Measure echo response
  pinMode(ultrasonicPin, INPUT);  // Set pin as input to read echo
  duration = pulseIn(ultrasonicPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  // Output distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Activate LED and buzzer if distance is less than 100 cm
  if (distance < 100) {
    digitalWrite(ledPin, HIGH);
    // digitalWrite(buzzer, HIGH);
    delay(10);
  }

  delay(100); // Small delay to stabilize readings
}
