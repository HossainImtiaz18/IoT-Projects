#include <SoftwareSerial.h>
#define RFIDoutput 11
#define ldrDataPin A0
#define LDRoutput 12
#define ULTRAoutput 10
#define trigPin 9
#define echoPin 5
SoftwareSerial RFID=SoftwareSerial(2, 3); // RX and TX
String st="";
String str="";
String strArray[10];
String fin="";
int i,j;
int ldrData = 0;
void setup(){
  RFID.begin(9600);
  Serial.begin(9600);
  RFIDsetup();
  LDRsetup();
  ULTRAsetup();
}
void loop(){
  getRfidData();
  getLdrData();
  getUltraData();
}
void RFIDsetup(){
  strArray[0]="24848484849704856515250513";
  strArray[1]="24948484851535568695766493";
  strArray[2]="25155484852657054515666513";
  pinMode(RFIDoutput,OUTPUT);
  //digitalWrite(RFIDoutput,1);
}
void LDRsetup(){
  pinMode(LDRoutput,OUTPUT);
  //digitalWrite(LDRoutput,1);  
}
void ULTRAsetup(){
    pinMode(trigPin,OUTPUT);
    pinMode(ULTRAoutput,OUTPUT);
    pinMode(echoPin,INPUT);  
}
void getRfidData(){
 getUltraData();
 fin=getData();
 getUltraData();
 if(fin.length()>=25){
           int chk=0;
           for(i=0;i<3;i++){              
                if(fin==strArray[i]){
                  //.......For allowed section........

                  //...........
                  Serial.println("Access Allowed!");
                  fin="";
                  chk=1;
                  break;
                }
            }
            //getLdrData();//..............
            //getUltraData();//............
            if(chk==0){
                     for(j=0;j<5;j++){
                        digitalWrite(RFIDoutput,0);
                        delay(10);
                        //digitalWrite(RFIDoutput,1);
                        //delay(50);
 //                       getLdrData();//........
   //                     getUltraData;//..........
                     }
                  Serial.println("Access denied!");
                  fin="";
                  delay(100);
                  digitalWrite(RFIDoutput,1);
            }
            else{
                  digitalWrite(RFIDoutput,1); 
                  fin="";
                 // delay(10);
            }
  }  
  delay(10);
}
String getData(){
    str="";
    while(RFID.available()>0){
         st = RFID.read();
         getLdrData(); //...............
        // getUltraData();//.................
         str+=st;
         if(str.length()>=26)
           break;
      }
      return str;
}
void getLdrData(){
  ldrData = analogRead(ldrDataPin);
  Serial.println(ldrData);
  if(ldrData<50){
    digitalWrite(LDRoutput,0);
    //getRfidData();
    //delay(100);
    getUltraData();
  }
  else
    digitalWrite(LDRoutput,1);
   // delay(100);
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
  Serial.println(dis);
  //delay(100);
}
