// Include the required Wire library for I2C<br>
#include<Wire.h>
int x = 5;
int buttonPin = 12;
int buttonState = 0;
int receivedValue = 0;

void setup() {
  // Start the I2C Bus as Master
  Serial.begin(9600);
  Wire.begin(); 
  pinMode(buttonPin, INPUT);
}

void loop() {
  //Request 1 byte from Arduino at address 9
  Wire.requestFrom(9, 1);

  while (Wire.available()) { // slave may send less than requested
    receivedValue = Wire.read(); // receive a byte as int
    Serial.println(receivedValue);         // print the int
  }
  
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    x = 0;  
  }else{
    if(receivedValue == 5){
      x = 5;
    }
  }

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  delay(100);
}
