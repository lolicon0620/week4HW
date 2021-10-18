#include <Servo.h>  //匯入函式庫
Servo myservo;  // 建立伺服馬達控制

const int servoPin = 13;  //用常態變數設定pin腳位，與之前define方式差不多
int pos = 90; //角度初始在中間，設定為90度

const int Button1_Pin = 12, Button2_Pin = 14; //紀錄兩按鈕腳位
const int led_pin = 15;
bool btn1_Pressed = false, btn2_Pressed = false;  //紀錄兩按鈕按壓狀態

void setup() {
  Serial.begin(115200);//序列阜連線速率(鮑率)

  myservo.attach(servoPin);  // 將伺服馬達連接的GPIO pin連接伺服物件
  myservo.write(90);  //角度初始在中間，設定為90度

  pinMode(Button1_Pin, INPUT);
  pinMode(Button2_Pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {

  //Input 1
  if (digitalRead(Button1_Pin) == HIGH && btn1_Pressed == false) {
    btn1_Pressed = true;

  }
  else if (digitalRead(Button1_Pin) == LOW && btn1_Pressed == true) {
    btn1_Pressed = false;
  }

  //Input 2
  if (digitalRead(Button2_Pin) == HIGH && btn2_Pressed == false) {
    btn2_Pressed = true;

  }
  else if (digitalRead(Button2_Pin) == LOW && btn2_Pressed == true) {
    btn2_Pressed = false;
  }
  if (pos == 0 || pos == 180) {
    digitalWrite(led_pin, HIGH);
    if (btn1_Pressed && btn2_Pressed) {
      digitalWrite(led_pin, LOW);
      pos = 90;
      myservo.write(pos);
    }
    return;
  }
  if (btn1_Pressed)
    pos += 5; //角度加五度
  if (btn2_Pressed)
    pos -= 5; //角度減五度

  myservo.write(pos);
  delay(50);
}
