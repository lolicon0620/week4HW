#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 5; //馬達旋轉速度
const int btn1_pin = 16, btn2_pin = 17;
int rot=0;
//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);

void setup() {
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
  pinMode(btn1_pin,INPUT);
  pinMode(btn2_pin,INPUT);
}

void loop() {
  rot=digitalRead(btn1_pin)-digitalRead(btn2_pin);
  myStepper.step(rot);
  delay(10);
}
