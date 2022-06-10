//variabler for komponenter
int button = 11;
int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  buttonState = digitalRead(button);
}

void loop() {
  if(buttonState == HIGH){
    /*
    her så skal knappen sende signal til armbaands arduinoen om at den skal slaa paa lyset
    siden vi ikke har noen maate aa sende signal paa, saa forblir denne if setningen tom.
    */
  }
}
