//varuabler for lys
int blaalys = 12;
int groonlys = 11;
int roodlys = 10;
int gullys = 9;

//variabler for svar knappene for hjelp
int svar_blaa = 8;
int svar_groon = 7;
int svar_rood = 6;
int svar_gul = 5;

//variabler for baren sender hjelp
int hjelp_blaa = A0;
int hjelp_groon = A1;
int hjelp_rood = A2;
int hjelp_gul = A3;

//states for svar til hjelp
int kommer_blaa = 0;
int kommer_groon = 0;
int kommer_rood = 0;
int kommer_gul = 0;

//states for trenger hjelp
int send_blaa = 0;
int send_groon = 0;
int send_rood = 0;
int send_gul = 0;

void setup() {
  pinMode(blaalys, OUTPUT);
  pinMode(groonlys, OUTPUT);
  pinMode(roodlys, OUTPUT);
  pinMode(gullys, OUTPUT);
  
  pinMode(svar_blaa, INPUT);
  pinMode(svar_groon, INPUT);
  pinMode(svar_rood, INPUT);
  pinMode(svar_gul, INPUT);

  pinMode(hjelp_blaa, INPUT);
  pinMode(hjelp_groon, INPUT);
  pinMode(hjelp_rood, INPUT);
  pinMode(hjelp_gul, INPUT);

  digitalWrite(blaalys, HIGH);
  digitalWrite(groonlys, HIGH);
  digitalWrite(roodlys, HIGH);
  digitalWrite(gullys, HIGH);
}

void loop() {
  kommer_blaa = digitalRead(svar_blaa);
  kommer_groon = digitalRead(svar_groon);
  kommer_rood = digitalRead(svar_rood);
  kommer_gul = digitalRead(svar_gul);
  
  send_blaa = digitalRead(hjelp_blaa);
  send_groon = digitalRead(hjelp_groon);
  send_rood = digitalRead(hjelp_rood);
  send_gul = digitalRead(hjelp_gul);
  
  hjelpkommer();
  sendhjelp();
}

/*
 * metode for å svare på hjelp.
 * dette reflektere ikke hvordan det skal faktisk være.
 * dette er kun for å simpulere hvordan armbåndet reagerer.
*/
void hjelpkommer(){
   if(kommer_blaa == HIGH){
    digitalWrite(blaalys, LOW);
  }
  if(kommer_groon == HIGH){
    digitalWrite(groonlys, LOW);
  }
  if(kommer_rood == HIGH){
    digitalWrite(roodlys, LOW);
  }
  if(kommer_gul == HIGH){
    digitalWrite(gullys, LOW);
  }
}

/*
 * metode for å si i fra at bar trenger hjelp.
 * dette reflektere ikke hvordan det skal faktisk være.
 * dette er kun for å simpulere hva armbåndet gjør når den sender at baren trenger hjelp.
*/
void sendhjelp(){
  if(send_blaa == HIGH){
    digitalWrite(blaalys, HIGH);
  }
  if(send_groon == HIGH){
    digitalWrite(groonlys, HIGH);
  }
  if(send_rood == HIGH){
    digitalWrite(roodlys, HIGH);
  }
  if(send_gul == HIGH){
    digitalWrite(gullys, HIGH);
  }
}
