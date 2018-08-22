#include <Arduino.h>

/************************
 * Constants
 ************************/
// Pin definitions
static const uint8_t BUTTON_PIN = 16;

// Delay before accepting button state change for debouncing purposes
static const unsigned long LOCKOUT_DELAY_MILLIS = 2;

/************************
 * Variables
 ************************/
// True if the button has been pressed but not actioned
volatile bool gButtonStateChangeToAction = false;
// The debounced button state
uint8_t gButtonState = 0;

// The number of button interrupts received
uint16_t gButtonInterrupts = 0;

/*********************
 * Interrupt routines
 *********************/
void buttonPressedISR() {
  unsigned long currentMillis = millis();
  cli();
  static unsigned long lastButtonStateChangeTime = 0;
  gButtonInterrupts++;
  uint8_t newButtonState = digitalReadFast(BUTTON_PIN);
  // Make sure we're not in the lockout period
  if (currentMillis - lastButtonStateChangeTime > LOCKOUT_DELAY_MILLIS) {
    // Only do anything if we've changed state
    if (gButtonState != newButtonState) {
      lastButtonStateChangeTime = currentMillis;
      gButtonStateChangeToAction = true;
      gButtonState = newButtonState;
    }
  }
  sei();
}

/*********************
 * Entry Point methods
 *********************/
// Setup function - executes once on startup
void setup() {
  // Set up pins and internals
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonPressedISR, CHANGE);
  Serial.begin(115200);
}

// Loop function - loops :)
void loop() {
  static uint16_t buttonPressesProcessed = 0;
  // Check to see if the user has pressed the button
  if (gButtonStateChangeToAction && gButtonState == HIGH) {
    buttonPressesProcessed++;
    Serial.println(String(buttonPressesProcessed) + "/" + String(gButtonInterrupts) + ": Button pressed");
    gButtonStateChangeToAction = false;
  }
}
