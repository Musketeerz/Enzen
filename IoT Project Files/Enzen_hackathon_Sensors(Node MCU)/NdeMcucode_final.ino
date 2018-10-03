#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <string.h>


#define FIREBASE_HOST "bluetoothcontrol-7ac34.firebaseio.com"

#define FIREBASE_AUTH "Rfl3KOVwSPaVkEExy8TwiNgaJ94rrqFDILbWD28y"

#define WIFI_SSID "SUNDEEP's iPhone"

#define WIFI_PASSWORD "04121997"

#define LED 2
//*******************************for sensors*********************888
int inputPinPIR = 13;
              
int pirState = LOW;  
int ldrState = LOW;  

int waterlevel_empty_state= LOW;  
int waterlevel_full_state= LOW;  
     
int val = 0; 
int sensorPin = A0;
int sensorValue = 0;
int level0= 9;
int level1= 10;

int empty = 0; 
int full = 0;
//**********************************************************************
void setup() {

pinMode(LED,OUTPUT);
  pinMode(inputPinPIR,INPUT);

digitalWrite(LED,0);

Serial.begin(9600);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) {

Serial.print(".");

delay(500);

}

Serial.println();

Serial.print("connected: ");

Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

//Firebase.setInt("LEDStatus",0);


}

void loop() {


digitalWrite(LED,HIGH);





//***********************************************************************************


 val = digitalRead(inputPinPIR); 
  if (val == HIGH)
  {       
    
    if (pirState == LOW)
    {
      //digitalWrite(6, HIGH); 
                                    // Serial.println("0001");
                      Firebase.setString("SENSORS/LDR-PIR/PIR STATUS","pir_true");
      pirState = HIGH;
      delay(2000);
    }
  } 
  else
  {
 
    if (pirState == HIGH){
    
                                   // Serial.println("0000");
                               Firebase.setString("SENSORS/LDR-PIR/PIR STATUS","pir_false");
     //digitalWrite(6, LOW);
      pirState = LOW;
    }
  }

////************************************************* L D R SENSOR ***************************
sensorValue = analogRead(sensorPin); 

if(sensorValue<100)
{

   if (ldrState == LOW)
    {
 
                                                 //  Serial.println("1111");
                        Firebase.setString("SENSORS/LDR-PIR/LDR STATUS","ldr_true");
      ldrState = HIGH;
      
    }
}
else
{
 
    if (ldrState == HIGH){

                                               // Serial.println("1110");
              Firebase.setString("SENSORS/LDR-PIR/LDR STATUS","ldr_false");
     
      ldrState = LOW;
   }
    delay(500);
}




//***********************************************************************************


if (Firebase.failed()) // Check for errors 
{

Serial.print("setting /number failed:");

Serial.println(Firebase.error());

return;

}

delay(100);

digitalWrite(LED,LOW);

}
