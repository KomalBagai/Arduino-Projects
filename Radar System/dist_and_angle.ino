#include<Servo.h>
int echo = 11;
int trig = 10;
long duration;
int dist;
int ang = 0;

Servo rot;

// function to calculate distance of obstacle
void ultrasonic()
{

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  dist = (duration * 0.034) / 2;// calculating distance in cms
  delay(10);

}
void setup() {
  rot.attach(6);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  rot.write(0);
}

void loop() {
  for (ang = 0; ang <= 180; ang++)
  { rot.write(ang); // rotating servo to and fro
    ultrasonic();// calculating the distance using ultrasonic sensor
    if (dist <= 350 && dist >= 3)
    {
      Serial.print("obstacle detected at distance: ");
      Serial.print(dist);
      Serial.print( "cm" );
      Serial.print(" where angle is: ");
      Serial.print(ang);
      Serial.println(" degree");
      delay(100);
    }

  }
  for (ang = 180; ang >= 0; ang--)
  { rot.write(ang);
    delay(5);
    ultrasonic();
    if (dist <= 350 && dist >= 3)// min distance = 3cm and maximum distance = 350cm approx
    {
      Serial.print("obstacle detected at distance: ");
      Serial.print(dist);
      Serial.print( "cm" );
      Serial.print(" where angle is: ");
      Serial.print(ang);
      Serial.println(" degree");
      delay(100);
    }
  }
}
