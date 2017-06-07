/*
 * 
 Based on Analog Input Sample code
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

int potPin = A2;    // input pin for the potentiometer
int red = 9;     // led pins
int green = 10;
int blue = 11;
int redBright = 0;  // to store values after mapping
int greenBright = 0;
int blueBright = 0;
int potValue = 0;  // variable to store the value coming from the pot

void setup() {
  // declare the pins as input/output
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the pot
  potValue = analogRead(potPin);

  /* 
   *  red range should be 85 - 597
   *  green range should be 427 - 939
   *  blue range should be 767 - 256 (wrapped around 0)
   */
  Serial.println(potValue);
  // maps maps maps
  if(potValue < 342) {
    blueBright = map(potValue, 0, 256, 1023, 40);
    redBright = map(potValue, 85, 341, 40, 1023);
    greenBright = 0;
    Serial.println("low");
  } else if(potValue < 684) {
    redBright = map(potValue, 342, 597, 1023, 40);
    greenBright = map(potValue, 427, 683, 40, 1023);
    blueBright = 0;
    Serial.println("middle");
  } else {
    greenBright = map(potValue, 684, 939, 1023, 40);
    blueBright = map(potValue, 767, 1023, 40, 1023);
    redBright = 0;
    Serial.println("high");
  }
  analogWrite(red, redBright);
  analogWrite(green, greenBright);
  analogWrite(blue, blueBright);
  delay(100);
}

