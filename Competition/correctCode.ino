#include <LiquidCrystal.h> // includes the LiquidCrystal Library

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;//echo and trig were inverted
const int led1Pin = 1;
const int led2Pin = 2;
const int buttonPin = 3;

long duration;
int distanceCm;
int threshold = 50;

bool systemActive = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1Pin, OUTPUT);//led pin was set to INPUT
  pinMode(led2Pin, OUTPUT);//SAME
  pinMode(buttonPin, INPUT);//added the button
}

void loop() {
  static bool lastButtonState = HIGH;
  bool buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) { //logic handling
    //double stated button, the system stays active until the next button press
    delay(50);
    systemActive = !systemActive;
    if (!systemActive) {
      digitalWrite(led1Pin, LOW);
      digitalWrite(led2Pin, LOW);
    }
  }

  if (systemActive) {
    digitalWrite(trigPin, LOW); //Trigger pin was only emitting High signal, never uses LOW
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distanceCm = duration * 0.034 / 2;
    
	//printing part was not necessary
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distanceCm);
    lcd.print(" cm");

    if (distanceCm > threshold) {
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led1Pin, LOW);
    } else {
      digitalWrite(led1Pin, HIGH);
      digitalWrite(led2Pin, LOW);
    }
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Off");
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }

  lastButtonState = buttonState;
  delay(100);
}
