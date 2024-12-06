// #include <SoftwareSerial.h>

// RX (receive) to Arduino pin 10, TX (transmit) to Arduino pin 11
const int rx = 0;
const int tx = 1;

const int ledPin = 13;

// SoftwareSerial BTSerial(rx, tx); 

/*
Arduino Due + HC-06 (Bluetooth) -echo bluetooth data

Serial (Tx/Rx) communicate to PC via USB
Serial3 (Tx3/Rx3) connect to HC-06
HC-06 Rx - Due Tx3
HC-06 Tx - Due Rx3
HC-06 GND - Due GND
HC-06 VCC - Due 3.3V

*/
#define HC05 Serial3

void setup() {     
  // BTSerial.begin(9600);         // Start Bluetooth communication
  Serial.begin(9600);  
  HC05.begin(9600);
  Serial.println("HC-05 Bluetooth Module Test");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  // Serial2.begin(9600);
}

void loop() {
  if (HC05.available() > 0) {
    Serial.println("Receiving");
    char data = HC05.read();
    switch(data) {
      case '1': digitalWrite(ledPin, HIGH); break;
      case '0': digitalWrite(ledPin, LOW); break;
      default: Serial.println("No command"); 
    }
    Serial.print("Received via Bluetooth: ");
    Serial.println(data);
  }
  else { 
    Serial.println("Not receiving");
  }

}