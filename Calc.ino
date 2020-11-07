int a,b,krok=0;
String dzialanie;
void setup() {
  Serial.begin(9600);
  Serial.println("Kalkulator");
}
bool check(int x){
  if(abs(x)>=100){
    Serial.println("Liczba nie jest dwucyfrowa");
    krok=0;
    return true;
  }
  return false;
}
void loop() {
  if(!krok){
    krok++;
    Serial.println("Podaj 1 liczbę");
  }
  if (Serial.available()) {
    delay(100);
    while (Serial.available() > 0) {
      if(krok==1){
      krok++;
      String s=Serial.readStringUntil('\n');
      a=s.toInt();
      if(check(a)) break;
      //Serial.println(a);
      Serial.println("Podaj znak działania");
      }else if(krok==2){
      krok++;
      dzialanie=Serial.readStringUntil('\n');
      Serial.println("Podaj 2 liczbę");
      }else if(krok==3){
      krok=0;
      String s=Serial.readStringUntil('\n');
      b=s.toInt();
      if(check(b)) break;
      if(!(dzialanie=="+" || dzialanie=="-" || dzialanie=="*" || dzialanie=="/" || dzialanie=="%")){
        Serial.println("Niepoprawny znak działania!");
        krok=0;
        break;
      }
     // Serial.println(b);
      Serial.println("Wynik to");
      Serial.print(a);
      Serial.print(dzialanie);
      Serial.print(b);
      Serial.print("=");
      if(dzialanie=="+") Serial.println(a+b);
      else if(dzialanie=="-") Serial.println(a-b);
      else if(dzialanie=="*") Serial.println(a*b);
      else if(dzialanie=="/") Serial.println(a/b);
      else Serial.println(a%b);
      }
    }
  }
}
