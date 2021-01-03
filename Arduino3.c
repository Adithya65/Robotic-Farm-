

int zm;
#include <Servo.h>

#include <Keypad.h>
int x;
int y;



const int ROW_NUM = 4; 
const int COLUMN_NUM = 3; 

char keys[ROW_NUM][COLUMN_NUM] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; 
byte pin_column[COLUMN_NUM] = {5, 4, 3}; 

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password = "0"; 
String input_password;
Servo servo1;        



void setup(){
 pinMode(A1,INPUT);
pinMode(13,OUTPUT);
servo1.attach(11);



Serial.begin(9600);
pinMode(1,OUTPUT);
pinMode(12,OUTPUT);

pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
input_password.reserve(32); 

pinMode(13,OUTPUT);
  pinMode(A5,INPUT);
pinMode(10,OUTPUT);
}

void loop(){
Serial.println(analogRead(A5));
zm=analogRead(A5);
if(analogRead(A5)>500)
{digitalWrite(10,HIGH);
}
else{
  digitalWrite(10,LOW);
}


char key = keypad.getKey();

if (key){
Serial.println(key);

if(key == '*') {
input_password = keypad.getKey();; 
} else if(key == '#') {
if(password == input_password) {
{ Serial.println("password is correct");


servo1.write(180);                 
delay(1000); 
servo1.write(0);
}}



else {
Serial.println("password is incorrect, try again");
    digitalWrite(13,HIGH);
    delay(1000);
  }

  input_password = ""; 
} else {
  input_password += key; 
}
}
  x = analogRead(A1);
 if( x>160)
 {
   digitalWrite(12,HIGH);   
 }
else{
  digitalWrite(12,LOW);
}   
}
