#include <LiquidCrystal.h>

//display code

//arcade font
byte arcadeA[8] = {
  0b00100,
  0b01110,
  0b11011,
  0b11001,
  0b11001,
  0b11111,
  0b11001,
  0b11001
};

byte arcadeC[8] = {
  0b01110,
  0b11011,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b11011,
  0b01110
};

byte arcadeE[8] = {
  0b11111,
  0b11000,
  0b11000,
  0b11000,
  0b11110,
  0b11000,
  0b11000,
  0b11111
};

byte arcadeG[8] = {
  0b01110,
  0b11011,
  0b11000,
  0b11000,
  0b11011,
  0b11001,
  0b11001,
  0b01110
};

byte arcadeH[8] = {
  0b11001,
  0b11001,
  0b11001,
  0b11001,
  0b11111,
  0b11001,
  0b11001,
  0b11001
};

byte arcadeI[8] = {
  0b11111,
  0b01100,
  0b01100,
  0b01100,
  0b01100,
  0b01100,
  0b01100,
  0b11111
};

byte arcadeM[8] = {
  0b10001,
  0b11011,
  0b11111,
  0b10101,
  0b10001,
  0b10001,
  0b10001,
  0b10001
};

byte arcadeN[8] = {
  0b11001,
  0b11001,
  0b11101,
  0b11111,
  0b11111,
  0b11011,
  0b11001,
  0b11001
};

byte arcadeO[8] = {
  0b01110,
  0b11011,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b11011,
  0b01110
};

byte arcadeR[8] = {
  0b11110,
  0b10011,
  0b10011,
  0b10011,
  0b11110,
  0b10111,
  0b10011,
  0b10011
};

byte arcadeT[8] = {
  0b11111,
  0b01100,
  0b01100,
  0b01100,
  0b01100,
  0b01100,
  0b01100,
  0b01100
};

byte arcadeV[8] = {
  0b11001,
  0b11001,
  0b11001,
  0b11001,
  0b11001,
  0b11011,
  0b01110,
  0b00100
};

byte arcade1[8] = {
  0b00000,
  0b00110,
  0b01110,
  0b00110,
  0b00110,
  0b00110,
  0b00110,
  0b01111
};

byte arcade2[8] = {
  0b00000,
  0b01110,
  0b10001,
  0b00011,
  0b00110,
  0b01100,
  0b11000,
  0b11111
};

byte arcade3[8] = {
  0b00000,
  0b01110,
  0b10011,
  0b00011,
  0b00110,
  0b00011,
  0b10011,
  0b01110
};

byte arcade4[8] = {
  0b00000,
  0b00011,
  0b00101,
  0b01001,
  0b11001,
  0b11111,
  0b00011,
  0b00011
};

byte arcade5[8] = {
  0b00000,
  0b11111,
  0b11000,
  0b11000,
  0b11110,
  0b00011,
  0b10011,
  0b01110
};

byte arcade6[8] = {
  0b00000,
  0b01110,
  0b11001,
  0b11000,
  0b11110,
  0b11001,
  0b11001,
  0b01110
};

byte arcade7[8] = {
  0b00000,
  0b11111,
  0b00011,
  0b00011,
  0b00110,
  0b01100,
  0b01100,
  0b01100
};

byte arcade8[8] = {
  0b00000,
  0b01110,
  0b11001,
  0b11001,
  0b01110,
  0b11001,
  0b11001,
  0b01110
};

byte arcade9[8] = {
  0b00000,
  0b01110,
  0b10011,
  0b10011,
  0b01111,
  0b00011,
  0b10011,
  0b01110
};

byte arcade0[8] = {
  0b00000,
  0b01110,
  0b11001,
  0b11001,
  0b11001,
  0b11001,
  0b11001,
  0b01110
};



void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, arcadeA);
  lcd.createChar(1, arcadeC);
  lcd.createChar(2, arcadeE);
  lcd.createChar(3, arcadeG);
  lcd.createChar(4, arcadeH);
  lcd.createChar(5, arcadeI);
  lcd.createChar(6, arcadeM);
  lcd.createChar(7, arcadeN);
  lcd.createChar(8, arcadeO);
  lcd.createChar(9, arcadeR);
  lcd.createChar(10, arcadeT);
  lcd.createChar(11, arcadeV);
  lcd.createChar(12, arcade1);
  lcd.createChar(13, arcade2);
  lcd.createChar(14, arcade3);
  lcd.createChar(15, arcade4);
  lcd.createChar(16, arcade5);
  lcd.createChar(17, arcade6);
  lcd.createChar(18, arcade7);
  lcd.createChar(19, arcade8);
  lcd.createChar(20, arcade9);
  lcd.createChar(21, arcade0);

  //print GAME OVER
  lcd.setCursor(6,0);
  lcd.write((byte)3);

  lcd.setCursor(7,0);
  lcd.write((byte)0);

  lcd.setCursor(8,0);
  lcd.write((byte)6);

  lcd.setCursor(9,0);
  lcd.write((byte)2);

  lcd.setCursor(6,1);
  lcd.write((byte)8);

  lcd.setCursor(7,1);
  lcd.write((byte)11);

  lcd.setCursor(8,1);
  lcd.write((byte)2);

  lcd.setCursor(9,1);
  lcd.write((byte)9);
}

void loop() {
  // put your main code here, to run repeatedly:

}
