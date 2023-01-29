motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
   
  }
  
}
//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define lefts A0
#define Center A1
#define rights A2


//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //Setting the motor speed
  motor1.setSpeed(90);
  motor2.setSpeed(90);
  motor3.setSpeed(90);
  motor4.setSpeed(90);
  //Declaring PIN input types
  pinMode(lefts, INPUT);
  pinMode(rights, INPUT);
  pinMode(Center, INPUT);
  //Begin serial communication

  
}

void loop(){
  //Printing values of the sensors to the serial monitor
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));
  Serial.println(analogRead(Center));
  
  //line detected by both
  if(!analogRead(lefts)<=250 && !analogRead(rights)>=250 && analogRead(Center)>=250) {
    //Forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  //line detected by left sensor
  else if(!analogRead(lefts)<=250 && analogRead(rights)>=250 && analogRead(Center)>=250){
    //turn left
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
      delay(100);
      
    
  }
  else if(!analogRead(lefts)>=250 && analogRead(rights)>=250 && !analogRead(Center)>=250){
    //turn left
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
      delay(100);
  }
  //line detected by right sensor
  else if(analogRead(lefts)>=250 && !analogRead(rights)>=250 && !analogRead(Center)>=250){
    //turn right
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
      delay(100);
   
  }
   else if(analogRead(lefts)>=250 && !analogRead(rights)>=250 && analogRead(Center)>=250){
    //turn right
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
      delay(100);
   
  }
  //line detected by none
  else if(analogRead(lefts)>=250 && analogRead(rights)>=250 &&analogRead(Center)>=250){
    //stop
