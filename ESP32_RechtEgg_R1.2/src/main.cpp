#include <Arduino.h>
#include <konsta.h>
#include <RGB_Mono.h>
#include <Start_Window.h>
#include<StoppUhr.h>
#include<GyverEncoder.h>
#include<Timer1.h>
#include<Timer2.h>
#include<Timer3.h>
#include<myTime.h>
#include<CustomTime.h>



int pointEnter =0;
unsigned long Timer1,Timer2,Timer3;
bool start =1;
bool MenuAn =0;

void setup() {

  //Zurücktaste und Signal
  pinMode(LED, OUTPUT);
  pinMode(tast,INPUT);
  pinMode (R,OUTPUT);
  pinMode(G,OUTPUT);

  RGB();

  //RTC
  Wire.begin();
  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));

  
  //PIXELS
  strip.begin();
  strip.setBrightness(HELLKT);
  
  // LCD
  Serial.begin(115200);
  LCD.init();
  Welcome();
  
  
  

  //Encoder
  Encoder ecoder(CLK,DT,SW);
  ecoder.setType(TYPE2);
  ecoder.setTickMode(AUTO);

  

  

}

void loop() {
  
    //Hauptbildschirm
    RGB();
    
    myTime();

  ecoder.tick();
  if ((ecoder.isLeft() || ecoder.isRight()) && millis() - Timer2>=1500)
      {
        RGB_stop();
        Timer2=millis();
        MenuAn=1;
        }
    //Hauptmenu
  while (MenuAn==1)
  {
    oled_update();
    ecoder.tick();

  if (ecoder.isRight() && millis() - Timer1 >= 25) {
        Timer1=millis();
        //Serial.println("Right");
        zeiger++;
        pointEnter++;
        if (zeiger >6) {
            zeiger=6;
        }

        if (pointEnter>6){
          pointEnter=6;
          //Serial.println("point max");
        }                
        }
        
    if (ecoder.isLeft() && millis() - Timer1 >= 25) {
        Timer1=millis();
        //Serial.println("Left");
        zeiger--;
        pointEnter--;
        if (zeiger<0) {
            zeiger=0;
                    }
        if (pointEnter<0){
          pointEnter=0;
          //Serial.println("point min");
        }                           
        }
    if (ecoder.isClick()){

      switch (pointEnter)
        {
        case 1:
            LCD.clear();
            LCD.update();
            //Serial.println("1 pos");
            WeichEi();
            break;
        case 2:
            LCD.clear();
            LCD.update();
            CoolEi();
            //Serial.println("2 Pos");
            break;
        case 3:
            LCD.clear();
            LCD.update();
            //Serial.println("3 Pos");
            FestEi();
            break;
        case 5:
              LCD.clear();
              LCD.update();
              StoppUhr();
              break;
        case 6:
              LCD.clear();
              LCD.update();
              Custom();
              break;      
        default:
            Serial.println("Stop");     
        }
        Serial.println("Click");
        pointEnter=0;
        zeiger=0;
        
    }

    if (ecoder.isHolded() && millis()-Timer1>100){
        Timer1=millis();
        Timer2=millis();
        //Serial.println("Holded"); 
        LCD.clear();
        LCD.update();
        MenuAn=0;
    }
}
}

    
     
