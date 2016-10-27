#include <Arduino.h>
int front = 0;
int back = 2;
int right = 1;
int left = 3;

int testSpeed = 150;
int testInt = 500;
int enA = 10;
int pinCount = 4;
int motorL[] = {48,52,44,40};
int motorR[] = {46,50,38,42};
int motorV[] = {5,4,2,3};
int motorPol[] = {1,-1,1,1};


//int j = 0;
//int k = 0;
//int motorL[] = {motorL[j],motorL[j],motorL[j],motorL[j]};
//int motorR[] = {motorR[k],motorR[k],motorR[k],motorR[k]};
//int motorV[] = {2,3,4,5};

void setup()
{
   pinMode(enA, OUTPUT);
  // set all the motor control pins to outputs
  for (int i=0; i <pinCount; i++){
      pinMode( motorL[i],OUTPUT);
      pinMode( motorR[i],OUTPUT);
      pinMode( motorV[i],OUTPUT);
  }
 
 
}
void setMotorSpeed(int i, int v)
{
  //int motor;
  //int v;
  if(v*motorPol[i]>0){
   digitalWrite(motorR[i], HIGH);
   digitalWrite(motorL[i], LOW);
  }
  if(v*motorPol[i]<0){
   digitalWrite(motorL[i], HIGH);
   digitalWrite(motorR[i], LOW);
  }
  if(v==0){
   digitalWrite(motorL[i],LOW);
   digitalWrite(motorR[i], LOW);
  }
  
   analogWrite(motorV[i], abs(v));
  
}
void demoOne()
{


  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
    for (int i=0; i <pinCount; i++){
      digitalWrite(motorL[i], HIGH);
      digitalWrite(motorR[i], LOW);
      digitalWrite(motorV[i], HIGH);
    }
 
  delay(2000);
  // now change motor directions
  for (int i=0; i <pinCount; i++){
      digitalWrite(motorL[i], LOW);
      digitalWrite(motorR[i], HIGH);
  }
  
  
  delay(2000);
  // now turn off motors
  for (int i=0; i <pinCount; i++){
      digitalWrite(motorR[i], LOW);
      digitalWrite(motorL[i], LOW);
  }
 
}
//void demoTwo()
//{
//  // this function will run the motors across the range of possible speeds
//  // note that maximum speed is determined by the motor itself and the operating voltage
//  // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
//  // by your hardware
//  // turn on motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);  
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, HIGH); 
//  // accelerate from zero to maximum speed
//  for (int i = 0; i < 256; i++)
//  {
//    analogWrite(enA, i);
//    analogWrite(enB, i);
//    delay(20);
//  } 
//  // decelerate from maximum speed to zero
//  for (int i = 255; i >= 0; --i)
//  {
//    analogWrite(enA, i);
//    analogWrite(enB, i);
//    delay(20);
//  } 
//  // now turn off motors
//  digitalWrite(in1, LOW);
//  digitalWrite(in2, LOW);  
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, LOW);  
//}

void demoThree(){
  setMotorSpeed(back, testSpeed);
  setMotorSpeed(front, -testSpeed);
  delay(testInt);
  setMotorSpeed(back, 0);
  setMotorSpeed(front, 0);
  delay(testInt);
  setMotorSpeed(back, -testSpeed);
  setMotorSpeed(front, testSpeed);
  delay(testInt);
  setMotorSpeed(back, 0);
  setMotorSpeed(front, 0);
  delay(testInt);

  setMotorSpeed(left, testSpeed);
  setMotorSpeed(right, -testSpeed);
  delay(testInt);
  setMotorSpeed(left, 0);
  setMotorSpeed(right, 0);
  delay(testInt);
  setMotorSpeed(left, -testSpeed);
  setMotorSpeed(right, testSpeed);
  delay(testInt);
  setMotorSpeed(left, 0);
  setMotorSpeed(right, 0);
  delay(testInt);

  setMotorSpeed(left, testSpeed/2);
  setMotorSpeed(right, testSpeed/2);
  setMotorSpeed(back, testSpeed/2);
  setMotorSpeed(front, testSpeed/2);
   delay(testInt);
  setMotorSpeed(left, 0);
  setMotorSpeed(right, 0);
  setMotorSpeed(back, 0);
  setMotorSpeed(front, 0);
  delay(testInt);
  setMotorSpeed(left, -testSpeed/2);
  setMotorSpeed(right, -testSpeed/2);
   setMotorSpeed(back, -testSpeed/2);
  setMotorSpeed(front, -testSpeed/2);
  delay(testInt);
  setMotorSpeed(left, 0);
  setMotorSpeed(right, 0);
  setMotorSpeed(back, 0);
  setMotorSpeed(front, 0);
  delay(testInt);
  
}
//Use to isoloate problem with PWM
void demoFour(){
    for (int i=0; i <pinCount; i++){
      digitalWrite(motorL[i], HIGH);
      digitalWrite(motorR[i], LOW);
    }
    for (int i=0; i <pinCount; i++){
      analogWrite(motorV[i], testSpeed);
      delay((i+1)*1000);    
      analogWrite(motorV[i], 0);
    }
}
//Use to isoloate problem with L channel
void demoFive(){
    for (int i=0; i <pinCount; i++){
      analogWrite(motorV[i], testSpeed);
    }
    for (int i=0; i <pinCount; i++){
      digitalWrite(motorL[i], HIGH);
      digitalWrite(motorR[i], LOW);
      delay((i+1)*1000);    
       digitalWrite(motorL[i], LOW);
      digitalWrite(motorR[i], LOW);
    }
}
//Use to isoloate problem with R channel
void demoSix(){
    for (int i=0; i <pinCount; i++){
      analogWrite(motorV[i], testSpeed);
    }
    for (int i=0; i <pinCount; i++){
      digitalWrite(motorR[i], HIGH);
      digitalWrite(motorL[i], LOW);
      delay((i+1)*1000);    
       digitalWrite(motorL[i], LOW);
      digitalWrite(motorR[i], LOW);
    }
}
void loop()
{
  digitalWrite(13, HIGH);
  demoThree();
  digitalWrite(13, LOW);
  delay(2000);
  
//  demoTwo();
//  delay(1000);
}
