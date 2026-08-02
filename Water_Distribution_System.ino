Program: 
#include <LiquidCrystal.h> 
LiquidCrystal lcd(13,12,11,10,9,8); 
#include <SoftwareSerial.h> 
SoftwareSerial mySerial(4,3); 
int X; 
int Y; 
float TIME = 0; 
float FREQUENCY = 0; 
float WATER = 0; 
float TOTAL = 0; 
float LS = 0; 
const int input = 2; 
#define sol1 7 
#define sol2 6 
#define float_sw1 A1 
#define float_sw2 A2 
#define sensorPin A0 
int turbidity,count=0; 
int sensorValue; 
void send_data() 
{ 
mySerial.print("Turbidity:"); 
mySerial.print(turbidity); 
mySerial.print('\n'); 
delay(300); 
mySerial.print("Liters:"); 
mySerial.print(TOTAL); 
mySerial.print('\n'); 
delay(300); 
} 
void setup() 
{ 
Serial.begin(9600); 
mySerial.begin(9600); 
lcd.begin(16, 2); 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("IOT Based Water"); 
lcd.setCursor(0,1); 
lcd.print("Dist - System  "); 
delay(2000); 
pinMode(input,INPUT); 
pinMode(sol1,OUTPUT); 
pinMode(sol2,OUTPUT); 
pinMode(float_sw1,INPUT_PULLUP); 
pinMode(float_sw2,INPUT_PULLUP); 
digitalWrite(sol1,HIGH); 
digitalWrite(sol2,HIGH); 
} 
void loop() 
{ 
sensorValue = analogRead(sensorPin); 
turbidity = map(sensorValue, 0, 750, 100, 0); 
Serial.print("Turbidity:"); 
Serial.println(turbidity); 
lcd.setCursor(11,0); 
lcd.print("T:"); 
lcd.print(turbidity); 
delay(500); 
if(!digitalRead(float_sw1)) 
{ 
digitalWrite(sol1,LOW); 
delay(200); 
} 
if(digitalRead(float_sw1)) 
{ 
digitalWrite(sol1,HIGH); 
delay(200); 
} 
if(!digitalRead(float_sw2)) 
{ 
digitalWrite(sol2,LOW); 
delay(200); 
} 
if(digitalRead(float_sw2)) 
{ 
digitalWrite(sol2,HIGH); 
delay(200); 
} 
X = pulseIn(input, HIGH); 
Y = pulseIn(input, LOW); 
TIME = X + Y; 
FREQUENCY = 1000000/TIME; 
WATER = FREQUENCY/7.5; 
LS = WATER/60; 
if(FREQUENCY >= 0) 
{ 
if(isinf(FREQUENCY)) 
{ 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("VOL. :0.00"); 
lcd.setCursor(0,1); 
lcd.print("TOTAL:"); 
lcd.print( TOTAL); 
lcd.print(" L"); 
} 
else 
{ 
TOTAL = TOTAL + LS; 
Serial.println(FREQUENCY); 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("VOL.: "); 
lcd.print(WATER); 
lcd.print(" L/M"); 
lcd.setCursor(0,1); 
lcd.print("TOTAL:"); 
lcd.print( TOTAL); 
lcd.print(" L"); 
} 
} 
delay(500); 
count=count+1; 
if(count>=10) 
{ 
count=0; 
send_data(); 
} 
}
