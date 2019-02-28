#include <LiquidCrystal.h>
int RED_LED = 10;
int GREEN_LED = 9;
int limit = 350;
int currentValue;
//LCD connections
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  Serial.print("Calibrating...\n"); 
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(A0, INPUT); 
 //set up the LCD screen on start up
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Calibrating");
  for(int i = 0; i <5; i++){
    lcd.print(".");
    delay(1000);
  }
    lcd.clear(); 
    lcd.setCursor(5, 0);
    lcd.print("SENSOR ");
    lcd.setCursor(5, 1);
    lcd.print("ACTIVE");
    delay(1500);
    lcd.clear();
}

void loop() {
 // read the value of the sensor
  currentValue = analogRead(A0);
 // compare the current value with the limit
 // if the current value exceeds the limit, High Gas is printed on the serial monitor and the LCD, green LED is off, red LED blinks
  if (currentValue > limit){
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Value: ");
      lcd.print(currentValue);
      lcd.setCursor(4, 1);
      lcd.print("HIGH GAS");
      Serial.println("HIGH GAS");
      Serial.println(currentValue);
      delay(100);
      digitalWrite(RED_LED, LOW);     
    }
  // if the current value of the sensor is under the limit, No leakage is printed on the Serial monitor and the LCD, green LED is on, red LED is off
  else {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Value: ");
      lcd.print(currentValue);
      lcd.setCursor(4, 1);
      lcd.print("NO LEAKAGE");
      Serial.println("NO LEAKAGE");
      Serial.println(currentValue);
    }
    delay(100);
}
