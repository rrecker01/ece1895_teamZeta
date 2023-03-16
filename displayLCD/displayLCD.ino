#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int buttonState = 0;


void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(16, INPUT);

  //print GAME OVER
  lcd.setCursor(0, 0);
  lcd.print("DONT PRESS");
  lcd.setCursor(0,1);
  lcd.print("THE BUTTON");
}

void loop() {
  // put your main code here, to run repeatedly:
  //print GAME OVER
  buttonState = digitalRead(16);

  if(buttonState == HIGH){
    lcd.setCursor(6, 0);
    lcd.print("GAME");
    lcd.setCursor(6, 1);
    lcd.print("OVER");
  }
  else if(buttonState == LOW){
    lcd.setCursor(0, 0);
    lcd.print("DONT PRESS");
    lcd.setCursor(0,1);
    lcd.print("THE BUTTON");
  }

  delay(500);
}
