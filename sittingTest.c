#define digData 3
#define bz  7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(digData,INPUT);
  pinMode(bz,OUTPUT);
  digitalWrite(digData,LOW);
  digitalWrite(bz,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(digData)==HIGH){
     Serial.println("There's someone sitting !");
      digitalWrite(bz,HIGH);
      delay(50);
      digitalWrite(bz,LOW);
  }
       Serial.println("BoooooooooooM !");
}
