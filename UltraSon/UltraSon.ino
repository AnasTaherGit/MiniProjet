#include <SoftwareSerial.h>

#define trigPin 5
#define echoPin 6
#define Buzzer  7
#define OnOff    2

float pingTime;
float speedOfSound=343;
// float thresh=10;
float Dist;

int RxPin=0;
int TxPin=1;
char c;
bool ObstacleExist=false;
bool state=true;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //HC06.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(OnOff,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(OnOff),Wakeup,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);
  Dist=speedOfSound*pingTime/20000;

  if (Dist<100){
    ObstacleExist=true;
  }
  else{
    ObstacleExist=false;
  }

  delay(10);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);
  Dist=speedOfSound*pingTime/20000;
  if (Dist<100 && ObstacleExist){
    if(!state){
      analogWrite(Buzzer, 190);
      delay(10+Dist*10);
      analogWrite(Buzzer, 0);
      String ss="#"+String(Dist);
      for (int i=0;i<ss.length();i++){
        c=ss[i];
        Serial.write(c);
      }
    }
  }
  else{
    String ss=">>>";
    for (int i=0;i<ss.length();i++){
      c=ss[i];
      Serial.write(c);
    }
  }
  delay(100);
}

void Wakeup(){
  state=!state;
}
