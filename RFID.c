//...RFID detector
//............https://www.youtube.com/watch?v=ot4SN5K_0Y8
#include <SoftwareSerial.h>
SoftwareSerial RFID=SoftwareSerial(2, 3); // RX and TX
String st="",str="",strArray[10],fin="";
int i;
void setup(){
  strArray[0]="24848484849704856515250513";
  strArray[1]="24948484851535568695766493";
  strArray[2]="25155484852657054515666513";
  RFID.begin(9600); // start serial to RFID reader
  Serial.begin(9600); // start serial to PC 
}
void loop(){
  /*if(RFID.available() > 0) {
        i = RFID.read();
        //str+=i;
        Serial.print(i,DEC);
        Serial.print(" ");
  }*/
  fin=getData();
  int chk=0;
  for(i=0;i<3;i++){
      if(fin==strArray[i]){
        digitalWrite(11,1);
        Serial.println("Access Allowed!");
        delay(1000);
        fin="";
        chk=1;
        break;
        }
   }
   if(chk==0){
    digitalWrite(11,0);
    Serial.println("Access denied!");
    fin="";
    }
  delay(300);
  //str=str.substring(1,13);
  //Serial.print(str);
  //Serial.print(" ");
}
String getData(){
  str="";
    while(RFID.available()>0){
         st = RFID.read();

         str+=st;
         if(str.length()>=26)
         break;
      }  
      return str;
}
