//speed of motors betwen 0 and 255, if you like you can change it
int pwm_speedA = 255;
int pwm_speedB = 240;
char command;

void setup() {
  Serial.begin(9600);
  //pins for motor controller
  pinMode(8, OUTPUT);//1
  pinMode(7, OUTPUT);//2
  pinMode(5, OUTPUT);//3
  pinMode(4, OUTPUT);//4
  pinMode(3, OUTPUT);//en B
  pinMode(9, OUTPUT);// en A

}

void loop() {

  if(Serial.available() > 0){
    command = Serial.read();
    motors_stop();
    switch(command){
      case 'F':
      forward();
      break;
      case 'B':
      backward();
      break;
      case 'L':
      left();
      break;
      case 'R':
      right();
      break;
    }
  }

}

// function for driving straight
void forward(){
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  digitalWrite(5, LOW);
  digitalWrite(4, LOW);

  analogWrite(9, pwm_speedA);
  analogWrite(3, pwm_speedB);
}

//function for reversing
void backward(){
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);

  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);

  analogWrite(9, pwm_speedA);
  analogWrite(3, pwm_speedB);
}

//function for turning left
void left(){
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);

  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);

  analogWrite(3, 0);
  analogWrite(9, pwm_speedA);
}

//function for turning right
void right(){
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  digitalWrite(5, LOW);
  digitalWrite(4, LOW);

  analogWrite(3, pwm_speedB);
  analogWrite(9, 0);
}

//function for stopping motors
void motors_stop(){
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);

  digitalWrite(5,LOW);
  digitalWrite(4, LOW);

  analogWrite(9, 0);
  analogWrite(3, 0);
}
