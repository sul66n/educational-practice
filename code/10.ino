#include <Servo.h>

Servo myServo;

int currentAngle = 90;
int targetAngle = 90;

void setup() {
  myServo.attach(3);
  myServo.write(currentAngle);
  Serial.begin(9600);
  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() > 0 && input.toInt() >= 0 && input.toInt() <= 180) {
      targetAngle = input.toInt();

      if (targetAngle != currentAngle) {
        if (targetAngle > currentAngle) {
          for (int angle = currentAngle; angle <= targetAngle; angle++) {
            myServo.write(angle);
            delay(10);
          }
        } else {
          for (int angle = currentAngle; angle >= targetAngle; angle--) {
            myServo.write(angle);
            delay(10);
          }
        }
        currentAngle = targetAngle;
      }

    } else {
      Serial.println("Ошибка: введите число от 0 до 180");
    }
  }
}
