 #include "fonctions.h"
 #include <string> 
 #define RECEIVE
 
 
 LCD_DISCO_F429ZI lcd;

 RCSwitch mySwitch = RCSwitch( PF_7, PF_9 ); //tx, rx
 Serial pc(USBTX, USBRX);
 
 int main()
 {
    uint8_t text[30];
    BSP_LCD_SetFont(&Font20);
    lcd.Clear(LCD_COLOR_BLACK);
    lcd.SetBackColor(LCD_COLOR_BLACK);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    
    float receivedValue = 0;
    
    
    while(1) {
        if (mySwitch.available()) {
            receivedValue = mySwitch.getReceivedValue();
            sprintf((char*)text, "Received %f", decode(receivedValue));
            lcd.DisplayStringAt(0, LINE(1), (uint8_t *)&text, CENTER_MODE);
            mySwitch.resetAvailable();
         }
    pc.printf("%f\n",decode(receivedValue));
    
    string uuuu= (string)pc.getc();
    sprintf((char*)text, "valeur: %s", uuuu );
    lcd.DisplayStringAt(0, LINE(4), (uint8_t *)&text, CENTER_MODE);
    }
 }