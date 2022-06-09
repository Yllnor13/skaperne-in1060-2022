#include<Wire.h>

int x = 5; //verdi som blir sendt

//knapp relatert variabler
int buttonPin = 12;
int buttonState = 0;

//variablelen som holder verdien slave gir
int receivedValue = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin(); 
  pinMode(buttonPin, INPUT);
}

void loop() {
  //spør om 1 byte fra address 9 (slave arduino)
  Wire.requestFrom(9, 1);

  while (Wire.available()) { //slave kan sende mindre enn etterspurt
    receivedValue = Wire.read();
    Serial.println(receivedValue);
  }
  
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    x = 0; //dette gjør at lyset slår seg på i slave
  }else{
    if(receivedValue == 5){ //dette slår ikke på noe led i slave
      x = 5;
    }
  }
  transmission();
}

//sending av data til addressen 9 (slave arduino)
void transmission(){
  Wire.beginTransmission(9);
  Wire.write(x);
  Wire.endTransmission();
  delay(100);
}
