#include <Arduino.h>

//OLED
#include <GyverOLED.h>
GyverOLED <SSD1306_128x64, OLED_BUFFER> LCD;

//Welcome Fenster
void Welcome() {
  LCD.setCursor(20, 1);
  LCD.setScale(3);
  LCD.print("Hallo");
  LCD.update();

  LCD.setCursor(20, 5);
  LCD.setScale(2);
  LCD.print("ich bin");
  LCD.update();
  delay(2000);
  LCD.clear();
  LCD.update();
  

  LCD.setCursor(45, 1);
  LCD.setScale(2);
  LCD.print("Dein");
  LCD.update();

  LCD.setCursor(15, 5);
  LCD.print("RechtEgg!");
  LCD.update();
  delay(3000);
  LCD.clear();
  LCD.update();
}

//Zeiger und Hauptmenu
  int zeiger = 0;

void printZeiger(int ptr){
  LCD.setCursor(0,ptr);
  LCD.print("=>");
}

void oled_update(){
  LCD.update();
  LCD.home();
  LCD.setScale(1);
  LCD.print
  (F(
    "   ------------------\n\r"
    "   Weich Egg : 5 Min\n\r"
    "   Cool  Egg : 7 Min\n\r"
    "   Fest  Egg : 10 Min\n\r"
    "   ------------------\n\r"
    "      Stopp_Uhr    \n\r"
    "       My Egg   \n\r"
    
  ));
  printZeiger(zeiger);
  LCD.update();

}

