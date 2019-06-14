#include <Servo.h>
Servo sv1;
Servo sv2;
Servo sv3; 
Servo sv4;

int inf_1 = 12;
int inf_2 = 13;

int pos1 = 0;
int pos2 = 0;

void setup() {
  Serial.begin(9600);
  
  sv1.attach(4);
  sv2.attach(5);
  sv3.attach(6);
  sv4.attach(7);
  sv1.write(90);
  sv2.write(90);
  sv3.write(90);
  sv4.write(90);

  pos1 = 0;
  pos2 = 0;

  pinMode(inf_1,INPUT);
  pinMode(inf_2,INPUT);
}

void loop() {
  if(digitalRead(inf_1) == LOW){
    Serial.println("1번 적외선 감지");
    if(pos1==0){
      /*for(int i=0;i<=90;i+=5){
        sv1.write(90+i);
        sv2.write(90-i);
        delay(50);
      }*/
      sv1.write(180);
      sv2.write(0);
      pos1++;
      delay(500);
    }
    delay(500);
  }
  else if(digitalRead(inf_1) == HIGH){
    Serial.println("1번 적외선 미감지");
    if(pos1==1){
      sv1.write(90);
      sv2.write(90);
      pos1--;
    }
    delay(500);
  }
  if(digitalRead(inf_2) == LOW){
    Serial.println("2번 적외선 감지");
    if(pos2==0) {
      sv3.write(180);
      sv4.write(0);
      pos2++;
      delay(500);
    }
    delay(500);
  }
  else if(digitalRead(inf_2) == HIGH){
    Serial.println("2번 적외선 미감지");
    if(pos2==1){
      sv3.write(90);
      sv4.write(90);
      pos2--;
      delay(500);
    }
    delay(500);
  }
}
