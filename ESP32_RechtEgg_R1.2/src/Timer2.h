#include <Arduino.h>
#include <konsta.h>
  
void CoolEi (){
  int ledstat=1;
  long statcolor=red;

  bool start = true;
  int SEC = 1;
  int MIN = 7;
  unsigned long timer1;
  bool butt_flag=0;
while (start==true){

  ecoder.tick();
  RGB_Run(lgreen,statcolor);
  RGB_StripStop(ledstat);

  if (ecoder.isHolded()){
      Serial.println("Holded");
      start=false;
      strip.clear();
      strip.show();
      }
            
  if (millis() - timer1 > 1000) {
    	timer1 = millis();
    	SEC=SEC-1;

      //Visualisierung
      if      (MIN==7 && SEC>0) ledstat=1;
      else if (MIN==6 && SEC<=30) {ledstat=2;
                                  statcolor=dorange;}
      else if (MIN==5 && SEC<=30) ledstat=3;
      else if (MIN==4 && SEC<=30) {ledstat=4;
                                  statcolor=gold;}
      else if (MIN==3 && SEC<=30) ledstat=5;
      else if (MIN==2 && SEC<=30) {ledstat=6;
                                  statcolor=yellow;}
      else if (MIN==1 && SEC<=30) ledstat=7;
      //Visualisierung Ende
    		if (SEC<0){
      			SEC = 59;
      			MIN = MIN -1;
  				  }  
  	    if (MIN==0 && SEC==0){
   		      digitalWrite(LED,HIGH);
            digitalWrite(G,HIGH);
            strip.fill(green,0,8);
            strip.show();
      
            while (digitalRead(LED)==1){
                  
                  //RGB_run_one_color(yellow);        
                  LCD.setCursor(10, 0);
                  LCD.setScale(2);
                  LCD.print("Cool Ei:");
        
                  LCD.setScale(3);
                  LCD.setCursor(25, 4);
                  LCD.update();
                  LCD.print(String(MIN) + ":" + String(SEC));
                  
                   if (digitalRead(tast)==0 && butt_flag==0){
                    timer1=millis();
                      butt_flag=!butt_flag;
                      Serial.println("flug up");
                      digitalWrite(LED,LOW);
                      digitalWrite(G,LOW);
                      RGB_stop();
                      start=false;
                      }
                  if (digitalRead(tast)==1 && butt_flag==1){
                    butt_flag=!butt_flag;
                    Serial.println("flag down");
                      }
                  }
        
  		      } 
    // OLED Ausgabe
    LCD.setCursor(10, 0);
    LCD.setScale(2);
    LCD.print("Cool Ei:");

    LCD.setScale(3);
    LCD.setCursor(25, 4);
    LCD.print(String(MIN) + ":" + String(SEC));

    Serial.println(String(MIN) + " : " + String(SEC));
    LCD.update();
    LCD.clear();
  	}
  } 
}