#ifndef StoppUhr_H
#define StoppUhr_H

#include <Arduino.h>
#include <Neo_Pixel.h>


void StoppUhr (){ 

  int SEC =0;
  int MIN = 0;
  unsigned long timer;
  int gong = 1;
  int count =0;
  
  byte butt_flag4=0;
  
  while (gong==1 && count<5){
        ecoder.tick();

     //Zurück ins Hauptmenu   
        if (ecoder.isHolded()){
        //Serial.println("Holded");
        LCD.clear();
        LCD.update();
        strip.clear();
        strip.show();
        gong=0;
          }

    LCD.setCursor(40, 0);
    LCD.setScale(1);
    LCD.print("StoppUhr:");
    LCD.setScale(2);
    LCD.setCursor(35, 2);
    LCD.print(String(MIN) + " : " + String(SEC));
    //Serial.println(String(MIN) + " : " + String(SEC));
    LCD.update();
    

    if (ecoder.isClick()){
    count++;
    SEC=SEC;
    MIN=MIN;
    // Runden darstellen
      if (count==1){
        LCD.setScale(1);
        LCD.setCursor(0, 4);
        LCD.print("Time: "+ String(MIN) + ":" +String(SEC));
        LCD.update();
        strip.setPixelColor(7,white);
        strip.setPixelColor(6,white);
        strip.show();
        }

    if (count==2){
        LCD.setScale(1);
        LCD.setCursor(0, 7);
        LCD.print("Time: "+ String(MIN) + ":" +String(SEC));
        LCD.update();
        strip.setPixelColor(5,blue);
        strip.setPixelColor(4,blue);
        strip.show();
        }

     if (count==3){
        LCD.setScale(1);
        LCD.setCursor(68, 4);
        LCD.print("Time: "+ String(MIN) + ":" +String(SEC));
        LCD.update();
        strip.setPixelColor(3,red);
        strip.setPixelColor(2,red);
        strip.show();
        }   

    if (count==4){
        
        LCD.setScale(1);
        LCD.setCursor(68, 7);
        LCD.print(String(count)+" " + "Time: " +String(SEC));
        LCD.update();
        strip.setPixelColor(1,cyan);
        strip.setPixelColor(0,cyan);
        strip.show();
        
        while (digitalRead(tast)==1 && gong==1)
        {
        LCD.update();
        SEC=SEC;
        MIN=MIN;
        LCD.setCursor(40, 0);
        LCD.setScale(1);
        LCD.print("StoppUhr:");
        LCD.setScale(2);
        LCD.setCursor(35, 2);
        LCD.print(String(MIN) + " : " + String(SEC));
        LCD.update();

        if (digitalRead(tast)==0 && butt_flag4==0){
              butt_flag4=!butt_flag4;
              Serial.println("flug up");
              strip.clear();
              strip.show();
              gong=0;
              LCD.clear();
              LCD.update(); 
              }
  
          if (digitalRead(tast)==1 && butt_flag4==1){
            butt_flag4=!butt_flag4;
            Serial.println("flag down");
            }
          }  
      }
        }
    
if (millis() - timer > 1000) {
  Serial.println(String(MIN) + " : " + String(SEC));
    timer = millis();
    SEC=SEC+1;
    //LCD.clear();
    LCD.update();
    if (SEC>59){
      SEC = 0;
      MIN = MIN +1;
  }  
  
    if (MIN>=5 && SEC>=0){
        LCD.clear();
        LCD.update();
        digitalWrite(LED,HIGH);
        //digitalWrite(R,HIGH);

         while (digitalRead(tast)==1 && gong==1)
        {
        LCD.update();
        SEC=SEC;
        MIN=MIN;
        LCD.setScale(2);
        LCD.setCursor(15,5);
        LCD.print("Time_Out:");
        LCD.setScale(2);
        LCD.setCursor(35, 2);
        LCD.print(String(MIN) + " : " + String(SEC));
        LCD.update();
        strip.fill(red,0,8);
        strip.show();

        if (digitalRead(tast)==0 && butt_flag4==0){
              butt_flag4=!butt_flag4;
              Serial.println("flug up");
              digitalWrite(LED,LOW);
              digitalWrite(R,LOW);
              strip.clear();
              strip.show();
              gong=0;
              LCD.clear();
              LCD.update(); 
              }
  
          if (digitalRead(tast)==1 && butt_flag4==1){
            butt_flag4=!butt_flag4;
            Serial.println("flag down");
            }
          }      
  }
    
  }
  } 
}

#endif