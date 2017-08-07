//.....DHT Library ...https://drive.google.com/file/d/0B1paTI5fzcHodno5azFOSVVDT0E/view?usp=sharing
//.....http://www.instructables.com/id/How-to-interface-Humidity-and-Temperature-DTH11-Se/step2/Program-and-Results/

#include<dht.h>
dht DHT;
// if you require to change the pin number, Edit the pin with your arduino pin.
#define DHT11_PIN 3
void setup() {
Serial.begin(9600);
Serial.println("welcome to TechPonder Humidity and temperature Detector"); 
}
void loop() { // READ DATA
int chk = DHT.read11(DHT11_PIN);
Serial.println(" Humidity " );
Serial.println(DHT.humidity, 1);
Serial.println(" Temparature ");
Serial.println(DHT.temperature, 1);
delay(2000);
}
