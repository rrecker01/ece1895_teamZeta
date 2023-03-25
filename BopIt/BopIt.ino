#include <LiquidCrystal_I2C.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD connected to A4 and A5
SoftwareSerial softwareSerial(0,1); //MP3 Player connected to D0(Rx) and D1(Tx)
DFRobotDFPlayerMini player;

const int correct = 1;
const int wrong = 2;
const int gameOver = 3;
const int score10 = 4;
const int speedUp = 5;
const int DDR = 6;
const int PB = 7;
const int stick = 8;

const int coin = 6;     //Coin slot connected to D2
const int pinball = 2;  //Pinball plunger connected to D4
const int DDRLeft = 9; //DDR Button Left connected to D5
const int DDRUp = 11;   //DDR Button Up connected to D7
const int JSx = A0;     //Joystick x-axis connected to A0
const int JSy = A1;     //Joystick y-axis connected to A1


int prevIn = 0;         //store last input
int gameMap[99];        //array of inputs the game wants
int turn = 0;           //round the player is on
int inDelay = 1000;      //delay between inputs, reset at the start of every game
bool start = false;     //game won't start until start is true

void setup() {

  lcd.init();
  lcd.clear();
  lcd.backlight();

  softwareSerial.begin(9600);
  player.begin(softwareSerial);
  player.volume(30);

  pinMode(coin, INPUT);
  pinMode(pinball, INPUT);
  pinMode(DDRLeft, INPUT);
  pinMode(DDRUp, INPUT);
  pinMode(JSx, INPUT);
}

void loop() {
  //pregame behavior
  prevIn = 0;
  lcd.clear();
  while(start == false){
    prevIn = 0;
    turn = 0;
    inDelay = 1200;
    randomSeed(analogRead(A0));
    for(int i = 0 ; i < 99 ; i++){
      gameMap[i] = random(1,5);
    }
    lcd.setCursor(5,0);
    lcd.print("INSERT");
    lcd.setCursor(6,1);
    lcd.print("COIN");
    //start?
    if(digitalRead(coin) == HIGH){
      start = true;
      player.play(1);
    }
  }

  

  while(start == true){
    lcd.clear();
    if(gameMap[turn] == 1){
        player.play(8);
        lcd.print("WIGGLE!");
      }else if(gameMap[turn] == 3){
        player.play(6);
        lcd.print("FORWARD!");
      }else if(gameMap[turn] == 2){
        player.play(6);
        lcd.print("LEFT!");
      }else if(gameMap[turn] == 4){
        player.play(7);
        lcd.print("PINBALL!");
    }

    for(int i = 0; i < inDelay; i++){
      lcd.setCursor(0,1);
      if(analogRead(JSx) < 450 || analogRead(JSx) > 550){
        prevIn = 1;
      }
      else if(digitalRead(DDRLeft) == HIGH){
        prevIn = 2;
      }
      else if(digitalRead(DDRUp) == HIGH){
        prevIn = 3;
      } 
      else if(pinIn()){
        prevIn = 4;
      }
      // lcd.setCursor(12,0);
      // lcd.print(analogRead(JSx));
      // lcd.setCursor(0,1);
      // lcd.print(prevIn);
      delay(1);
    }

    if(prevIn == gameMap[turn]){
      if(turn%10 == 0){
        inDelay -= 50;
        player.play(5);
      }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(gameMap[turn]);
      lcd.setCursor(0,1);
      lcd.print(prevIn);
      lcd.setCursor(4,0);
      lcd.print("CORRECT");   
      prevIn = 0;  
      turn += 1;
      delay(500); 
    }else{
      lcd.clear();
      delay(500);
      lcd.setCursor(6,0);
      lcd.print("GAME");
      lcd.setCursor(6,1);
      lcd.print("OVER");
      delay(1000);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("HI SCORE");
      for(int i = 0; i <= turn; i++){
        lcd.setCursor(7,1);
        lcd.print(i);
        delay(100);
      }
      delay(3000);
      start = false;
    }  

    //win screen
    if(turn == 99){
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("YOU");
      lcd.setCursor(6,1);
      lcd.print("WIN");
      delay(1000);
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("HI SCORE");
      lcd.setCursor(7,1);
      for(int i = 0; i <= turn; i++){
        lcd.setCursor(7,1);
        lcd.print(i);
        delay(100);
      }
      delay(3000);
      start = false;
    }
  }
}

bool JSWiggled(){
  if(analogRead(JSx) < 450 || analogRead(JSx) > 550)
    return false;
  else
    return true;
}

bool pinIn(){
  return (digitalRead(pinball) == HIGH);
}

bool buttonBlue(){
  return digitalRead(DDRLeft);
}

bool buttonRed(){
  return digitalRead(DDRUp);
}
