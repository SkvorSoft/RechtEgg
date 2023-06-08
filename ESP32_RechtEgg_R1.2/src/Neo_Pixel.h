#ifndef Neo_Pixel_H
#define Neo_Pixel_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include<konsta.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

long red(strip.Color(250, 0, 0));
long dorange(strip.Color(200,50,0));
long orange(strip.Color(255,100,0));
long gold(strip.Color(155,150,0));
long yellow(strip.Color(255,255,0));

long lgreen(strip.Color(124,252,0));
long green(strip.Color(0, 250, 0));

long hblau(strip.Color(0,125,255));
long cyan(strip.Color(0,238,238));
long blue(strip.Color(0, 0, 250));

long purple(strip.Color(155,48,255));
long blvio(strip.Color(115,5,225));
long vio(strip.Color(193,12,212));

long white(strip.Color(255,255,255));
long aus(strip.Color(0,0,0));

int pixel=0;
unsigned long timer_sec,timer_strip=0;

//Alle LEDs Ausschalten
void RGB_stop(){
   for (int i=0; i<LED_NUM;i++){
         strip.setPixelColor(i,(0,0,0));
         strip.show();
   }
}
void RGBTEST(){
      strip.fill(dorange,0,2);
      strip.fill(purple,2,3);
      strip.fill(blvio,4,5);
      strip.fill(vio,6,7);
      strip.show();
}
// 1 Farbeffekt
void RGB_StripStop(int num){
            strip.fill(lgreen,0,num);
            strip.show();
}

void RGB_Run(long color,long color2){
            if (millis()-timer_strip>=SPEED){
                  timer_strip=millis();
                  strip.setPixelColor(pixel,color);
                  strip.show();
                  pixel++;
                  }
            if (pixel>8){
                  pixel=0;
                  strip.fill(color2,0,8);
                  strip.show();
                  }
            
}

// Lauflicht 1/Sec
void RGB_SecondRun(long color){
            if (millis()-timer_sec>=1000){
            timer_sec=millis();
            strip.setPixelColor(pixel,color);
            strip.show();
            pixel++;
            if (pixel>8){
                  pixel=0;
                  strip.clear();
                  strip.show();
                  }
            }
}

#endif


