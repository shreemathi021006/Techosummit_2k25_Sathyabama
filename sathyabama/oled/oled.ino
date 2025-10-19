#include <Wire.h>                // For I2C
#include <Adafruit_GFX.h>        // Graphics library
#include <Adafruit_SSD1306.h>    // OLED driver

#define SCREEN_WIDTH 128 // OLED width
#define SCREEN_HEIGHT 64 // OLED height

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Initialize display with I2C address 0x3C (most common)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.begin(9600);
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Stop here if OLED not found
  }

  display.clearDisplay();              // Clear screen
  display.setTextSize(2);              // Text size
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 0);
  // Start at top-left
  
  display.println("door open");
  display.setCursor(0, 20);
  // Start at top-left
  
  display.println("object not taken");
  display.display();                   // Show on screen
}

void loop() {
  // Nothing here (static text)
}
