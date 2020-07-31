const int trigP = 16;                       //D0 Or GPIO-16 of nodemcu
const int echoP = 5;                        //D1 Or GPIO-5 of nodemcu
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>
int D2;
int D3;
Servo myservo;                              // create servo object to control a servo
int pos = 0;                                // variable to store the servo position
LiquidCrystal_I2C lcd(0x27, 16, 2);
long duration;
int distance;

void setup()
{
  pinMode(trigP, OUTPUT);                   // Sets the trigPin as an Output
  pinMode(echoP, INPUT);                    // Sets the echoPin as an Input
  Serial.begin(9600);                       // Open serial channel at 9600 baud rate
  Wire.begin(D2,D3);
  myservo.attach(2);
  lcd.begin();
  lcd.home();
  lcd.print("Hello, NodeMCU");
}

void loop()
{
  digitalWrite(trigP, LOW);                // Makes trigPin low
  delayMicroseconds(2);                    // 2 micro second delay
  digitalWrite(trigP, HIGH);               // tigPin high
  delayMicroseconds(10);                   // trigPin high for 10 micro seconds
  digitalWrite(trigP, LOW);                // trigPin low
  duration = pulseIn(echoP, HIGH);         //Read echo pin, time in microseconds
  distance = duration * 0.034 / 2;         //Calculating actual/real distance
  Serial.print("Distance = ");             //Output distance on arduino serial monitor
  Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("distance");
  lcd.setCursor(0,7);
  lcd.print(distance);
  delay(500);
  if(distance>10
  {
    lcd.setCursor(1,0);                   // Pause for 3 seconds and start measuring distance again
    lcd.print("flood alert");
    for (pos = 0; pos <= 180; pos += 1)   // goes from 0 degrees to 180 degrees in steps of 1 degree
    {
      myservo.write(pos);                 // tell servo to go to position in variable 'pos'
      delay(15);                          // waits 15ms for the servo to reach the position
    }
    pos=0;
  }
  else
  {
    lcd.setCursor(1,0);                   //Pause for 3 seconds and start measuring distance again
    lcd.print("           ");
  }
}
