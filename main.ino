#define FASTLED_ALLOW_INTERRUPTS 0

#include <Stepper.h>
#include <FastLED.h>

#define DATA_PIN            13
#define NUM_LEDS            58
#define LED_TYPE            WS2811
#define COLOR_ORDER         GRB
CRGB leds[NUM_LEDS];

const int stepsPerRevolution = 200;
Stepper FishMotor(stepsPerRevolution, 8, 9, 10, 11);
#define LED_BUTTON A0
#define MOTOR_BUTTON A1
bool LED_button_state = 0;
bool motor_button_state = 0;

void setup() {
  pinMode(LED_BUTTON, INPUT_PULLUP);
  analogRead(LED_BUTTON);
  pinMode(MOTOR_BUTTON, INPUT_PULLUP);
  analogRead(MOTOR_BUTTON);

  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FishMotor.setSpeed(200);
}

void loop() {



  if (LED_button_state=1)
  {
    setAll(0x00, 0x00, 0xff);
  }
  else
  {
    setAll(0x00, 0x00, 0x00);
  }

  if(motor_button_state=1)
  {
    FishMotor.step(stepsPerRevolution);
  }
  else
  {
    FishMotor.step(0);
  }
  

  

  FishMotor.step(stepsPerRevolution);
  FastLED.show();
  
  
}

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
