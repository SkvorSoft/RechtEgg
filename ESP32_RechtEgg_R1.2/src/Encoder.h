#ifndef Encoder_H
#define Encoder_H

#include <Arduino.h>
#include <GyverEncoder.h>
#include <konsta.h>


Encoder ecoder(CLK,DT,SW);

/*
void Encoder_test(){
    ecoder.tick();

    if (ecoder.isRight()) {
        Serial.println("Right");
        zeiger++;
        if (zeiger >7) {
            zeiger=7;
                        }
        }
        
    if (ecoder.isLeft()) {
        Serial.println("Left");
        zeiger--;
        if (zeiger >0) {
            zeiger=0;
                    }
        }
    if (ecoder.isClick()){
        Serial.println("Click");
    }

    if (ecoder.isHolded()){
        Serial.println("Holded");
    }
    }
   */
#endif