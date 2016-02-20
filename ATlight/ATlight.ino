#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

  // Pins
  int ledRed = 22;
  int ledGreen =23;

  int butBack = 27;
  int butUp = 26;
  int butOk = 25;
  int butDown = 24;

  int mode = 0;
  int sub = 0;

  int dmxStart = 1; 
  
  int menuLevel = 0;
  
  int menuUpLast = 0;
  int menuUpState = 0;

  int menuDownLast = 0;
  int menuDownState = 0;

  int menuOkLast = 0;
  int menuOkState = 0;

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
  pinMode(butOk, INPUT);
  pinMode(butDown, INPUT);
  pinMode(butBack, INPUT);

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
  if(mode == 0){
    lcd.print("Home");
    lcd.setCursor(0,1);
    switch(menuLevel){
      case 0:
        lcd.print("> ADDRESSING");
        if(digitalRead(butOk) == HIGH){
          mode = 1;
          delay(50);
        }
        break;
      case 1:
        lcd.print("> PROGRAMS");
        if(digitalRead(butOk) == HIGH){
          mode = 2;
          delay(50);
        }
        break;
      case 2:
        lcd.print("> SETTINGS");
        if(digitalRead(butOk) == HIGH){
          mode = 3;
          delay(50);
        }
        break;
      default:
        if(menuLevel == -1){
          menuLevel = 2;
        }else{
          menuLevel = 0;
        }
    }
  }
  switch(mode){
    case 1:
      lcd.print("ADDRESSING");
      lcd.setCursor(0,1);
        lcd.print("DMX START: ");
        lcd.print(dmxStart);
        if(digitalRead(butUp) == HIGH || digitalRead(butDown) == HIGH){
          lcd.clear();
          lcd.print("ADDRESSING");
          lcd.setCursor(0,1);
          lcd.print("DMX START: ");
          if(digitalRead(butUp) == HIGH){
            lcd.print(dmxStart++);
            delay(300);
          }else if(digitalRead(butDown) == HIGH){
            lcd.print(dmxStart--);
            delay(300);
          }
        }
        break;
    case 2:
      lcd.print("PROGRAMS");
      lcd.setCursor(0,1);
      lcd.print("NO PROGRAMS");
      break;
    case 3:
      lcd.print("SETTINGS");
      lcd.setCursor(0,1);
      lcd.print("NO SETTINGS");
    }
    if(digitalRead(butBack) == HIGH){
      mode = 0;
      menuLevel = 0;
      lcd.clear();
    }
    
  lcd.home();
}

void loop(){
menu();
Serial.println(mode);

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

menuOkState = digitalRead(butOk);
if(menuOkState != menuOkLast){
  if(menuOkState == HIGH){
    lcd.clear();
  }
  delay(50);
}
menuOkLast = menuOkState;
}
// http://www.instructables.com/id/I2C-between-Arduinos/
