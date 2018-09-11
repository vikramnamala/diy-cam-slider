#define EN        8

//Direction pin
#define X_DIR     5
#define Y_DIR     6
#define Z_DIR     7

//Step pin
#define X_STP     2
#define Y_STP     3
#define Z_STP     4


//DRV8825
int delayTime=30; //Delay between each pause (uS)
int stps=6400;// Steps to move


void step(boolean dir, byte dirPin, byte stepperPin, int steps)

{

  digitalWrite(dirPin, dir);

  delay(100);

  for (int i = 0; i < steps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(delayTime);

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(delayTime);

  }

}

void setup(){

  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);

  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);

  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);

  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);

}

void loop(){

  step(false, X_DIR, X_STP, stps); //X, Clockwise
  step(false, Y_DIR, Y_STP, stps); //Y, Clockwise
  step(false, Z_DIR, Z_STP, stps); //Z, Clockwise

  delay(100);

  step(true, X_DIR, X_STP, stps); //X, Counterclockwise
  step(true, Y_DIR, Y_STP, stps); //Y, Counterclockwise
  step(true, Z_DIR, Z_STP, stps); //X, Counterclockwise

  delay(100);

}
