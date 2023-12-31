#include <LiquidCrystal.h>
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);
int trig=13;
int echo=11;
float time;
float dist;
void setup()
{
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
LCD.begin(16,2);
LCD.setCursor(0,0);
LCD.print("Object Distance:");
}
void loop()
{
digitalWrite(trig, LOW);
delayMicroseconds(1000);
digitalWrite(trig, HIGH);
delayMicroseconds(30);
digitalWrite(trig, LOW);
delayMicroseconds(10);
time = pulseIn(echo, HIGH);
dist= time*0.0346903/2; // conversion into centimetre
LCD.setCursor(0,1);
LCD.print(" ");
LCD.setCursor(0,1);
LCD.print(dist);
LCD.print(" cm");
delay(250);
}