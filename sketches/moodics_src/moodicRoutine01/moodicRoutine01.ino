// This sketch is for the blue LED light-strip

#define light_pin 5
#define motor_pin 6

void setup() {
  pinMode(light_pin, OUTPUT);
  pinMode(motor_pin, OUTPUT);
}

void loop() {
  digitalWrite(light_pin, HIGH );  
  analogWrite(motor_pin, 122);
  delay(500); 
  analogWrite(motor_pin, 0 );    // off
  analogWrite(light_pin, 110);
  delay(1000);
  analogWrite(light_pin, 210);
  delay(1000);
  analogWrite(light_pin, 10);
  delay(4000);            
}
