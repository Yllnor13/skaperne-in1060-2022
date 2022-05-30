int blaalys = 12;
int groonlys = 11;
int roodlys = 10;
int gullys = 9;

int blaaknapp = 8;
int groonknapp = 7;
int roodknapp = 6;
int gulknapp = 5;

int blaaState = 0;
int groonState = 0;
int roodState = 0;
int gulState = 0;

void setup() {
  pinMode(blaalys, OUTPUT);
  pinMode(groonlys, OUTPUT);
  pinMode(roodlys, OUTPUT);
  pinMode(gullys, OUTPUT);
  
  pinMode(blaaknapp, INPUT);
  pinMode(groonknapp, INPUT);
  pinMode(roodknapp, INPUT);
  pinMode(gulknapp, INPUT);

  digitalWrite(blaalys, HIGH);
  digitalWrite(groonlys, HIGH);
  digitalWrite(roodlys, HIGH);
  digitalWrite(gullys, HIGH);
}

void loop() {
  blaaState = digitalRead(blaaknapp);
  groonState = digitalRead(groonknapp);
  roodState = digitalRead(roodknapp);
  gulState = digitalRead(gulknapp);

  if(blaaState == HIGH){
    digitalWrite(blaalys, LOW);
  }
  if(groonState == HIGH){
    digitalWrite(groonlys, LOW);
  }
  if(roodState == HIGH){
    digitalWrite(roodlys, LOW);
  }
  if(gulState == HIGH){
    digitalWrite(gullys, LOW);
  }
}
