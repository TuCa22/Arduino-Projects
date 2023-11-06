char STP=6;
void setup()
{
  pinMode(STP, OUTPUT);
}

  void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(STP, HIGH);
  delayMicroseconds (500);
  digitalWrite(STP, LOW);
  delayMicroseconds (500);
}