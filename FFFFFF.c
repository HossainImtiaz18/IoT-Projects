#include <Servo.h>
#include <SoftwareSerial.h>
#define RFIDoutput 11
#define ldrDataPin A0
#define LDRoutput 12
#define ULTRAoutput 10
#define trigPin 9
#define echoPin 5
#define servoPin 6
Servo ser;
SoftwareSerial RFID=SoftwareSerial(2, 3); // RX and TX
String st="\0";
String str="\0";
String strArray[10];
String fin="\0";
int i,j,test=1,cnt;
int ldrData = 0;
void setup(){
  RFID.begin(9600);
  Serial.begin(9600);
  ser.attach(servoPin);
  RFIDsetup();
  LDRsetup();
  ULTRAsetup();
}
void loop(){
   cnt=0;
    //ser.write(0);
    //delay(1000);
  getRfidData();
  getLdrData();
  getUltraData();
  //delay(1000);
}
void RFIDsetup(){
  strArray[0]="24848484849704856515250513";
  strArray[1]="24948484851535568695766493";
  strArray[2]="25155484852657054515666513";
  pinMode(RFIDoutput,OUTPUT);
  digitalWrite(RFIDoutput,0);
}
void LDRsetup(){
  pinMode(LDRoutput,OUTPUT);
}
void ULTRAsetup(){
    pinMode(trigPin,OUTPUT);
    pinMode(ULTRAoutput,OUTPUT);
    pinMode(echoPin,INPUT);  
}
void getRfidData(){
 
 fin=getData();
 //Serial.println(fin);
 cnt=0;
 if(fin.length()>=25){
           int chk=0;
           for(i=0;i<3;i++){              
                if(fin==strArray[i]){
                   //Serial.println("Access Allowed!");
                 fin="\0";
                  str="\0";
                  st="\0";
                  test=0;
                  chk=1;
                  break;
                }
            }
            if(chk==0){
                        digitalWrite(RFIDoutput,0);
                        delay(100);
                        //Serial.println("Access denied!");
                        fin="";
                        test=1;
                 // delay(100);
                 digitalWrite(RFIDoutput,1);
                 // delay(2);
                  //digitalWrite(RFIDoutput,0);
                        cnt=0;
            }
            else{
                  digitalWrite(RFIDoutput,1); 
                  cnt++;
                  fin="\0";
            }
  }  
  delay(10);
  fin="";
  if(cnt>0){
                  ser.write(0);
                  delay(500);
                  //ser.write(90);
                  //delay(100);
                  ser.write(180);
                  delay(500);
                  cnt=0;
    }
}
String getData(){
    str="";
    st="";
    while(RFID.available()>0){
         st = RFID.read();
         //getLdrData(); //...............
         str+=st;
         //Serial.println(str);
         delay(10);
        if(str.length()>=26){
       // Serial.println(str);
        delay(200);
           break;
         }
      }
      return str;
}
void getLdrData(){
  ldrData = analogRead(ldrDataPin);
  //Serial.println(ldrData);
  if(ldrData<50){
    digitalWrite(LDRoutput,0);
     //ser.write(0);
     ////delay(1000);
   // getRfidData();
  }
  else
    digitalWrite(LDRoutput,1);
}
void getUltraData(){
  float dura, dis;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  dura = pulseIn(echoPin, HIGH);
  dis = (dura / 2.0) * 0.0344;
  if (dis<= 20.0){
    digitalWrite(ULTRAoutput,1);
    delay(100);
  }
  else {
    digitalWrite(ULTRAoutput,0);
    delay(100);
  }  
  //Serial.println(dis);
  //ser.write(0);
  delay(10);
  //getRfidData();
}
