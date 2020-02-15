//int LED = 11; // Use the onboard Uno LED
int obstaclePin = 4;  // This is our input pin
int hasObstacle = LOW;  // HIGH MEANS NO OBSTACLE
int LED = 13; // Use the onboard Uno LED
int obstaclePin_2 = 7;  // This is our input pin
int hasObstacle_2 = LOW;  // HIGH MEANS NO OBSTACLE
int buzzer=12;
int obstaclePin_1 = 8;  // This is our input pin
int hasObstacle_1 = LOW;  // HIGH MEANS NO OBSTACLE
int led_1 = 5;
int led_2 = 9;
int led_3 = 2;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(obstaclePin, INPUT);
  pinMode(obstaclePin_1, INPUT);
  pinMode(obstaclePin_2, INPUT);
//  pinMode(obstaclePin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  lcd.begin(20, 4); 
  lcd.setCursor(0, 0);
  lcd.print("    Direction   ");
  Serial.begin(9600);  
}
void loop() {
  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
 hasObstacle_2 = digitalRead(obstaclePin_2);
 hasObstacle_1 = digitalRead(obstaclePin_1);
  if (hasObstacle_2 == HIGH) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Stop something is ahead!!");
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
    digitalWrite(led_1, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 2);
    lcd.print("lEFT");
    delay(1500);
    digitalWrite(led_1, LOW);
  }
  else
  if (hasObstacle == HIGH) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Stop something is ahead!!");
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
    digitalWrite(led_2, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(8, 2);
    lcd.print("MIDDLE");
     delay(1500);
         digitalWrite(led_2, LOW);
  }

  else
  if (hasObstacle_1 == HIGH) //LOW means something is ahead, so illuminates the 13th Port connected LED
{
    Serial.println("Stop something is ahead!!");
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
    digitalWrite(led_3, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(15, 2);
    lcd.print("RIGHT");
     delay(1500);
         digitalWrite(led_3, LOW);
  }
  else
  {
    Serial.println("Path is clear");
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 2);
    lcd.print("    ");
    lcd.setCursor(8, 2);
    lcd.print("      ");
    lcd.setCursor(15, 2);
    lcd.print("     ");
  }
  delay(200);
}
