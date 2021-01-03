#include <LiquidCrystal.h>
#include <Servo.h>
#include <EEPROM.h>
int v1;
int v2;
int angle,a1[100],a2[100];
int i=0;
int j=0;


Servo myservo1; 
Servo myservo2;
int switch1;


int potpin1 = A0; 
int potpin2 = A1;

int val1=0; 
int val2=0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void write_angle_lcd1(int val1){
	
	lcd.setCursor(0, 0);
  lcd.print("SERVO 1:");
  lcd.setCursor(8, 0);
	lcd.print(val1);
  delay(10);
  	
}
void write_angle_lcd2(int val2){

lcd.setCursor(0,1);
lcd.print("SERVO 2:");
lcd.setCursor(8,1);
lcd.print(val2);


}

void setup() {

lcd.begin(16, 2);


myservo1.attach(9); 
myservo2.attach(10);
pinMode(8, INPUT); 
pinMode(13,INPUT);


Serial.begin(9600);
}


void loop() {
delay(10);   
if((digitalRead(8)==HIGH) && (digitalRead(13)==LOW))
{      

myservo1.write(100);
myservo2.write(130);

delay(500);
myservo1.write(0);

myservo2.write(0);
delay(500);

} 
if(digitalRead(8)==LOW && digitalRead(13)==LOW)
{ delay(10);
lcd.clear();
delay(10);
v1 = analogRead(potpin1); 
val1 = map(v1, 0, 1024, 0, 180);
myservo1.write(val1); 
write_angle_lcd1(val1);
v2 = analogRead(potpin2); 
val2 = map(v2, 0, 1024, 0, 180);
myservo2.write(val2);
write_angle_lcd2(val2);
Serial.println(val2);

  
 }
if ((digitalRead(8)==LOW )&& (digitalRead(13)==HIGH))
for (i=0;i<100;i++)
{ delay(10);
lcd.clear();
delay(10);
v1 = analogRead(potpin1); 
val1 = map(v1, 0, 1024, 0, 180);
myservo1.write(val1); 
write_angle_lcd1(val1);
a1[i]=val1;//recording

v2 = analogRead(potpin2); 
val2 = map(v2, 0, 1024, 0, 180);

myservo2.write(val2);
write_angle_lcd2(val2);
a2[i]=val2;//recording 

}
}
 
