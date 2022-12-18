#include <SoftwareSerial.h>
SoftwareSerial BLU(0,1);

int red_light_pin= 13;
int green_light_pin = 12;
int blue_light_pin = 8;
int r=160,g=150,b=25;


void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
//   RGB_color(255, 0, 0); // Red
//   delay(1000);
//   RGB_color(0, 255, 0); // Green
//   delay(1000);
//   RGB_color(0, 0, 255); // Blue
//   delay(1000);
  if(Serial.available()>'0'){
    r=Serial.read()- 48;
    g=Serial.read()-48;
    b=Serial.read()-48;
  
  
  
  
  if(r<=255&& g<=255 && b<=255){
  
  RGB_color(r,g,b); // Raspberry
//  delay(1000);
  }
  else{
  
  digitalWrite(red_light_pin,LOW);
  digitalWrite(green_light_pin,LOW);
  digitalWrite(blue_light_pin, LOW);
  
//  delay(1000);
  }
  }
  
  
  /*RGB_color(0, 255, 255); // Cyan
  delay(1000);
  RGB_color(255, 0, 255); // Magenta
  delay(1000);
  RGB_color(255, 255, 0); // Yellow
  delay(1000);
  RGB_color(255, 255, 255); // White
  delay(1000);*/
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
