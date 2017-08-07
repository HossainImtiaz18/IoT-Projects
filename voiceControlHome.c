String voice;
#define relay1 2
#define relay2 3
void setup() {  
  Serial.begin(9600);  
  pinMode(relay1,OUTPUT);  
  pinMode(relay2,OUTPUT);  
  digitalWrite(relay1,HIGH);  
  digitalWrite(relay2,HIGH); 
} 
 
void loop() {   
  while(Serial.available())
  {     
    delay(10); 
    char c = Serial.read();     
    if(c=='#'){       
      break;     
    }     
    voice +=c;   
  }   
    if(voice.length()>0)   
    {     
      Serial.println(voice);     
      if(voice=="*light on"){       
        lighton();     
      }     
      else if(voice=="*light off"){       
        lightoff();     
      }     
      else if(voice=="*fan on"){      
        fanon(); 
      }    
      else if(voice=="*fan stop"){       
        fanoff();     
      }    
      voice="";   
     } 
  } 
 
void lighton() 
{   
  digitalWrite(relay1,LOW); 
} 
void lightoff() 
{   
  digitalWrite(relay1,HIGH); 
} 
 
void fanon() 
{  
  digitalWrite(relay2,LOW); 
} 
void fanoff() 
{   
  digitalWrite(relay2,HIGH); 
}
