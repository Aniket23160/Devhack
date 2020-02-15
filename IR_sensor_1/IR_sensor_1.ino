int obstaclePin = 4;  // This is our input pin
int hasObstacle = LOW;  // HIGH MEANS NO OBSTACLE
int LED = 13; // Use the onboard Uno LED

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(obstaclePin, INPUT);
Serial.begin(9600);  

}
void loop() {
    hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
if (hasObstacle == HIGH) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Stop something is ahead!!");
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
    
  }
}
  // put your main code here, to run repeatedly:
