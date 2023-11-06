const int ena = 5;
const int step = 6;
const int dir = 7;

void setup() {
    pinMode(ena, OUTPUT);
    pinMode(step, OUTPUT);
    pinMode(dir, OUTPUT);
}

void loop() {
    digitalWrite(ena, LOW);

    digitalWrite(dir, HIGH);
    for (int i = 0; i < 200; i++)
    {
        digitalWrite(step, HIGH);
        delayMicroseconds(3000);
        digitalWrite(step, LOW);
        delayMicroseconds(3000);
    }
    delay(1000);
}