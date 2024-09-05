#include <Servo.h>

// 스텝 모터 핀 설정
const int steppin = 11;
const int dirpin = 10;
const int switch1 = 13;
const int limit1 = 12;
const int startButtonPin = 2;  // 시작 버튼이 연결된 핀

int smode = 0;
float where = 0;
bool startSequence = false;

// 서보 모터 설정
Servo servos[6];
const int servoPins[6] = {3, 4, 5, 6, 7, 8};

// 함수 선언
void moveStepperMotor();
void moveServoMotors(String brailleSequence);

void setup() {
  Serial.begin(9600);  // 시리얼 통신 시작
  
  // 스텝 모터 핀 설정
  pinMode(steppin, OUTPUT);
  pinMode(dirpin, OUTPUT);
  pinMode(limit1, INPUT_PULLUP);
  pinMode(switch1, INPUT_PULLUP);
  pinMode(startButtonPin, INPUT_PULLUP);  // 시작 버튼 핀을 입력으로 설정

  // 서보 모터 핀 설정 및 중립 위치로 초기화
  for (int i = 0; i < 6; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(90);
  }

  Serial.println("Press the start button to begin sequence."); // 안내 메시지
}

void loop() {
  int Sw1 = digitalRead(switch1);  // 스위치 상태 읽기
  int limSw1 = digitalRead(limit1);  // 리미트 스위치 상태 읽기
  int startButtonState = digitalRead(startButtonPin);  // 시작 버튼 상태 읽기
  
  // 시작 버튼이 눌렸을 때 시퀀스 시작
  if (startButtonState == LOW) {  // 버튼이 눌리면 LOW 신호가 입력됨
    startSequence = true;
    delay(2500);  // 2.5초 대기
  }

  // 시퀀스가 시작된 경우
  if (startSequence) {
    for (int i = 0; i < 11; i++) {  // 스텝 모터가 11번 동작
      moveStepperMotor();  // 스텝 모터 움직이기

      // 서보 모터를 라즈베리파이에서 받은 점자 정보로 움직임
      if (Serial.available() > 0) {
        String brailleSequence = Serial.readStringUntil('\n');  // 점자 정보 수신
        moveServoMotors(brailleSequence);  // 서보 모터 제어
      }

      delay(2700);  // 2.7초 대기
    }
  }

  // 스위치가 눌렸을 때 (Sw1 == 0)
  if (Sw1 == 0) {
    smode = 1;
  }

  if (smode == 1) {
    digitalWrite(dirpin, HIGH);  // 스텝 모터가 역방향으로 동작
    digitalWrite(steppin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(steppin, LOW);
    delayMicroseconds(1000);

    if (limSw1 == 0) {  // 리미트 스위치가 눌리면
      smode = 0;  // 모드 초기화
      where = 0;  // 위치 초기화
    }
  }
}

// 스텝 모터 움직이기 함수
void moveStepperMotor() {
  if (where < 52 * 10) {  // 일정 스텝 거리만큼 이동
    digitalWrite(dirpin, LOW);  // 방향 설정
    for (int x = 0; x < 52; x++) {  // 52 스텝만큼 이동
      digitalWrite(steppin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin, LOW);
      delayMicroseconds(1000);
      where += 1;  // 현재 위치 증가
    }
  }
}

// 서보 모터 움직이기 함수
void moveServoMotors(String brailleSequence) {
  for (int i = 0; i < 6; i++) {
    if (brailleSequence.charAt(i) == '0') {
      servos[i].write(58);  // -32도
    } else if (brailleSequence.charAt(i) == '1') {
      servos[i].write(122);  // +32도
    }
  }

  delay(1000);  // 1초 대기

  // 모든 서보 모터를 중립 위치로 복귀
  for (int i = 0; i < 6; i++) {
    servos[i].write(90);
  }

  delay(1800);  // 다음 시퀀스로 넘어가기 전 잠시 대기
}
