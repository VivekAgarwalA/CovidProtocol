
#include <AFMotor.h>
int IRSensor = 2;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {

  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  Serial.begin(9600);
}

void loop() {
  
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 1){
    Serial.print(1);
    motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  delay(500);
  }  else



  
  {
    Serial.print(0);
     motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  

  }
  delay(1000); 
}
