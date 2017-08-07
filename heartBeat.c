//...https://www.youtube.com/watch?v=xa_2W-Oh-ls
//...http://microcontrollerslab.com/heart-beat-sensor-arduino/
//...https://www.youtube.com/watch?v=dzV2IehmhR0
//...https://www.youtube.com/watch?v=2_c0yE9QHNI

int led_Pin = 13;                                      // initializing the led pin
int output_Pin = A0;                                // initializing the sensor output pin
//initializng other variables
double alpha = 0.75;
int period = 200;
double change = 0.0;
void setup ( ){
     pinMode (led_Pin, OUTPUT);                   // declaring led pin as output
      Serial.begin (115200);                                   // setting baud rate at 115200
}
void loop (){
// initializing other variables
    static double oldValue = 0;
    static double oldChange = 0;
    int rawValue = analogRead (output_Pin);                                         // Reading the sensors values
    double value = alpha * oldValue + (1 - alpha) * rawValue;         // calculating values using the formula
    Serial.print (rawValue);              // printing the sensor output value on the screen
    Serial.print (",");                                                                                          
    Serial.println (value);             // printing the heart beat value on the screen
    oldValue = value;
    delay (period);
} 
