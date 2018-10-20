//initialising the motor pin variables 
int MR0 = 2;
int MR1 = 3;
int ML0 = 4;
int ML1 = 5;
char flag = 0;

void setup() {
  // put your setup code here, to run once:
  //initialising the Serial communication
  Serial.begin(9600);
  Serial1.begin(9600);  //serial port 1 to read the values of the bluetooth

  //initialising the input and output pins
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(MR0, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(ML0, OUTPUT);
  pinMode(ML1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  flag = Serial1.read();
  {
    if (flag == 'U')  //forward
    {
      digitalWrite(MR0, 1);
      digitalWrite(ML0, 1);
      digitalWrite(MR1, 0);
      digitalWrite(ML1, 0);
    }

    if (flag == 'D')  //backward
    {
      digitalWrite(MR1, 1);
      digitalWrite(ML1, 1);
      digitalWrite(MR0, 0);
      digitalWrite(ML0, 0);
    }

    if (flag == 'L')  //left
    {
      digitalWrite(MR0, 0);
      digitalWrite(ML0, 1);
      digitalWrite(MR1, 0);
      digitalWrite(ML1, 0);
    }

    if (flag == 'R')  //right
    {
      digitalWrite(MR0, 1);
      digitalWrite(ML0, 0);
      digitalWrite(MR1, 0);
      digitalWrite(ML1, 0);
    }

    if (flag == 'C')  //stop
    {
      digitalWrite(MR0, 0);
      digitalWrite(ML0, 0);
      digitalWrite(MR1, 0);
      digitalWrite(ML1, 0);
    }

    Serial1.println(flag); // to debug
  }
}
