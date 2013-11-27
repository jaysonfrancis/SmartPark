

#include <LiquidCrystal.h>
#include <Servo.h> 

Servo servo1;

LiquidCrystal lcd(12,11,5,4,3,2);
const int analogInPin = A0 ;
int sensorValue = 0;

void setup() {
  lcd.begin(16,2);
  
  intro();
  delay(3000);
  showcap(); 
  
  servo1.attach(10);
  Serial.begin(9600);
} //end

void servoopen(){
 servo1.write(90);
 delay(6000);
 servoclose(); 
}

void servoclose(){
 // delay(3000);
  servo1.write(0);
}

void intro() {
  lcd.setCursor(0, 0);
 
  char welcome[21]; 
  welcome[0] = 'W';
  welcome[1] = 'e';
  welcome[2] = 'l';
  welcome[3] = 'c';
  welcome[4] = 'o';
  welcome[5] = 'm';
  welcome[6] = 'e';
  welcome[7] = ' ';
  welcome[8] = 'T';
  welcome[9] = 'o';
  welcome[10] = ' ';
  welcome[11] = 'S';
  welcome[12] = 'm';
  welcome[13] = 'a';
  welcome[14] = 'r';
  welcome[15] = 't';
  welcome[16] = ' ';
  welcome[17] = 'P';
  welcome[18] = 'a';
  welcome[19] = 'r';
  welcome[20] = 'k';
  
  for (int i = 0; i < 10; i++) {
   lcd.print(welcome[i]);
   delay(200);
  } 
  
  lcd.setCursor(4,1);
  
  for (int i = 10; i< 21; i++){
    lcd.print(welcome[i]);
    delay(200);
   }

}


void showcap(){
  lcd.clear();
  lcd.setCursor(1,0);
  char available[14];

  available[0] = 'A';
  available[1] = 'v';
  available[2] = 'a';
  available[3] = 'i';
  available[4] = 'l';
  available[5] = ' ';
  available[6] = 'C';
  available[7] = 'a';
  available[8] = 'p';
  available[9] = 'a';
  available[10] = 'c';
  available[11] = 'i';
  available[12] = 't';
  available[13] = 'y';
  
 for (int i = 0; i < 14; i++){
  lcd.print(available[i]);
  delay(200);
    }
}


void loop(){

//float sensorValue;
sensorValue = analogRead(analogInPin);

Serial.print("\nsensor = " );
Serial.print(sensorValue);

if ( sensorValue > 250 ) { servoopen(); } 

lcd.setCursor(4,1);
lcd.print("CLOSED");

}

  
  
  
  
  
