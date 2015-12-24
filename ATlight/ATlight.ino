
  // Pins
  int ledRed = 3;
  int ledGreen = 5;
  int ledBlue = 6;

  int butUp = 7;
  int butMid = 8;
  int butDown = 9;

  
void setup(){ 

  Serial.begin(9600);

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
}
