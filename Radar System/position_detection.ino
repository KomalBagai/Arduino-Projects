#include<Servo.h>
#include<math.h>
int echo = 11;
int trig = 10;
long duration;
int dist;
int ang = 0;
int x, y;
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
  dist = (duration * 0.034) / 2; // calculating distance in cms
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

    ultrasonic();
    if (dist <= 3)
    {
      x = dist * cos((3.14 / 180) * ang);// calculating x coordinate
      y = dist * sin((3.14 / 180) * ang);// calculating y coordinate

      // priting the output
      Serial.print("x=");
      Serial.print( x );
      Serial.print(" and y= ");
      Serial.println(y);
      delay(100);
    }

  }
  for (ang = 180; ang >= 0; ang--)
  { rot.write(ang);
    delay(5);
    ultrasonic();
    if (dist <= 25 && dist >= 3) //
    {
      x = dist * cos((3.14 / 180) * ang);// calculating x coordinate
      y = dist * sin((3.14 / 180) * ang);// calculating y coordinate

      // priting the output
      Serial.print("touch detected at ");
      Serial.print("x=");
      Serial.print( x );
      Serial.print(" and y= ");
      Serial.println(y);
      delay(100);
    }
  }
}
