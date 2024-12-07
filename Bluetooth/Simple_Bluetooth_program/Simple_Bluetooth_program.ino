const int rx = 0;
const int tx = 1;

const int ledPin = 13;

void setup() {     
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
    switch(data) {
      case 'a': digitalWrite(ledPin, HIGH); break;
      case 'b': digitalWrite(ledPin, LOW); break;
      default: Serial.println("No command"); 
    }
    Serial.print("Received via Bluetooth: ");
    Serial.println(data);
  }
  delay(50);
}