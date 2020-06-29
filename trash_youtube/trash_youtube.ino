// gonasoo 쓰레기통 만들기  20200629 수정
#include <Servo.h>      // 서보 라이브러리 사용

Servo trash;            //trash 라는 이름의 서보 선언
 
int trig = 13;          //초음파센서의 trig핀을 아두이노 13번 핀 연결
int echo = 12;          //초음파센서의 echo핀을 아두이노 12번 핀 연결

void setup() {
  // put your setup code here, to run once:
  trash.attach(2);      //아두이노의 2번 핀에서 서보모터 동작 
  Serial.begin(9600);   //디버깅을 위한 컴퓨터와 통신속도 9600 설정
  pinMode(trig, OUTPUT);//13번핀 OUTPUT 설정
  pinMode(echo, INPUT); //12번핀 INPUT 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  ///////////////초음파 센서 인식/////////////
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration/58;            //cm 환산
  Serial.println(distance);
  //////////////////////////////////////////
  if(distance <= 6){
    delay(500);
    trash.write(120);
    delay(2500);
  }
  else
  trash.write(0);
}
