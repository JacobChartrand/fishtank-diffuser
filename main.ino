#define FASTLED_ALLOW_INTERRUPTS 0

#include <Stepper.h>
#include <FastLED.h>

#define DATA_PIN            13
#define NUM_LEDS            100
#define MAX_POWER_MILLIAMPS 500
#define LED_TYPE            WS2811
#define COLOR_ORDER         GRB
CRGB leds[NUM_LEDS];

const int stepsPerRevolution = 200;
Stepper FishMotor(stepsPerRevolution, 8, 9, 10, 11);

bool LED_button_state = 0;
bool motor_button_state = 0;

void setup() {
 
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FishMotor.setSpeed(200);
}

void loop() {

  FishMotor.step(stepsPerRevolution);
  FastLED.show();
  
  
}


