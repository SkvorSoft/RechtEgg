#ifndef RGB_Mono_H
#define RGB_Mono_H


#include <Arduino.h>
#include <konsta.h>
#include<Encoder.h>

int newVal=1400;
unsigned long rgb_time;

//RGB Steuerung
void rgb (int red, int green, int blue) {
  analogWrite (R, red);
  analogWrite (G, green);
  analogWrite (B, blue);
}

bool flag=0;
void RGB() {
  
  if (ecoder.isHold() && flag==0 && digitalRead(tast)==0){
      newVal = newVal-25;
      if(newVal<0){
        newVal=0;
      }
  }
  if (ecoder.isReleaseHold()){
    flag=!flag;
  }

  if (ecoder.isHold()&& flag==1 && digitalRead(tast)==0){
      newVal = newVal+25;
      if(newVal>1530){
        newVal=1530;
      }
  }
  if (newVal <= 255) { //red
    rgb (newVal, 0, 0);
  } else if ((newVal > 255) && (newVal <= 510)) { //orange bis gelb
    rgb (255, newVal - 255, 0);
  } else if ((newVal > 510) && (newVal <= 765)) { //grün
    rgb (765 - newVal, 255, 0);
  } else if ((newVal > 765) && (newVal <= 1020)) { //hellblau
    rgb (0, 255, newVal - 765);
  } else if ((newVal > 1020) && (newVal <= 1275)) { //blau
    rgb (0, 1275 - newVal, 255);
  } else if ((newVal > 1275) && (newVal <= 1530)) { //violett
    rgb (newVal - 1275, 0, 255);
  }
  Serial.println (newVal);
}

#endif