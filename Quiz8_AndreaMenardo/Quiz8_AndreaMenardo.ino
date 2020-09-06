//call-in the servo library
#include <Servo.h>
Servo MOTOR; 

//list all constants
const int POT1 = A1; //potentiometer 0 controls rotation
const int POT0 = A0; //potentiometer 1 controls speed

//list all variables
int POT1Value;
int POT0Value;
int angleMIN;
int angleMAX;
int deltaAngle;
int velocity;


void setup() 
{
  MOTOR.attach(9);
  
  angleMIN = 0;
  angleMAX = angleMIN+deltaAngle;
  
  Serial.begin(9600);
}


void loop()
{
   POT1Value = analogRead(POT1);
   Serial.print("POT1 Value: ");
   Serial.print(POT1Value);

   deltaAngle = map(POT1Value, 0, 1023, 0, 180);
   Serial.print(" - Delta Angle: ");
   Serial.print(deltaAngle);
   Serial.print("° Degrees");
   
   POT0Value = analogRead(POT0);
   Serial.print(" - POT0 Value: ");
   Serial.print(POT0Value);

   velocity = map(POT0Value, 0, 1023, 1500, 500);
   Serial.print(" - Velocity: ");
   Serial.print(velocity);
   Serial.print("ms");
 
   Serial.print(" - Angle MIN: ");
   Serial.print(angleMIN);
   MOTOR.write(angleMIN);

   delay(velocity);
   
   angleMAX = angleMIN+deltaAngle;
   Serial.print(" - Angle MAX: ");
   Serial.println(angleMAX);
   MOTOR.write(angleMAX);
   
   delay(velocity);
}
