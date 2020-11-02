#include<Servo.h>
Servo serwo;
void setup() {
  serwo.attach(3);
  // put your setup code here, to run once:

}

void loop() {
  int anal=analogRead(A0);
 int  kat=map(anal,0,1023,0,179);
  serwo.write(kat);
  delay(30);
}
