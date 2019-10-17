# 1 "c:\\Users\\abaub\\Documents\\Arduino\\generated_examples\\BlinkSerial\\BlinkSerial.ino"
# 1 "c:\\Users\\abaub\\Documents\\Arduino\\generated_examples\\BlinkSerial\\BlinkSerial.ino"
String s1 = "";
byte LED = 6;

void setup()
{
    pinMode(LED, (0x1));
    SerialUSB.begin(9600);
    SerialUSB.println("START");
}


void loop()
{
    s1 = SerialUSB.readString(); // s1 is String type variable.
    if (s1!=""){
        SerialUSB.print("Received Data => ");
        SerialUSB.println(s1); //display same received Data back in serial monitor. 

        if(s1.indexOf("ON")>=0){ //ON order from serial monitor 
            digitalWrite(LED,(0x1));
            SerialUSB.println("LED ON");
        }
        else if(s1.indexOf("OFF")>=0){ //OFF order from serial monitor
            digitalWrite(LED,(0x0));
            SerialUSB.println("LED OFF");
        }
        else{ //Invalid order from serial monitor
            SerialUSB.println("Invalid Data");
        }
    }

    delay(100);

}
