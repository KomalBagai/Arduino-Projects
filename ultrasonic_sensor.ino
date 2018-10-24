int echo = 11;
int trig = 10;
long duration;
int dist;


void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  dist = (duration * 0.034) / 2;

  Serial.print("distance in cms= ");
  Serial.println(dist);
  delay(10);

}
