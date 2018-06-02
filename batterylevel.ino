

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// the setup routine runs once when you press reset:
void setup() {
  lcd.begin(16, 2);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (4.2 / 1023.0);
  int bat_level = map(sensorValue, 3, 1023, 0, 100 );
  // print out the value you read:
  lcd.print("Bat Level:");

  lcd.setCursor(11, 0);
  lcd.print(bat_level);

  lcd.setCursor(13, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Bat Volt:");

  lcd.setCursor(10, 10);
  lcd.print(voltage);  

  lcd.setCursor(14, 14);
  lcd.print("V");

  lcd.setCursor(15, 15);
  lcd.print(" ");
  
  Serial.println(bat_level);
  Serial.println(voltage);
  Serial.println(sensorValue);
  delay(3000);
}
