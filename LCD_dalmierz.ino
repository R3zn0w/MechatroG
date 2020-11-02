#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
float czas, odleglosc;
void setup() {
  lcd.begin(16,2);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
}

void loop() {
  lcd.print("Dystans:");
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);
  czas = pulseIn(8, HIGH);
  odleglosc = 0.017 * czas;
  lcd.setCursor(0,1);
  lcd.print(odleglosc);
  lcd.print(" cm");
  delay(500);
  lcd.clear();
}
