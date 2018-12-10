//declaring all the variables
//IR sensors
int IR1 = 2;
int IR2 = 3;
int IR3 = 4;
//motors
int MR0 = 6;
int MR1 = 7;
int ML0 = 8;
int ML1 = 9;

void setup() {
  // declaring the input of the IR sensors
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  //declaring the motor pins
  pinMode(MR0, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(ML0, OUTPUT);
  pinMode(ML1, OUTPUT);

}

//declaring the operation functions
void forward()
{ digitalWrite(MR0, HIGH);
  digitalWrite(MR1, LOW);
  digitalWrite(ML0, HIGH);
  digitalWrite(ML1, LOW);
}
void right()
{
  digitalWrite(MR1, LOW);
  digitalWrite(MR0, LOW);
  digitalWrite(ML1, LOW);
  digitalWrite(ML0, HIGH);
}

void left()
{ digitalWrite(MR0, HIGH);
  digitalWrite(MR1, LOW);
  digitalWrite(ML0, LOW);
  digitalWrite(ML1, LOW);
}

void wait() //to stop
{ digitalWrite(MR0, LOW);
  digitalWrite(MR1, LOW);
  digitalWrite(ML0, LOW);
  digitalWrite(ML1, LOW);
}

void loop() {
  //taking values from the IR sensors
  IR1 = digitalRead(2);
  IR2 = digitalRead(3);
  IR3 = digitalRead(4);

  // the main algorithm
  if ((IR1 == 1) && (IR2 == 0) && (IR3 == 1))
  { forward();
  }
  if ((IR1 == 0) && (IR2 == 0) && (IR3 == 1))
  { left();
  }
  if ((IR1 == 1) && (IR2 == 0) && (IR3 == 0))
  { right();
  }
  if ((IR1 == 1) && (IR2 == 1) && (IR3 == 1))
  { wait();
  }
  if ((IR1 == 1) && (IR2 == 1) && (IR3 == 0))
  { right();
  }
  if ((IR1 == 0) && (IR2 == 1) && (IR3 == 1))
  { left();
  }
  if ((IR1 == 0) && (IR2 == 1) && (IR3 == 0))
  { left();
  }
  if ((IR1 == 0) && (IR2 == 0) && (IR3 == 0))
  { wait();
  }
}
