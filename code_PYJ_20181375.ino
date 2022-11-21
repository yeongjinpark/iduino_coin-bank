#include <Servo.h>             //서브모터 사용을 위한 라이브러리

int analog_out_pin = 3;         //LED D3번핀에 연결
int servo_pin = 4;               // 서브모터 D4번핀에 연결
Servo my_servo;                  //  서브모터 사용을 위한 클래스 객체선언 


void setup() {
  my_servo.attach(servo_pin);            //servo_pin(D4번핀)핀을 서브모터 제어에 사용
  Serial.begin(9600);   
}

void loop() {
  int adc_servo = analogRead(A0); //A0에서 ADC한 값을 adc_servo로 선언
  int adc = analogRead(A1); // A1에서 ADC한 값: 0~1023

   int servo_ang = map(adc_servo, 0, 1023 , 0, 180); //map함수: adc_servo값을 0~1023으로 입력하면 servo_ang값을 0~180으로 출력
   Serial.println(servo_ang);   

  int adc2 = adc / 4;  // A1에서 ADC한 값을 4로 나눔-> 0~255;
  Serial.println(adc2);       
  
  analogWrite(analog_out_pin, adc2);  //A1에서 4로 나눈값을 Writr함수에 입력시키고 anlog_out_pin(D3번핀)으로 출력

  if(servo_ang< 90){            //servo_ang값이 90 이하인 경우
    servo_ang=90;               //servo_ang값을 90으로 통일
    my_servo.write(servo_ang);  //servo_ang값에따라 모터가 동작수행
  }
  else{                        //servo_ang값이 90 이상인 경우
    servo_ang=180;             //servo_ang값을 180으로 통일
    my_servo.write(servo_ang);  //servo_ang값에따라 모터가 동작수행
  }
    delay(100);  //모터가 물리적으로 움직이는 동안 걸리는 시간을 고려하여 딜레이 추가 
}
