#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pinButton1 = 6;
int pinButton2 = 7;
int tempoI = 0;
int tempoF = 0;
int tempo  = 0;
int cronos = 0;
int state  = 0;

void setup() {
  pinMode(pinButton1, INPUT);
  pinMode(pinButton2, INPUT);
  lcd.begin(16, 2);
}

void loop() {
  int valButton1 = digitalRead(pinButton1);
  int valButton2 = digitalRead(pinButton2);
  
  if(state == 0){
    if(valButton1==HIGH){
  		tempoI = millis();
    	lcd.clear();
  		state = 1;
  	} 
  }
  
  if(state == 1){
    lcd.setCursor(0, 0);
    lcd.print("Tempo: ");
    	
    cronos = millis() - tempoI;
    lcd.setCursor(0, 1);
	lcd.print(cronos);
    
    if(valButton2==HIGH){
    	tempoF = millis();
    	tempo  = tempoF - tempoI;
    
  		lcd.setCursor(0, 1);
		lcd.print(tempo);
          
    	state = 0;
  	}  
  }
}
 