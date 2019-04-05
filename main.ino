#include "SPI.h"
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#define OLED_MOSI 9
#define OLED_CLK 10
#define OLED_DC 11
#define OLED_CS 12
#define OLED_RESET 13
#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
Adafruit_BMP085 bmp;

void setup() {
  // инициализация и очистка дисплея
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.display();

  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
}
int a = 0;
void loop() {

  display.setTextSize(1); // установка размера шрифта
  display.setTextColor(WHITE); // установка цвета текста
  display.setCursor(0, 0); // установка курсора

  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;
  a = bmp.readSealevelPressure() / 100;

  display.print("TEMPERATURE: ");
  display.println(bmp.readTemperature());
  display.display();

  if (a > 1015) {
    display.print("RAIN = ");
    display.print("NO");
    display.print(" (");
    display.print(bmp.readSealevelPressure() / 100);
    display.print(")");
    display.display();
  } else if (a <= 1015) {
    display.print("RAIN = ");
    display.print("YES");
    display.print(" (");
    display.print(bmp.readSealevelPressure() / 100);
    display.print(")");
    display.display();
  }
  delay(15000);
  display.clearDisplay();
}
