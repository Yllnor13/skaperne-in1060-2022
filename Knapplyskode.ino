int groenn = 10;
int gul = 11;
int blaa = 12;
int roed = 13;
int knapp1 = 0;
int knapp2 = 1;
int knapp3 = 3;
int knapp4 = 4;

boolean knapplys1 = false;
boolean knapplys2 = false;

void setup() {
  pinMode(groenn, OUTPUT);
}

void loop() {
  if(knapplys1==true){
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
  if(knapplys2==true){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  if(!digitalRead(knapp1) == HIGH){
    knapplys1=true;
    knapplys2=false;
    //knapplys1 = true;
  }
  
  if(!digitalRead(knapp2) == HIGH){
    knapplys1=true;
    knapplys2=false;
  }
}
