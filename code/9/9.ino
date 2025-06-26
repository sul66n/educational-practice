const int photoResistorPin = A0;
const int greenLedPin = 5;
const int redLedPin = 9;

unsigned long doorOpenTime = 1000;
unsigned long doorCloseTime = 1000;

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(photoResistorPin);

  if (lightLevel > 512) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    Serial.println("Двери открыты");

    delay(doorOpenTime);

    lightLevel = analogRead(photoResistorPin);
    if (lightLevel <= 512) {
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      Serial.println("Двери закрыты");
    }

  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    Serial.println("Двери закрыты");
  }

  delay(doorCloseTime);
}
