//Example 02: How to move a servo
//www.malapraxis.es
#include <Servo.h>
 
int servoPin = 2; // pin2 DIGITAL OUT
const int button = 7; // pin7 DIGITAL IN

//
int val = 0; 
int old_val = 0;
int state = 1; //we set to 1 to avoid the "first loop" 
int angle = 0; // degrees. 
int maxDegrees = 120;


//Declares
Servo servo;

void setup()
{
    servo.attach(servoPin); //servo is connected to pin 2 as an output
    pinMode(button,INPUT); //Button is connected to pin 7 as an input
    servo.write(1);
    delay(1);
}
void loop()
{
   val = digitalRead(button); //We read the button value, only 2 states: HIGH (1) or LOW (0)
   
   
   if ((val == LOW) && (old_val == LOW))
   {
      state = 1 - state;
   }
   if( state == 1)
   {
    
      positiveRotateServo();
      negativeRotateServo();   
     
   }
   else
   {
     state --;
   }
   
   
} 

void positiveRotateServo ()
{
   // we want to emulate a "push" button. So positive rotate must 
   // be quick, that's the explanation about delay(1)
   // scan from 0 to N degrees
      for(angle = 0; angle < maxDegrees; angle++)
      {
         servo.write(angle);
         delay(1);
      }
}

void negativeRotateServo()
{
   for(angle = maxDegrees; angle > 0; angle--)
     {
        servo.write(angle);
        delay(15);
      }
}
