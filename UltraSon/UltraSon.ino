int trigPin=30;
int echoPin=31;
float pingTime;
float speedOfSound=343;
float thresh=10;
float Dist;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);

  Dist=speedOfSound*pingTime/20000;
  if (Dist<=thresh){
    Serial.println("Stop"); // Bdl had lcode
  }
  else{
    Serial.println("Just Go"); //bdl had lcode
  }
  delay(100);
}
