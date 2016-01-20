#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

  // Pins
  int ledRed = 22;
  int ledGreen =23;

  int butUp = 26;
  int butMid = 25;
  int butDown = 24;

  int mode = 0;
  
  int menuLevel = 0;
  
  int menuUpLast = 0;
  int menuUpState = 0;

  int menuDownLast = 0;
  int menuDownState = 0;

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
  lcd.print("Home");
  lcd.setCursor(0,1);
  if(mode == 0){
    switch(menuLevel){
      case 0:
        lcd.print("> ADDRESSING");
        if(digitalRead(butMid) == HIGH){
          mode = 1;
        }
        break;
      case 1:
        lcd.print("> SETTINGS");
        if(digitalRead(butMid) == HIGH){
          mode = 2;
        }
        break;
      case 2:
        lcd.print("> SHUTDOWN");
        if(digitalRead(butMid) == HIGH){
          mode = 3;
        }
        break;
      default:
        if(menuLevel == -1){
          menuLevel = 2;
        }else{
          menuLevel = 0;
        }
    }

    switch(mode){
      case 1:
        lcd.print("test");
        break;
    }
  }
  
  lcd.home();
}

void loop(){
Serial.println(menuLevel);
menu();

menuUpState = digitalRead(butUp);
if(menuUpState != menuUpLast){
  if(menuUpState == HIGH){
      menuLevel++;
      lcd.clear();
  }
  delay(50);
}
menuUpLast = menuUpState;


menuDownState = digitalRead(butDown);
if(menuDownState != menuDownLast){
  if(menuDownState == HIGH){
    menuLevel--;
    lcd.clear();
  }
  delay(50);
}
menuDownLast = menuDownState;

  
}
// http://www.instructables.com/id/I2C-between-Arduinos/
