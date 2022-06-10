int button = 11;
int buttonState = 0;
int LED = 12;
bool LEDlys = false;

void setup() {
  pinMode(button, INPUT);
  buttonState = digitalRead(button);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(buttonState == HIGH){
    //her saa skal lyset lyse naar man trykker paa knappen, og saa slaar lyset seg av naar man trykker det igjen
    LEDlys = !LEDlys;
    delay(500);
  }
  if(LEDlys){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
