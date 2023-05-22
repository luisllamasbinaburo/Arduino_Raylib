# Raylib Arduino

The Raylib Arduino project is a library that allows us to use Raylib to simulate the same visual output we would have in an Arduino program. 

This tool was created because I like creating libraries for Arduino, specially visual effects and animations using a TFT and ESP32 (for example).

For me its very convenient for me to be able to debug and visualize the results in the computer, without having to upload the project to an actual Arduino.

![](https://github.com/luisllamasbinaburo/raylib_arduino/blob/master/screenshot.png)

### Key Features
- Facilitates the development of Arduino applications
- Offers a syntax similar to that of a real program
- Allow use the computer debug
- Utilizes Raylib to provide a graphical visualization similar to TFT_eSPI

### What it is

It's a tool designed to streamline the development process of Arduino applications, by employing a syntax similar to that of a real Arduino program.

Some funtions like `millis()`, `delay(2000)`, are provided. Also some 'mock' functions, like `digitalRead()` or `digitalWrite`. (mock means that doesn't have a real physical effect, but can be used to simulate real world behavior). Pinout are generic (1 to 16 GPIO), and not specific to any board.

It uses Raylib and Raygui to create visual programs and animations. A simulation of the real TFT are provided. I use the sintax that you can find, for example, in Adafruit GPX or TFT_eSPI.

### What it's not

It's not a complete simulator of Arduino code or hardware (and never will be). It does not provide precise emulation of all Arduino-specific components and functionalities. Of course, third party libraries for Arduino are not supported.

### HOW TO USE

Just clone the repo, and replace the code inside `main.hpp` with you Arduino code.

For example
```cpp
#include <RaylibArduino.hpp>

TFT_eSPI lcd = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&lcd);

static const uint16_t icon[1298] = {
   // omited
};

void Update()
{
}

void Render()
{
  lcd.fillScreen(TFT_BLACK);

  lcd.drawCircle(40, 40, 5, TFT_RED);
  lcd.drawLine(40, 40, 80, 80, TFT_BLUE);
  lcd.drawString("HOLA", 200, 200, 12);

  sprite.pushImage(120, 40, 22, 59, icon);
  sprite.pushSprite(0, 0);
}

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  sprite.createSprite(22, 59);
}
```

### TO-DO
- [x] Millis, micros, delay, and delay micros
- [x] Serial.print to console output
- [x] pinmode, digitalWrite, digitalRead mocks (16 gpio simulated)
- [x] TFT_eSPI drawing funtions (point, line, circule, rectangule...)
- [x] RGB565 - RGB conversion
- [x] Pushimage from RGB565 uint16 array 
- [x] TFT_eSPI_Sprite basic sintax (but it works drawing directly on stream, not like a buffer)
- [ ] analogWrite, analogRead
- [ ] SPI, I2C mocks
