#include "Servo.h" 
 
Servo servoD1; 


char incomingByte;

int  water_heater = 2;    
int  iron_box = 3; 
int  bedroom_light = 4;
int  bedroomfan = 6;
int watermotor = 7;
int outsidelight = 5;
                
int inputPinPIR = 8;
              
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


void setup() {

  
   Serial.begin(9600);
  pinMode(9, OUTPUT);
 
  
  pinMode(inputPinPIR,INPUT);   

  pinMode(water_heater,OUTPUT);
  pinMode(iron_box,OUTPUT);
  pinMode(bedroom_light,OUTPUT);
   pinMode(bedroomfan,OUTPUT);
   pinMode(watermotor,OUTPUT);
   pinMode(outsidelight,OUTPUT);

     pinMode(LED_BUILTIN, OUTPUT);

     pinMode (level0,INPUT);
     pinMode (level1,INPUT);

       servoD1.attach(8);

  
  
}

void loop() {
  
  if (Serial.available() > 0 )
  {
    incomingByte = Serial.read();  
 Serial.println(incomingByte);

 
    
    if(incomingByte == 'b') 
    {
       digitalWrite(water_heater, LOW);
       
    }

    
    if(incomingByte == 'a') 
    {
       digitalWrite(water_heater, HIGH); 

    }

    if(incomingByte == 'd')
    {
       digitalWrite(iron_box, LOW);
    }

    
    if(incomingByte == 'c') 
    {
       digitalWrite(iron_box, HIGH); 
    }

    if(incomingByte == 'f')
    {
       digitalWrite(bedroom_light, LOW);
    }

    
    if(incomingByte == 'e') 
    {
       digitalWrite(bedroom_light, HIGH); 
    }

        if(incomingByte == 'h')
    {
       digitalWrite(bedroomfan, LOW);
    }

    
    if(incomingByte == 'g') 
    {
       digitalWrite(bedroomfan, HIGH); 
    }

          if(incomingByte == 'l')
    {
       digitalWrite(watermotor, LOW);
    }

    
    if(incomingByte == 'k') 
    {
       digitalWrite(watermotor, HIGH); 
    }

           if(incomingByte == 'n')
    {
       digitalWrite(outsidelight, LOW);
    }

    
    if(incomingByte == 'm') 
    {
       digitalWrite(outsidelight, HIGH); 
    }

     if(incomingByte == 'x')
    {
      servoD1.write(-30);   //door close
    }

    
    if(incomingByte == 'y') 
    {
       servoD1.write(100);  //door open 
    }

 }


//
////************************************************* P I R SENSOR ***************************
////
//    val = digitalRead(inputPinPIR); 
//  if (val == HIGH)
//  {       
//    
//    if (pirState == LOW)
//    {
//      //digitalWrite(6, HIGH); 
//      Serial.println("0001");
//      pirState = HIGH;
//      delay(1000);
//    }
//  } 
//  else
//  {
// 
//    if (pirState == HIGH){
//    
//      Serial.println("0000");
//     //digitalWrite(6, LOW);
//      pirState = LOW;
//    }
//  }
//
////************************************************* L D R SENSOR ***************************
//sensorValue = analogRead(sensorPin); 
//
//if(sensorValue<100)
//{
//
//   if (ldrState == LOW)
//    {
// 
//      Serial.println("1111");
//      ldrState = HIGH;
//      
//    }
//}
//else
//{
// 
//    if (ldrState == HIGH){
//
//     Serial.println("1110");
//     
//      ldrState = LOW;
//   }
//    delay(500);
//}
//************************************************* WATER LEVEL EMPTY***************************

//     empty=digitalRead(level0);
//  if (empty == HIGH)
//  {       
//     
//    if (waterlevel_empty_state == LOW)
//    {
//   
//    //  Serial.println("WATER LEVEL LOW");
//      waterlevel_empty_state = HIGH;
//    }
//  } 
//  else
//  {
//     
//    if (waterlevel_empty_state == HIGH)
//    {
//         Serial.println("1010");
//     waterlevel_empty_state = LOW;
//    }
//  }

//************************************************* WATER LEVEL FULL***************************
//full=digitalRead(level1);
// if (full == HIGH)
//  {       
//   // digitalWrite(ledPin, HIGH);  
//    if (waterlevel_full_state == LOW)
//    {
//      Serial.println("1011");
//      //Serial.println("WATER LEVEL FULL");
//      waterlevel_full_state = HIGH;
//      
//    }
//  } 
//  else
//  {
//    if (waterlevel_full_state == HIGH)
//    {     
//     waterlevel_full_state = LOW;
//    }
//  }
//****************************************************************************
//Serial.flush();
}


