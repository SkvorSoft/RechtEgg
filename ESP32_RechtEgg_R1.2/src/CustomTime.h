#ifndef CustomTime_H
#define CustomTime_H

#include <Arduino.h>
#include <konsta.h>


void Custom (){
  int CMinMax=59;
  int CSec=0;
  int CMin=0;
  
  bool setup =true;
  bool start = false;
  unsigned long timer1;
  bool butt_flag=0;
  

//Timer Einstellen
while (setup==true){
  LCD.setCursor(10, 0);
  LCD.setScale(2);
  LCD.print("My Timer:");
  LCD.setScale(3);
  LCD.setCursor(25, 4);
  LCD.print(String(CMin) + ":" + String(CSec));
  LCD.update();
  LCD.clear();

  if (digitalRead(tast)==0 && butt_flag==0){
    butt_flag=!butt_flag;
    setup=false;
      }
  if (digitalRead(tast)==1 && butt_flag==1){
    butt_flag=!butt_flag;
  }
  
  ecoder.tick();

  if(ecoder.isRight()){
    CMin=CMin+1;
    LCD.clear();
    LCD.update();
    if(CMin>CMinMax){
      CMin=0;
    }
  }

  if(ecoder.isLeft()){
    CMin=CMin-1;
    LCD.clear();
    LCD.update();
    if(CMin<0){
      CMin=59;
    }
  }

  if(ecoder.isRightH()){
    CSec=CSec+15;
    if (CSec>59){
      CSec=0;
    }
  }
  if(ecoder.isLeftH()){
    CSec=CSec-15;
    if(CSec<0){
      CSec=59;
    }
  }
  
  if (ecoder.isDouble()){
      setup=false;
      start=true;
  }

}

//Timer Starten
while (start==true){

  ecoder.tick();
  RGB_Run(hblau,purple);

  if (ecoder.isHolded()){
      start=false;
      strip.clear();
      strip.show();
      }
            
  if (millis() - timer1 > 1000) {
    	timer1 = millis();
    	CSec=CSec-1;
      
    		if (CSec<0){
      			CSec = 59;
      			CMin = CMin -1;
  				  }  
  	    if (CMin==0 && CSec==0){
   		      digitalWrite(LED,HIGH);
            strip.fill(green,0,8);
            strip.show();
      
            while (digitalRead(LED)==1){      
                  LCD.setCursor(10, 0);
                  LCD.setScale(2);
                  LCD.print("My Timer:");
        
                  LCD.setScale(3);
                  LCD.setCursor(25, 4);
                  LCD.update();
                  LCD.print(String(CMin) + ":" + String(CSec));
                  
                   if (digitalRead(tast)==0 && butt_flag==0){
                    timer1=millis();
                      butt_flag=!butt_flag;
                      digitalWrite(LED,LOW);
                      RGB_stop();
                      start=false;
                      }
                  if (digitalRead(tast)==1 && butt_flag==1){
                    butt_flag=!butt_flag;
                      }
                  }
        
  		      } 
    // OLED Ausgabe
    LCD.setCursor(10, 0);
    LCD.setScale(2);
    LCD.print("My Timer:");
    LCD.setScale(3);
    LCD.setCursor(25, 4);
    LCD.print(String(CMin) + ":" + String(CSec));
    LCD.update();
    LCD.clear();
  	}
  } 
}

#endif