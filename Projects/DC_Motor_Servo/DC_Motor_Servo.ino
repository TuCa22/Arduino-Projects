#include <TimerOne.h>
double T, xung;
double tocdo, tocdodat;
double E, E1, E2;
double a, b, g, kp, ki, kd;
double Output, LastOutput;
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  tocdodat = 200; tocdo = 0;
  E = 0; E1 = 0; E2 = 0;
  Output = 0; LastOutput = 0;
  T = 0.01;
  kp = 5; ki = 0; kd = 0;
  Serial.begin(9600);
  attachInterrupt(0, demxung, FALLING);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(pid);
}
void loop()
{
  for (int i = 1; i < 234; i++)
  {
    digitalWrite(10, HIGH);
    delayMicroseconds(500);
    digitalWrite(11, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
  Serial.print("Toc do: ");
  Serial.println(tocdo);

}
void demxung()
{
  if (digitalRead(8) == LOW)
    xung++;
  else
    xung--;
}
void pid()
{
  tocdo = (xung/280)*(1/T)*60;
  xung = 0;
  E = tocdodat - tocdo;
  a = 2*T*kp + ki*T*T +2*kd;
  b = ki*T*T - 4*kd - 2*T*kp;
  g = 2*kd;
  Output = (a*E + b*E1 +g*E2 + 2*T*LastOutput) / (2*T);
  LastOutput = Output;
  E2 = E1;
  E1 = E;
  if (Output > 255)
    Output = 255;
  if (Output <0)
    Output = 0;
  if (Output >0)
  {
    analogWrite(5, Output);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else
  {
    analogWrite(5, 0);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}