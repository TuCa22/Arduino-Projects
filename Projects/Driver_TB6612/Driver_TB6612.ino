    /*
  TB6612FNG-Dual-Driver
  made on 28 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

*/

#define PWM1 5
#define AIN1 10
#define AIN2 11
// #define PWM2 6
// #define BIN1 7
// #define BIN2 8

int pot;
int out;

void setup() {
  Serial.begin(9600);
  pinMode(PWM1,OUTPUT);
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  // pinMode(PWM2,OUTPUT);
  // pinMode(BIN1,OUTPUT);
  // pinMode(BIN2,OUTPUT);
  
}
 
void loop() {
  
  digitalWrite(AIN1,HIGH); //Motor A Rotate Clockwise
  digitalWrite(AIN2,LOW);
  // digitalWrite(BIN1,HIGH); //Motor B Rotate Clockwise
  // digitalWrite(BIN2,LOW);
  
  pot=analogRead(A0);
  out=map(pot,0,1023,0,255);
  analogWrite(PWM1,out); //Speed control of Motor A
  // analogWrite(PWM2,out); //Speed control of Motor B
 
}
