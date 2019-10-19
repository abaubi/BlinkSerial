String s1 = "";
byte LED = 2; //2 wemos d1 mini, 6 mkr1000
 
void setup() 
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    Serial.println("START");
}
 
 
void loop()
{
    s1 = Serial.readString();               // s1 is String type variable.
    if (s1!=""){
        Serial.print("Received Data => ");
        Serial.println(s1);                 //display same received Data back in serial monitor. 
    
        if(s1.indexOf("ON")>=0){            //ON order from serial monitor 
            digitalWrite(LED,HIGH);
            Serial.println("LED ON");
        }
        else if(s1.indexOf("OFF")>=0){      //OFF order from serial monitor
            digitalWrite(LED,LOW);
            Serial.println("LED OFF");
        }
        else{                               //Invalid order from serial monitor
            Serial.println("Invalid Data");
        }             
    }

    delay(100);
 
}
  
