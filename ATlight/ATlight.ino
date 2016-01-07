#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

  // Pins
  int ledRed = 22;
  int ledGreen =23;

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

  int menuItem = 0;

  char listItem;
  
void setup(){ 

  Serial.begin(9600);
  
  lcd.begin(16,2); // LCD setup 16x2

  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home();

  lcd.print("Initializing...");
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  pinMode(butUp, INPUT);
  pinMode(butMid, INPUT);
  pinMode(butDown, INPUT);

  digitalWrite(ledRed, HIGH);

  for(int y = 1; y <= 6; y++){
    if(y%2 == 0){
      digitalWrite(ledRed, LOW);
    }else{
      digitalWrite(ledRed, HIGH);
    }
    delay(500);
  }

  digitalWrite(ledGreen, HIGH);

  lcd.clear();
}

void menu(){

  switch(menuItem){
    case 0:
      menuItem++;
      //menuName = "Addressing";
      break;
  }
  lcd.print("Home");
  lcd.setCursor(0,1);
  lcd.print("> Addressing");
  lcd.home();
}

void loop(){

menu();


  
}
