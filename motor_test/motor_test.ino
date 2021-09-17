#include <Servo.h>


int servoPin0 = 9;
int servoPin1 = 10;
int servoPin2 = 11;
int servoPin3 = 6;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  
 Serial.begin(9600);
 servo1.attach(servoPin0);
 servo2.attach(servoPin1);
 servo3.attach(servoPin2);
 servo4.attach(servoPin3);

 servo1.writeMicroseconds(1500); // send "stop" signal to ESC.
 servo2.writeMicroseconds(1500); // send "stop" signal to ESC.
 servo3.writeMicroseconds(1500); // send "stop" signal to ESC.
 servo4.writeMicroseconds(1500); // send "stop" signal to ESC.

 delay(7000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
  
  Serial.println("Enter PWM signal value 1500 to 1600, 1500 to stop");
  
  while (Serial.available() == 0);
  
  int val = Serial.parseInt(); 
  
  if(val < 1500 || val > 1600)
  {
    Serial.println("not valid");
  }
  else
  {
    servo1.writeMicroseconds(val); // Send signal to ESC.
    servo2.writeMicroseconds(val); // Send signal to ESC.
    servo3.writeMicroseconds(val); // Send signal to ESC.
    servo4.writeMicroseconds(val); // Send signal to ESC.
  }
}
