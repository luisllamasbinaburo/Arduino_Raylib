#pragma once

#include "raylib.h"
#include "raymath.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdlib.h>
#include <iostream>

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

#define CHANGE 1
#define FALLING 2
#define RISING 3

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

#define interrupts() sei()
#define noInterrupts() cli()

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#include <tft.hpp>

bool TextmultiBox003EditMode = false;
char TextmultiBox003Text[128] = "SAMPLE TEXT";
bool TextBox004EditMode = false;
char TextBox004Text[128] = "SAMPLE TEXT";

bool Gpio01Enabled = false;
bool Gpio02Enabled = false;
bool Gpio03Enabled = false;
bool Gpio04Enabled = false;
bool Gpio05Enabled = false;
bool Gpio06Enabled = false;
bool Gpio07Enabled = false;
bool Gpio08Enabled = false;
bool Gpio09Enabled = false;
bool Gpio10Enabled = false;
bool Gpio11Enabled = false;
bool Gpio12Enabled = false;
bool Gpio13Enabled = false;
bool Gpio14Enabled = false;
bool Gpio15Enabled = false;
bool Gpio16Enabled = false;

bool Gpio01Checked = false;
bool Gpio02Checked = false;
bool Gpio03Checked = false;
bool Gpio04Checked = false;
bool Gpio05Checked = false;
bool Gpio06Checked = false;
bool Gpio07Checked = false;
bool Gpio08Checked = false;
bool Gpio09Checked = false;
bool Gpio10Checked = false;
bool Gpio11Checked = false;
bool Gpio12Checked = false;
bool Gpio13Checked = false;
bool Gpio14Checked = false;
bool Gpio15Checked = false;
bool Gpio16Checked = false;

void loop();
void setup();

void pinMode(uint8_t pin, uint8_t mode)
{
    if(pin == 1)  Gpio01Enabled = (mode == OUTPUT);
    if(pin == 2)  Gpio02Enabled = (mode == OUTPUT);
    if(pin == 3)  Gpio03Enabled = (mode == OUTPUT);
    if(pin == 4)  Gpio04Enabled = (mode == OUTPUT);
    if(pin == 5)  Gpio05Enabled = (mode == OUTPUT);
    if(pin == 6)  Gpio06Enabled = (mode == OUTPUT);
    if(pin == 7)  Gpio07Enabled = (mode == OUTPUT);
    if(pin == 8)  Gpio08Enabled = (mode == OUTPUT);
    if(pin == 9)  Gpio09Enabled = (mode == OUTPUT);
    if(pin == 10) Gpio10Enabled = (mode == OUTPUT);
    if(pin == 11) Gpio11Enabled = (mode == OUTPUT);
    if(pin == 12) Gpio12Enabled = (mode == OUTPUT);
    if(pin == 13) Gpio13Enabled = (mode == OUTPUT);
    if(pin == 14) Gpio14Enabled = (mode == OUTPUT);
    if(pin == 15) Gpio15Enabled = (mode == OUTPUT);
    if(pin == 16) Gpio16Enabled = (mode == OUTPUT);
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    if(pin == 1)  Gpio01Checked = (val == HIGH);
    if(pin == 2)  Gpio02Checked = (val == HIGH);
    if(pin == 3)  Gpio03Checked = (val == HIGH);
    if(pin == 4)  Gpio04Checked = (val == HIGH);
    if(pin == 5)  Gpio05Checked = (val == HIGH);
    if(pin == 6)  Gpio06Checked = (val == HIGH);
    if(pin == 7)  Gpio07Checked = (val == HIGH);
    if(pin == 8)  Gpio08Checked = (val == HIGH);
    if(pin == 9)  Gpio09Checked = (val == HIGH);
    if(pin == 10) Gpio10Checked = (val == HIGH);
    if(pin == 11) Gpio11Checked = (val == HIGH);
    if(pin == 12) Gpio12Checked = (val == HIGH);
    if(pin == 13) Gpio13Checked = (val == HIGH);
    if(pin == 14) Gpio14Checked = (val == HIGH);
    if(pin == 15) Gpio15Checked = (val == HIGH);
    if(pin == 16) Gpio16Checked = (val == HIGH);    
}

int digitalRead(uint8_t pin)
{
    if(pin == 1)  return Gpio01Checked ? HIGH : LOW;
    if(pin == 2)  return Gpio02Checked ? HIGH : LOW;
    if(pin == 3)  return Gpio03Checked ? HIGH : LOW;
    if(pin == 4)  return Gpio04Checked ? HIGH : LOW;
    if(pin == 5)  return Gpio05Checked ? HIGH : LOW;
    if(pin == 6)  return Gpio06Checked ? HIGH : LOW;
    if(pin == 7)  return Gpio07Checked ? HIGH : LOW;
    if(pin == 8)  return Gpio08Checked ? HIGH : LOW;
    if(pin == 9)  return Gpio09Checked ? HIGH : LOW;
    if(pin == 10) return Gpio10Checked ? HIGH : LOW;
    if(pin == 11) return Gpio11Checked ? HIGH : LOW;
    if(pin == 12) return Gpio12Checked ? HIGH : LOW;
    if(pin == 13) return Gpio13Checked ? HIGH : LOW;
    if(pin == 14) return Gpio14Checked ? HIGH : LOW;
    if(pin == 15) return Gpio15Checked ? HIGH : LOW;
    if(pin == 16) return Gpio16Checked ? HIGH : LOW;
}

void analogWrite(uint8_t pin, int val)
{
}

int analogRead(uint8_t pin)
{
    return 0;
}

void analogReference(uint8_t mode)
{
}

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return 0;
}
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout)
{
    return 0;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
}
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder)
{
    return 0;
}
void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode)
{
}

void detachInterrupt(uint8_t interruptNum)
{
}

unsigned long millis(void)
{
    return GetTime() * 1000;
}
unsigned long micros(void)
{
    return GetTime() * 1000;
}

void delay(unsigned long ms)
{
    WaitTime((float)ms / 1000);
}

void delayMicroseconds(unsigned int us)
{
    WaitTime((float)us / 1000000);
}

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

void print(char* t) {std::cout << t ;}
void print(const char t[]) {std::cout << t ;}
void print(char t) {std::cout << t ;}
void print(unsigned char t, int = DEC) {std::cout << t ;}
void print(int t, int = DEC) {std::cout << t ;}
void print(unsigned int t, int = DEC) {std::cout << t ;}
void print(long t, int = DEC) {std::cout << t ;}
void print(unsigned long t, int = DEC) {std::cout << t ;}
void print(long long t, int = DEC) {std::cout << t ;}
void print(unsigned long long t, int = DEC) {std::cout << t ;}
void print(double t, int = 2) {std::cout << t ;}

void println(char* t) {std::cout << t ;}
void println(const char t[]) {std::cout << t << "\n";}
void println(char t) {std::cout << t << "\n";}
void println(unsigned char t, int = DEC) {std::cout << t << "\n";}
void println(int t, int = DEC) {std::cout << t << "\n";}
void println(unsigned int t, int = DEC) {std::cout << t << "\n";}
void println(long t, int = DEC) {std::cout << t << "\n";}
void println(unsigned long t, int = DEC) {std::cout << t << "\n";}
void println(long long t, int = DEC) {std::cout << t << "\n";}
void println(unsigned long long t, int = DEC) {std::cout << t << "\n";}
void println(double t, int = 2) {std::cout << t << "\n";}


void RAYLIB_RENDER(void (*render)())
{
    BeginDrawing();
    
    render();
    
    DrawFPS(410, 25);
    EndDrawing();
}

int value = 50;
void drawGUI()
{
    ClearBackground(WHITE);

    GuiLabel({ 24, 4, 120, 24 }, "TFT / DISPLAY");
    DrawRectangleLines(24 - 1, 24 - 1, 480 + 2, 320 + 2, SKYBLUE);
    DrawRectangle(24, 24, 480, 320, LIGHTGRAY);

    
    GuiLabel({ 528, 4, 120, 24 }, "DIGITAL GPIO");
    if(Gpio01Enabled == false) {DrawCircle(524 + 12,  40 - 10 + 12, 8, Gpio01Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28,  40 - 10, 100, 24 }, "GPIO 01");}
    if(Gpio02Enabled == false) {DrawCircle(524 + 12,  70 - 10 + 12, 8, Gpio02Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28,  70 - 10, 100, 24 }, "GPIO 02");}
    if(Gpio03Enabled == false) {DrawCircle(524 + 12, 100 - 10 + 12, 8, Gpio03Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28, 100 - 10, 100, 24 }, "GPIO 03");}
    if(Gpio04Enabled == false) {DrawCircle(524 + 12, 130 - 10 + 12, 8, Gpio04Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28, 130 - 10, 100, 24 }, "GPIO 04");}
    if(Gpio05Enabled == false) {DrawCircle(524 + 12, 160 - 10 + 12, 8, Gpio05Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28, 160 - 10, 100, 24 }, "GPIO 05");}
    if(Gpio06Enabled == false) {DrawCircle(524 + 12, 190 - 10 + 12, 8, Gpio06Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28, 190 - 10, 100, 24 }, "GPIO 06");}
    if(Gpio07Enabled == false) {DrawCircle(524 + 12, 220 - 10 + 12, 8, Gpio07Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28, 220 - 10, 100, 24 }, "GPIO 07");}
    if(Gpio08Enabled == false) {DrawCircle(524 + 12, 250 - 10 + 12, 8, Gpio08Checked ? RED : LIGHTGRAY); GuiLabel({ 524 + 28, 250 - 10, 100, 24 }, "GPIO 08");}
    if(Gpio09Enabled == false) {DrawCircle(674 + 12,  40 - 10 + 12, 8, Gpio09Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28,  40 - 10, 100, 24 }, "GPIO 09");}
    if(Gpio10Enabled == false) {DrawCircle(674 + 12,  70 - 10 + 12, 8, Gpio10Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28,  70 - 10, 100, 24 }, "GPIO 10");}
    if(Gpio11Enabled == false) {DrawCircle(674 + 12, 100 - 10 + 12, 8, Gpio11Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28, 100 - 10, 100, 24 }, "GPIO 11");}
    if(Gpio12Enabled == false) {DrawCircle(674 + 12, 130 - 10 + 12, 8, Gpio12Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28, 130 - 10, 100, 24 }, "GPIO 12");}
    if(Gpio13Enabled == false) {DrawCircle(674 + 12, 160 - 10 + 12, 8, Gpio13Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28, 160 - 10, 100, 24 }, "GPIO 13");}
    if(Gpio14Enabled == false) {DrawCircle(674 + 12, 190 - 10 + 12, 8, Gpio14Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28, 190 - 10, 100, 24 }, "GPIO 14");}
    if(Gpio15Enabled == false) {DrawCircle(674 + 12, 220 - 10 + 12, 8, Gpio15Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28, 220 - 10, 100, 24 }, "GPIO 15");}
    if(Gpio16Enabled == false) {DrawCircle(674 + 12, 250 - 10 + 12, 8, Gpio16Checked ? RED : LIGHTGRAY); GuiLabel({ 674 + 28, 250 - 10, 100, 24 }, "GPIO 16");}

    if(Gpio01Enabled) Gpio01Checked = GuiCheckBox({ 524,  40 - 10, 24, 24 }, "GPIO 01", Gpio01Checked);
    if(Gpio02Enabled) Gpio02Checked = GuiCheckBox({ 524,  70 - 10, 24, 24 }, "GPIO 02", Gpio02Checked);
    if(Gpio03Enabled) Gpio03Checked = GuiCheckBox({ 524, 100 - 10, 24, 24 }, "GPIO 03", Gpio03Checked);
    if(Gpio04Enabled) Gpio04Checked = GuiCheckBox({ 524, 130 - 10, 24, 24 }, "GPIO 04", Gpio04Checked);
    if(Gpio05Enabled) Gpio05Checked = GuiCheckBox({ 524, 160 - 10, 24, 24 }, "GPIO 05", Gpio05Checked);
    if(Gpio06Enabled) Gpio06Checked = GuiCheckBox({ 524, 190 - 10, 24, 24 }, "GPIO 06", Gpio06Checked);
    if(Gpio07Enabled) Gpio07Checked = GuiCheckBox({ 524, 220 - 10, 24, 24 }, "GPIO 07", Gpio07Checked);
    if(Gpio08Enabled) Gpio08Checked = GuiCheckBox({ 524, 250 - 10, 24, 24 }, "GPIO 08", Gpio08Checked);
    if(Gpio09Enabled) Gpio09Checked = GuiCheckBox({ 674,  40 - 10, 24, 24 }, "GPIO 09", Gpio09Checked);
    if(Gpio10Enabled) Gpio10Checked = GuiCheckBox({ 674,  70 - 10, 24, 24 }, "GPIO 10", Gpio10Checked);
    if(Gpio11Enabled) Gpio11Checked = GuiCheckBox({ 674, 100 - 10, 24, 24 }, "GPIO 11", Gpio11Checked);
    if(Gpio12Enabled) Gpio12Checked = GuiCheckBox({ 674, 130 - 10, 24, 24 }, "GPIO 12", Gpio12Checked);
    if(Gpio13Enabled) Gpio13Checked = GuiCheckBox({ 674, 160 - 10, 24, 24 }, "GPIO 13", Gpio13Checked);
    if(Gpio14Enabled) Gpio14Checked = GuiCheckBox({ 674, 190 - 10, 24, 24 }, "GPIO 14", Gpio14Checked);
    if(Gpio15Enabled) Gpio15Checked = GuiCheckBox({ 674, 220 - 10, 24, 24 }, "GPIO 15", Gpio15Checked);
    if(Gpio16Enabled) Gpio16Checked = GuiCheckBox({ 674, 250 - 10, 24, 24 }, "GPIO 16", Gpio16Checked);
}

int main(void)
{
    InitWindow(780, 380, "ArduinoRaylib");

    setup();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(IsMouseButtonReleased(0))
        {
            auto mouse = GetMousePosition();
        }

        drawGUI();
        loop();
    }

    CloseWindow();
    return 0;
}
