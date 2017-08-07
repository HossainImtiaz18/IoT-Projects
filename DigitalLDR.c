//...Pin A0,out 10
int sensorPin = A0;
int sensorValue = 0; 
void setup() {
  // put your setup code here, to run once:
   //pinMode(LDR,INPUT);
   pinMode(10,OUTPUT);
   digitalWrite(10,1);
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sensorPin);
 // Serial.println(sensorValue);
  if(sensorValue>40){
    digitalWrite(10,1);
    }
  else{
      digitalWrite(10,0);
      }
  //delay(1);
}
