
#include <Servo.h> 

Servo s0;
Servo s1;
Servo s2;
Servo s3;
Servo s4;

int servoPin[] = {23,25,27,29,31};
int expression;
int expressions[][8] =   {{100,90,80,90,80,0,50,50}, //neutral
                        {150,115,90,70,30,0,0,50},  //sad
                        {20,90,80,90,160,0,50,0},  //happy               
                        {80,65,80,115,100,50,0,0},//mad
                        {20,85,150,95,160,50,50,0},//interested
                        {20,105,180,75,90,50,0,50}};  //uncertain

int rgbPins[] = {45,44,46};
int rgbScale[] = {120,120,120};
                      
int count = 0;
int time;
int val;
int lastread;
Servo myservo;

void setup() 
{ 
  Serial.begin(9600);
  expression = 0;  
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(33, INPUT_PULLUP);
  s0.attach(servoPin[0]);
  s1.attach(servoPin[1]);
  s2.attach(servoPin[2]);
  s3.attach(servoPin[3]);
  s4.attach(servoPin[4]);
}

void loop() {
  Serial.println(expression);
  if(digitalRead(33)==LOW){
      if(!lastread){
        expression ++;
        lastread = 1;
         if(expression == 6
         ){    
          expression = 0;
         }
       }
  }else{
    lastread = 0;
  }
   //s0.write(5*expression);
   //allServo(90+(10*expression));
   expressionSet(expression);
   delay(50);

}

//pos should be 0-100

void expressionSet(int exp){
  s1.write(expressions[exp][1]);
  s3.write(expressions[exp][3]);
 
  delay(100); 
  s0.write(expressions[exp][0]);

  delay(100);
  s2.write(expressions[exp][2]);
  s4.write(expressions[exp][4]);

     ledWrite(expressions[exp][5],expressions[exp][6],expressions[exp][7]);
}
void allServo(int val){
  s0.write(val);
  s1.write(val);
  s2.write(val);
  s3.write(val);
  s4.write(val);
}
void eyesSet(int val){
   s2.write(val);
}
void ledWrite(int r,int g,int b){
//  analogWrite(rgbPins[0], r*rgbScale[0]/100);
//  analogWrite(rgbPins[1], g*rgbScale[1]/100);
//  analogWrite(rgbPins[2], b*rgbScale[2]/100);
  digitalWrite(rgbPins[0], r);
  digitalWrite(rgbPins[1], g);
  digitalWrite(rgbPins[2], b);
}

