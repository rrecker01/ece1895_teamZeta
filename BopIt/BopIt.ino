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

const int coin = 4;     //Coin slot connected to D2
const int pinball = 6;  //Pinball plunger connected to D4
const int DDRLeft = 11; //DDR Button Left connected to D5
const int DDRRight = 12;//DDR Button Right connected to D6
const int DDRUp = 13;   //DDR Button Up connected to D7
const int DDRDown = 14; //DDR Button Down connected to D8
const int DDRBlue = 18; //Blue DDR Buttons connected to D12
const int DDRRed = 19;  //Red DDR Buttons connected to D13
const int JSx = 23;     //Joystick x-axis connected to A0
const int JSy = 24;     //Joystick y-axis connected to A1


int prevIn = 0;         //store last input
int gameMap[99];        //array of inputs the game wants
int turn = 0;           //round the player is on
int inDelay = 650;     //delay between inputs, reset at the start of every game
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
  pinMode(DDRRight, INPUT);
  pinMode(DDRUp, INPUT);
  pinMode(DDRDown, INPUT);
  pinMode(DDRBlue, OUTPUT);
  pinMode(DDRRed, OUTPUT);
  pinMode(JSx, INPUT);
  pinMode(JSy, INPUT);
}

void loop() {
  //pregame behavior
  lcd.clear();
  if(start == false){
    prevIn = 0;
    turn = 0;
    inDelay = 1000;
    randomSeed(analogRead(0));
    for(int i = 0 ; i < 99 ; i++){
      gameMap[i] = random(1,4);
    }
    lcd.setCursor(5,0);
    lcd.print("INSERT");
    lcd.setCursor(6,1);
    lcd.print("COIN");
  }

  //start?
  if(digitalRead(coin) == HIGH){
    start = true;
    player.play(1);
  }

  while(start == true){
    lcd.clear();
    if(gameMap[turn] == 1){
        player.play(8);
        lcd.print("WIGGLE!");
      }else if(gameMap[turn] == 2){
        digitalWrite(DDRBlue, HIGH);
        player.play(6);
        lcd.print("DANCE!");
      }else if(gameMap[turn] == 3){
        digitalWrite(DDRRed, HIGH);
        player.play(6);
        lcd.print("DANCE!");
      }else if(gameMap[turn] == 4){
        player.play(7);
        lcd.print("PINBALL!");
    }
    for(int i = 0; i < inDelay; i++){
      if(gameMap[turn] == 1){
        prevIn = JSWiggled()*1;
      }else if(gameMap[turn] == 2){
        prevIn = (buttonBlue()||buttonRed())*2;
      }else if(gameMap[turn] == 3){
        prevIn = (buttonRed()||buttonBlue())*3;
      }else if(gameMap[turn] == 4){
        prevIn = pinIn()*4;
      }
      delay(1);
    }

    if(prevIn == gameMap[turn]){
      prevIn = 0;
      if(turn%10 == 0){
        inDelay -= 50;
        player.play(5);
      }   
      turn += 1;
      delay(1000);   
    }else{
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("GAME");
      lcd.setCursor(6,1);
      lcd.print("OVER");
      delay(1000);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("HI SCORE");
      lcd.setCursor(7,0);
      for(int i = 0; i <= turn; i++){
        lcd.clear();
        if(i%10 == 0)
          player.play(4);
        lcd.write(turn);          
      }
      delay(1000);
      start = 0;
    }  

    //win screen
    if(turn == 99){
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("YOU");
      lcd.setCursor(6,1);
      lcd.print("WIN");
      delay(500);
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("HI SCORE");
      lcd.setCursor(7,0);
      for(int i = 0; i <= turn; i++){
        lcd.clear();
        if(i%10 == 0)
          player.play(4);
        lcd.write(turn);          
      }
      delay(1000);
      start = 0;
    }
  }
}

bool JSWiggled(){
  if(analogRead(JSx < 450 || JSx > 550))
    return true;
  else
    return false;
}

bool pinIn(){

  return digitalRead(pinball);
}

bool buttonBlue(){
  return digitalRead(DDRUp) || digitalRead(DDRDown);
}

bool buttonRed(){
  return digitalRead(DDRLeft) || digitalRead(DDRRight);
}
