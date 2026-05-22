#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
void setup();
void loop();
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int signalPin = 2;
const int freezePin = 3;
const int zoomPin = 4;

bool isFrozen = false;
int zoomSteps[] = {10, 50, 100, 500, 1000, 2000};
int zoomIdx = 1; // Starts at 50us
int values[128];

void setup()
{
  Serial.begin(115200);

  Wire.begin(8,9);

  // Pins with internal resistors
  pinMode(signalPin, INPUT_PULLDOWN);
  pinMode(freezePin, INPUT_PULLUP);
  pinMode(zoomPin, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED failed");
    for (;;)
      ;
  }

  display.clearDisplay();
  display.display();
}

void loop()
{
  // 1. Button handling (Freeze & Zoom)
  if (digitalRead(freezePin) == LOW)
  {
    isFrozen = !isFrozen;
    delay(250); // Simple debounce
  }

  if (digitalRead(zoomPin) == LOW)
  {
    zoomIdx = (zoomIdx + 1) % 6;
    delay(250);
  }

  // 2. If not frozen, perform sampling
  if (!isFrozen)
  {
    // Measure frequency and duty cycle
    unsigned long highT = pulseIn(signalPin, HIGH, 100000);
    unsigned long lowT = pulseIn(signalPin, LOW, 100000);

    float freq = 0;
    float duty = 0;

    if (highT + lowT > 0)
    {
      freq = 1000000.0 / (highT + lowT);
      duty = (float(highT) / (highT + lowT)) * 100.0;
    }

    // Fast sampling for waveform display
    for (int i = 0; i < 128; i++)
    {
      values[i] = digitalRead(signalPin);
      delayMicroseconds(zoomSteps[zoomIdx]);
    }

    // 3. Draw on the display
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    // Display frequency and duty cycle (top area)
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("F:");
    display.print((int)freq);
    display.print("Hz");

    display.setCursor(70, 0);
    display.print("D:");
    display.print((int)duty);
    display.print("%");

    // Display zoom level (bottom right)
    display.setCursor(85, 56);
    display.print("Z:");
    display.print(zoomSteps[zoomIdx]);

    // Draw waveform (center of the screen)
    for (int i = 0; i < 127; i++)
    {
      int y1 = (values[i] == HIGH) ? 20 : 50;
      int y2 = (values[i + 1] == HIGH) ? 20 : 50;
      display.drawLine(i, y1, i + 1, y2, SSD1306_WHITE);
    }

    display.display();
  }
  else
  {
    // If frozen, just show "HOLD" without clearing the waveform
    display.fillRect(45, 56, 40, 8, SSD1306_BLACK); // Clear text area
    display.setCursor(50, 56);
    display.print("HOLD");
    display.display();
  }
}