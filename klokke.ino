//LED variabler
int redLED = 12;
int grnLED = 11;
int ylwLED = 10;
int bluLED= 9;

//variabler for hjelp kommer knapp
int redbtn = 8;
int grnbtn = 7;
int ylwbtn = 6;
int blubtn = 5;

//variabler for trenger hjelp knappen
int redbutton = A0;
int grnbutton = A1;
int ylwbutton = A2;
int blubutton = A3;

//State for hjelp kommer knapp
int redState = 0;
int grnState = 0;
int ylwState = 0;
int bluState = 0;

//State for trenger hjelp knapp
int redHelpState = 0;
int grnHelpState = 0;
int ylwHelpState = 0;
int bluHelpState = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(grnLED, OUTPUT);
  pinMode(bluLED, OUTPUT);
  pinMode(ylwLED, OUTPUT);

  pinMode(redbtn, INPUT);
  pinMode(grnbtn, INPUT);
  pinMode(blubtn, INPUT);
  pinMode(ylwbtn, INPUT);

  pinMode(redbutton, INPUT);
  pinMode(grnbutton, INPUT);
  pinMode(blubutton, INPUT);
}

void loop() {
  redState = digitalRead(redbtn);
  grnState = digitalRead(grnbtn);
  ylwState = digitalRead(ylwbtn);
  bluState = digitalRead(blubtn);

  redHelpState = digitalRead(redbutton);
  grnHelpState = digitalRead(grnbutton);
  ylwHelpState = digitalRead(ylwbutton);
  bluHelpState = digitalRead(blubutton);
  
  help_needed();
  help_coming();
}

/*
 * metode for å svare på hjelp.
 * dette reflektere ikke hvordan det skal faktisk være.
 * dette er kun for å simpulere hvordan armbåndet reagerer.
*/
void help_needed(){
  if(redHelpState == HIGH){
    digitalWrite(redLED, HIGH);
  }
  if(grnHelpState == HIGH){
    digitalWrite(grnLED, HIGH);
  }
  if(ylwHelpState == HIGH){
    digitalWrite(ylwLED, HIGH);
  }
  if(bluHelpState == HIGH){
    digitalWrite(bluLED, HIGH);
  }
}

/*
 * metode for å si i fra at bar trenger hjelp.
 * dette reflektere ikke hvordan det skal faktisk være.
 * dette er kun for å simpulere hva armbåndet gjør når den sender at baren trenger hjelp.
*/
void help_coming(){
  if(redState == HIGH){
    digitalWrite(redLED, LOW);
  }
  if(grnState == HIGH){
    digitalWrite(grnLED, LOW);
  }
  if(ylwState == HIGH){
    digitalWrite(ylwLED, LOW);
  }
  if(bluState == HIGH){
    digitalWrite(bluLED, LOW);
  }
}
