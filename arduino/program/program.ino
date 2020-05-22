// Pin7 receptor
// Pin9 servo1
// Pin10 servo2

#include <Servo.h>

Servo servoMotor1;
Servo servoMotor2;

int posServo1 = 0;
int posServo2 = 0;
int channel1;

void setup() { 
  servoMotor1.attach(9);   
  servoMotor2.attach(10);
     
  pinMode(7, INPUT);
  Serial.begin(9600);     
}
void loop() {
  channel1 = pulseIn(7, HIGH);

  servoMotor1.write(posServo1);
  servoMotor2.write(posServo2);
  
  Serial.print("Channel 1:");
  Serial.println(channel1);

  if((channel1 >= 1400) && (channel1 <= 1550)){
    posServo1 = 90;
    posServo2 = 90;

    servoMotor1.write(posServo1);
    servoMotor2.write(posServo2);
  }
  else if(channel1<1400){
    for(posServo1 = 90; posServo1 < 180; posServo1 ++)  
      servoMotor1.write(posServo1);
      delay(100);
    for(posServo2 = 90; posServo2 < 180; posServo2 ++)
      servoMotor2.write(posServo2);
      delay(100);                      
  }
  else if(channel1>1550){
    for(posServo1 = 90; posServo1 > 0; posServo1 --)
      servoMotor1.write(posServo1);
      delay(100);
    for(posServo2 = 90; posServo2 > 0; posServo2 --) 
      servoMotor2.write(posServo2);
      delay(100);
  }
  delay(100);               
}
