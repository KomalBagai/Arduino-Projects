void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
 digitalWrite(23,LOW);
 digitalWrite(25,LOW);
 digitalWrite(27,LOW);
 digitalWrite(29,LOW);
 }

void loop() {
  // put your main code here, to run repeatedly:
 
int d0 = digitalRead(2);
int d1 = digitalRead(3);
int d2 = digitalRead(4);
int d3 = digitalRead(5);

 if(d0==1 && d1==0 && d2==0 && d3==0) //forward press 1
 digitalWrite(22,HIGH);
 //digitalWrite(24,HIGH);
 //digitalWrite(26,LOW);
 //digitalWrite(28,LOW); 
 if(d0==0 && d1==1 && d2==0 && d3==0) //RIGHT PRESS 2
 digitalWrite(22,HIGH);
 //digitalWrite(24,LOW);
 //digitalWrite(26,HIGH);
 //digitalWrite(28,LOW);
    
 if(d0==1 && d1==1 && d2==0 && d3==0) //LEFT PRESS 3       22        24
 digitalWrite(22,LOW);                                     //        //
 //digitalWrite(24,HIGH);                                    //        //
//digitalWrite(26,LOW);                                      //        //
//digitalWrite(28,HIGH);                                     //        //
 if(d0==0 && d1==0 && d2==1 && d3==0)//BACKWARD 4         26        28
 digitalWrite(22,LOW);
 //digitalWrite(24,LOW);
 //digitalWrite(26,HIGH);
 //digitalWrite(28,HIGH);
 delay(500);
   
}
