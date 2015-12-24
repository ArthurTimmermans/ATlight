#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

  // Pins
  int ledRed = 3;
  int ledGreen = 5;
  int ledBlue = 6;

  int butUp = 7;
  int butMid = 8;
  int butDown = 9;

  // LCD setup
  #define I2C_ADDR 0x27
  #define BACKLIGHT_PIN  3
  #define En_pin 2
  #define Rw_pin 1
  #define Rs_pin 0
  #define D4_pin 4
  #define D5_pin 5
  #define D6_pin 6
  #define D7_pin 7

  LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
  
void setup(){ 

  Serial.begin(9600);

  lcd.begin(16,2); // LCD setup 16x2

  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();

  lcd.print("Initializing...");

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  pinMode(butUp, INPUT);
  pinMode(butMid, INPUT);
  pinMode(butDown, INPUT);

  for(int x = 0; x <= 255; x++){
    analogWrite(ledRed, x);
    delay(4);
  }

  for(int y = 1; y <= 6; y++){
    if(y%2 == 0){
      digitalWrite(ledRed, LOW);
    }else{
      digitalWrite(ledRed, HIGH);
    }
    delay(500);
  }

  digitalWrite(ledGreen, HIGH);
  
}

void loop(){

  if(digitalRead(butDown) == HIGH){
    Serial.println("Jep");
  }



  
}
