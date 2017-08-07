//...https://www.youtube.com/watch?v=d7oFD-zQpuQ
int lf=2;
int lb=3;
void setup(){
    pinMode(lf,OUTPUT);
    pinMode(lb,OUTPUT);  
}
void loop(){
    digitalWrite(lf,HIGH);
    digitalWrite(lb,LOW);
    delay(3000);
    digitalWrite(lf,LOW);
    digitalWrite(lb,HIGH);  
    delay(3000);
}
