#define trigPin 5
#define echoPin 6
#define Buzzer  7

float pingTime;
float speedOfSound=343;
// float thresh=10;
float Dist;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(Buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);
  Serial.print(pingTime);
  Serial.print(" ");
  Dist=speedOfSound*pingTime/20000;
  Serial.println(Dist);
  if (Dist<50){
	  analogWrite(Buzzer, 190);
	  delay(10+Dist*10);
	  analogWrite(Buzzer, 0);
	  delay(300);
  }
}
