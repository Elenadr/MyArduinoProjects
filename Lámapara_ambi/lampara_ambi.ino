/*
  Modos:
  
  FIX_MODE: The color doesn't change.
  RANDOM_HUE_MODE: Color fades to random hue.
  RAINBOW_HUE_MODE: Fading from red to red, going through all hue values.
  RED_MODE: Random fade between redish colors.
  BLUE_MODE: Random fade between blueish colors.
  GREEN_MODE: Random fade between greenish colors.
  FIRE_MODE: Fire effect. Like an electronic candle.
*/


#include <RGBMood.h>

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int ldrPin = 0;

RGBMood mood(redPin, greenPin, bluePin); 


void setup() 
{
  pinMode(ldrPin, INPUT);
  mood.setMode(RGBMood::RANDOM_HUE_MODE);
  mood.setHoldingTime(2000);
  mood.setFadingSteps(150);
  mood.setFadingSpeed(50);
  mood.setHSB(random(359), 255, 255);
}

void loop() 
{
  int ambientLight = analogRead(ldrPin);
  if(ambientLight > 600)
  {
    mood.tick();
  }
  else
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }

}
