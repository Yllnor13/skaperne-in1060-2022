#include <Wire.h>

int redLED = 12;
int grnLED = 11;
int ylwLED = 10;
int bluLED= 9;

int red = 0;
int blu = 1;
int grn = 2;
int ylw = 3;

int redbtn = 8;
int grnbtn = 7;
int ylwbtn = 6;
int blubtn = 5;

int redbutton = A0;
int grnbutton = A1;
int ylwbutton = A2;
int blubutton = A3;

int redState = 0;
int grnState = 0;
int ylwState = 0;
int bluState = 0;

int redHelpState = 0;
int grnHelpState = 0;
int ylwHelpState = 0;
int bluHelpState = 0;

int whichLED = 5;
int valueReceived = 5;
int sendValue = 0;

void setup() {
  Serial.begin(9600);
  
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
  pinMode(ylwbutton, INPUT);

  Wire.begin(9);

  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void receiveEvent(int bytes) {
  //Read one value from the I2C
  valueReceived = Wire.read();
  //Display the value received  
  Serial.println(valueReceived);
}

void requestEvent(){
  //Tell the master whether the led is on or not
  Wire.write(sendValue);
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

  if(valueReceived == 0){
    digitalWrite(redLED, HIGH);
  }
  if(valueReceived == 1){
    digitalWrite(grnLED, HIGH);
  }
  if(valueReceived == 2){
    digitalWrite(bluLED, HIGH);
  }
  if(valueReceived == 3){
    digitalWrite(ylwLED, HIGH);
  }
  
  help_needed();
  help_coming();
}

void help_needed(){
  if(redHelpState == HIGH){
    digitalWrite(redLED, HIGH);
    sendValue = 0;
  }
  if(grnHelpState == HIGH){
    digitalWrite(grnLED, HIGH);
    sendValue = 0;
  }
  if(ylwHelpState == HIGH){
    digitalWrite(ylwLED, HIGH);
    sendValue = 0;
  }
  if(bluHelpState == HIGH){
    digitalWrite(bluLED, HIGH);
    sendValue = 0;
  }
}

void help_coming(){
  if(redState == HIGH){
    digitalWrite(redLED, LOW);
    sendValue = 5;
  }
  if(grnState == HIGH){
    digitalWrite(grnLED, LOW);
    sendValue = 5;
  }
  if(ylwState == HIGH){
    digitalWrite(ylwLED, LOW);
    sendValue = 5;
  }
  if(bluState == HIGH){
    digitalWrite(bluLED, LOW);
    sendValue = 5;
  }
}
