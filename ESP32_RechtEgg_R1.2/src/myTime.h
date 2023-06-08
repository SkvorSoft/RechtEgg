#ifndef myTime_H
#define myTime_H

#include<Arduino.h>
#include<Wire.h>
#include <RTClib.h>
#include <SimpleDHT.h>

//RealTimeClock
RTC_DS3231 rtc;
int set_color=11;
long color=purple;

//DHT22
int pinDHT22 = 25;
SimpleDHT22 dht22;

void myTime(){

    DateTime now =rtc.now();

    //Design
    LCD.fastLineH(20,0,23);
    LCD.fastLineH(20,107,127);
    LCD.fastLineH(63,0,127);

    //Kalender
    LCD.setScale(1);
    LCD.setCursor(30, 2);
    LCD.print(now.day(),DEC);
    LCD.setCursor(45,2);
    LCD.print("/");

    LCD.setCursor(55, 2);
    LCD.print(now.month(),DEC);
    LCD.setCursor(70,2);
    LCD.print("/");

    LCD.setCursor(80, 2);
    LCD.print(now.year(),DEC);

    //Uhrzeit
    LCD.setScale(3);
    LCD.setCursor(20,4);
    LCD.print(now.hour());
    
    LCD.setCursor(55,4);
    LCD.print(":");

    LCD.setCursor(70,4);
    LCD.print(now.minute());

    LCD.setScale(1);
    LCD.setCursor(110,4);
    LCD.print(now.second());

    //DHT22
    byte temperatur = 0;
    byte hum = 0;
  
    dht22.read(pinDHT22, &temperatur, &hum, NULL);
    LCD.setCursor(0, 0);  
    LCD.setScale(2);
    LCD.print(String(temperatur));

    LCD.setCursor(25, 0);
    LCD.print("C");

    LCD.setCursor(93, 0);
    LCD.print(String(hum));
    LCD.setCursor(117, 0);
    LCD.print("%");
    
    LCD.update();
    LCD.clear();
    

    //Farbenwechsel
    if (ecoder.isDouble() && digitalRead(tast)==1){
        set_color++;
        Serial.println(set_color);
        if (set_color>15){
            set_color=1;
        }
        switch (set_color)
        {
        case 1:
            color=red;
            break;
        case 2:
            color=dorange;
            break;
        case 3:
            color=orange;
            break;
        case 4:
            color=gold;
            break;
        case 5:
            color=yellow;
            break;
        case 6:
            color=lgreen;
            break;
        case 7:
            color=green;
            break;
        case 8:
            color=hblau;
            break;
        case 9:
            color=cyan;
            break;
        case 10:
            color=blue;
            break;
        case 11:
            color=purple;
            break;
        case 12:
            color=blvio;
            break;
        case 13:
            color=vio;
            break;
        case 14:
            color=white;
            break;
        case 15:
            color=aus;
            break;
        
        default:
            break;
        }

    }
    RGB_SecondRun(color);
}

#endif