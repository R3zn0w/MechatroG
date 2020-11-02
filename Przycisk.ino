void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
pinMode(3, INPUT);
pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(4,digitalRead(3));
  // put your main code here, to run repeatedly:

}
