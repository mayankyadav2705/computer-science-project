int trigPin = 9;
int echoiPin = 8;
int trigPin1 = 11;
int echoiPin1 = 10;
int e =0;
float pingTime; // ping time required to travel from sensor to object
float objectDistance; // distance of the object from the sensor
float pingTime1; // ping time required to travel from sensor to object
float objectDistance1; // distance of the object from the sensor
float speedOfSound = 341; // speed of sound in m/s
#include <Servo.h>
Servo servo_1;
Servo servo;
void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(9, OUTPUT); // set the trig pin as an output
pinMode(8, INPUT); // set the echo pin as an input
pinMode(11, OUTPUT); // set the trig pin as an output    
pinMode(10, INPUT); // set the echo pin as an input
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);    
Serial.begin(9600); // start the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(2,LOW);
digitalWrite(9, LOW); // set trigPin as low
delayMicroseconds (2); // delay for settling down the signal
digitalWrite(9, HIGH); // set the trigPin as high
delayMicroseconds (10); // delay in high state   
digitalWrite(9, LOW); // set trigPin as low again
pingTime=pulseIn(8,HIGH);
delayMicroseconds (10); // delay in high state 
digitalWrite(11, LOW); // set trigPin as low
delayMicroseconds (2); // delay for settling down the signal
digitalWrite(11, HIGH); // set the trigPin as high
delayMicroseconds (10); // delay in high state 
digitalWrite(11, LOW); // set trigPin as low again
pingTime1 = pulseIn (10, HIGH); // measuring the pingTime on echoPin
objectDistance = pingTime*0.0341/2; // Object to sensor distance in cm.
objectDistance1 = pingTime1*0.0341/2; // Object to sensor distance in cm.
Serial.println(objectDistance);
Serial.println(objectDistance1);
if(objectDistance <50 and objectDistance1>50)
{
  Serial.println("o");
  delay(500);
  delayMicroseconds (10); // delay in high state 
digitalWrite(11, LOW); // set trigPin as low
delayMicroseconds (2); // delay for settling down the signal
digitalWrite(11, HIGH); // set the trigPin as high
delayMicroseconds (10); // delay in high state 
digitalWrite(11, LOW); // set trigPin as low again
pingTime1 = pulseIn (10, HIGH); // measuring the pingTime on echoPin
objectDistance1 = pingTime1*0.0341/2; // Object to sensor distance in cm.
  if(objectDistance1 <50 )
  {
    Serial.println("o in");
 
   e=e+1;
  }
}
if(objectDistance1 <50 and objectDistance>50)
  {
    
    Serial.println("u");
    delay(500);
    digitalWrite(9, LOW); // set trigPin as low
delayMicroseconds (2); // delay for settling down the signal
digitalWrite(9, HIGH); // set the trigPin as high
delayMicroseconds (10); // delay in high state   
digitalWrite(9, LOW); // set trigPin as low again
pingTime=pulseIn(8,HIGH);
objectDistance = pingTime*0.0341/2;
    if(objectDistance <50)
    {
      Serial.println("u in");
      
e=e-1;
    }
    
  }
Serial.println(e);
if(e<=0)
{
  digitalWrite(4,LOW);
  servo_1.write(0);
  servo.write(90);
}
if(e>0)
{
  digitalWrite(4,HIGH);
  servo_1.write(90);
  servo.write(0);
}
  
}
