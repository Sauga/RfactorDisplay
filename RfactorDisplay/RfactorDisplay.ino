/*
 Name:		RfactorDisplay.ino
 Created:	21/11/2015 19:14:01
 Author:	David
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);
int cont = 0;
bool flag = true;


// the setup function runs once when you press reset or power the board
void setup() 
{
	Serial.begin(115200);
	lcd.begin(16, 2);
	lcd.setCursor(0, 0);
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (flag)
	{
		lcd.setCursor(0, 0);
		lcd.write("LCD ON");
		lcd.setCursor(0, 1);
		lcd.print(cont++);
		delay(500);
	}

	String content = "";
	while (Serial.available() > 0)
	{
		char character = Serial.read();
		content.concat(character);
		flag = false;
	}

	if (content != "")
	{
		lcd.clear();
		lcd.setCursor(0, 0);
		lcd.print(content);
	}
	delay(10);
}
