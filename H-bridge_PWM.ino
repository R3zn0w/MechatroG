int licznik = 0;
bool prev=0;
const int OnOff = 13;
const int inLewo = 12;
const int inPrawo = 11;
const int outLewo = 5;
const int outPrawo = 6;
void setup() { 
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(OnOff, INPUT);
pinMode(inLewo, INPUT);
pinMode(inPrawo, INPUT);
pinMode(outLewo, OUTPUT);
pinMode(outPrawo, OUTPUT);
pinMode(3, OUTPUT);
digitalWrite(outLewo, 0);
digitalWrite(outPrawo, 0);
Serial.println("Liczba uruchomien:");
}
void loop() {
if(digitalRead(OnOff) && !prev){
  prev=1;
  licznik++;
  delay(200);
  Serial.println(licznik);
}
if(digitalRead(OnOff) && prev){
  prev=0;
  delay(200);
}
if(prev){
if(digitalRead(inLewo) && !digitalRead(inPrawo)){
  digitalWrite(outLewo, 1);
  digitalWrite(outPrawo, 0);
} else if(!digitalRead(inLewo) && digitalRead(inPrawo)){
  digitalWrite(outLewo,0);
  digitalWrite(outPrawo, 1);
} else if(digitalRead(inLewo) && digitalRead(inPrawo)){
  digitalWrite(outLewo,0);
  digitalWrite(outPrawo, 0);
}
}else {
  digitalWrite(outLewo,0);
  digitalWrite(outPrawo, 0);
}
analogWrite(3, analogRead(A0)/4);
}
