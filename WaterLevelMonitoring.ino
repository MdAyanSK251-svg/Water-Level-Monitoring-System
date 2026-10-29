#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int waterSensor = A0;
const int greenLED = 5;
const int redLED = 6;
const int buzzer = 8;

const int sensorEmpty = 0;
const int sensorFull = 600;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Water Level");
  delay(1000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(waterSensor);

  int level = map(sensorValue, sensorEmpty, sensorFull, 0, 100);
  level = constrain(level, 0, 100);

  if (level >= 95) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("ALERT: Water level HIGH!");
  } else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  }

  lcd.setCursor(0, 0);
  lcd.print("Water Level:    ");
  lcd.setCursor(0, 1);
  lcd.print(level);
  lcd.print("%               ");

  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print(" | Water Level: ");
  Serial.print(level);
  Serial.println("%");

  delay(300);
}