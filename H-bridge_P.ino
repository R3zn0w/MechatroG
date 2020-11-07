float czas, odl, e, kp, zad, ster;
const int OnOff = 13;
const int echo = 12;
const int trig = 11;
const int outLewo = 5;
const int outPrawo = 6;
void setup() { 
  zad=10.0;
  kp=15.0;
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);
pinMode(outLewo, OUTPUT);
pinMode(outPrawo, OUTPUT);
pinMode(3, OUTPUT);
}
void loop() { 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  czas = pulseIn(echo, HIGH);
  odl = 0.017 * czas;  
  Serial.println(ster);
  
e=zad-odl;
ster=e*kp;

if(e>=0){
  digitalWrite(outLewo, 1);
  digitalWrite(outPrawo, 0);
} else if(e<0){
  digitalWrite(outLewo,0);
  digitalWrite(outPrawo, 1);
} else{
  digitalWrite(outLewo,0);
  digitalWrite(outPrawo, 0);
}
analogWrite(3, min(abs(ster),255));
}
