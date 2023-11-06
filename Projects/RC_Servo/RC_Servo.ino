#include <Servo.h>

Servo servo;  // Khai báo đối tượng servo

void setup() {
  servo.attach(9);  // Chân 9 được sử dụng để điều khiển động cơ Servo
}

void loop() {
  servo.write(0);      // Quay động cơ Servo đến góc 0 độ
  delay(1000);         // Đợi 1 giây
  servo.write(90);     // Quay động cơ Servo đến góc 90 độ
  delay(1000);         // Đợi 1 giây
  servo.write(180);    // Quay động cơ Servo đến góc 180 độ
  delay(1000);         // Đợi 1 giây
}