int x;
int y;

#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
    
}

void loop() {

  
  
Serial.print( "Temp Reading = ");
Serial.println( analogRead(A1));
lcd.setCursor(0, 0);
lcd.print("Temperature");
lcd.setCursor(0, 1);
lcd.print(analogRead(A1));
delay(50);
 y=map(analogRead(A1), 0, 1023, 0, 255);
Serial.println(y);
if (y>48)
{digitalWrite(6,HIGH);
}
else
{digitalWrite(6,LOW);
}


lcd.clear();

  
Serial.print( "Moisture Reading = ");
Serial.println( analogRead(A0));
lcd.setCursor(0, 0);
lcd.print("Moisture");
lcd.setCursor(0, 1);
lcd.print(analogRead(A0));
  
  
delay(50);
Serial.println(analogRead(A0));
  
 
  if(analogRead(A0)<200)
  {
    digitalWrite(13,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    
  }
  else if((analogRead(A0)>400) &&(analogRead(A0)<580))
  { 
  
    digitalWrite(9,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
   }
else if((analogRead(A0)>580))
{
  
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(13,LOW);
 }

lcd.clear();
Serial.print( "Humidity Reading = ");
Serial.println( analogRead(A2));
lcd.setCursor(0, 0);
lcd.print("Humidity");
lcd.setCursor(0, 1);
lcd.print(analogRead(A2));
delay(50);
lcd.clear();


  
}
  



