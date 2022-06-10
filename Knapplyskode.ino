int button = 11;
int buttonState = 0;
int LED = 12;

void setup() {
  pinMode(button, INPUT);
  buttonState = digitalRead(button);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(buttonState == HIGH){
    /*
    her så skal knappen sende signal til armbaands arduinoen om at den skal slaa paa lyset
    siden vi ikke har noen maate aa sende signal paa, saa forblir denne if setningen tom.
    */
  }
}
