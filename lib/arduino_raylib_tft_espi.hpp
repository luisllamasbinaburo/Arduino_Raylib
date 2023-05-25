#pragma once

#include "../lib/raylib/src/raylib.h"
#include "../lib/raylib/src/raymath.h"

#include "arduino_raylib_tft_espi.hpp"


#include <stdlib.h>
#include <iostream>

#define TFT_BLACK       0x0000
#define TFT_NAVY        0x000F
#define TFT_DARKGREEN   0x03E0
#define TFT_DARKCYAN    0x03EF
#define TFT_MAROON      0x7800
#define TFT_PURPLE      0x780F
#define TFT_OLIVE       0x7BE0
#define TFT_LIGHTGREY   0xD69A
#define TFT_DARKGREY    0x7BEF
#define TFT_BLUE        0x001F
#define TFT_GREEN       0x07E0
#define TFT_CYAN        0x07FF
#define TFT_RED         0xF800
#define TFT_MAGENTA     0xF81F
#define TFT_YELLOW      0xFFE0
#define TFT_WHITE       0xFFFF
#define TFT_ORANGE      0xFDA0
#define TFT_GREENYELLOW 0xB7E0
#define TFT_PINK        0xFE19
#define TFT_BROWN       0x9A60
#define TFT_GOLD        0xFEA0
#define TFT_SILVER      0xC618
#define TFT_SKYBLUE     0x867D
#define TFT_VIOLET      0x915C

#ifndef TFT_WIDTH
#define TFT_WIDTH 320
#endif

#ifndef TFT_HEIGHT
#define TFT_HEIGHT 240
#endif

#define TFT_MIN_X 24
#define TFT_MIN_Y 24

#define TFT_X(x) (min(x, TFT_WIDTH) + TFT_MIN_X)
#define TFT_Y(y) (min(y, TFT_HEIGHT) + TFT_MIN_Y)

Color RGB565_TO_COLOR(const std::uint16_t color_rgb565, const float alpha = 1.0)
{
	Color color;
	color.r = static_cast<std::uint8_t>((((((color_rgb565 >> 11) & 0x1F) * 527) + 23) >> 6));
	color.g = static_cast<std::uint8_t>(((((color_rgb565 >> 5) & 0x3F) * 259) + 33) >> 6);
	color.b = static_cast<std::uint8_t>((((color_rgb565 & 0x1F) * 527) + 23) >> 6);
	color.a = static_cast<std::uint8_t>(alpha * 255);

	return color;
}

std::uint16_t COLOR_TO_RGB565(std::uint8_t r, std::uint8_t g, std::uint8_t b)
{
	return (r >> 3) << 11 | (g >> 2) << 5 | b >> 3;
}

std::uint16_t COLOR_TO_RGB565(Color color)
{
	return COLOR_TO_RGB565(color.r, color.g, color.b);
}

class TFT_eSPI
{
public:
	void setRotation(uint8_t m)
	{
	}

	uint8_t getRotation(void)
	{
	}

	void invertDisplay(bool i)
	{
	}

	void drawPixel(int x, int y, Color color)
	{
		DrawRectangle(TFT_X(x), TFT_Y(y), 1, 1, color);
	}

	uint16_t readPixel(int32_t x, int32_t y)
	{
	}

	void drawChar(int32_t x, int32_t y, uint16_t c, uint32_t color, uint32_t bg, uint8_t size)
	{
	}

	void drawLine(int x0, int y0, int x1, int y1, Color color)
	{
		DrawLine(TFT_X(x0), TFT_Y(y0), TFT_X(x1), TFT_Y(y1), color);
	}

	void drawFastVLine(int x0, int y0, int length, Color color)
	{
		DrawLine(TFT_X(x0), TFT_X(y0), TFT_X(x0), TFT_Y(y0 + length), color);
	}

	void drawFastHLine(int x0, int y0, int length, Color color)
	{
		DrawLine(TFT_X(x0), TFT_Y(y0), TFT_X(x0) + (length), TFT_Y(y0), color);
	}

	void drawRect(int x0, int y0, int w, int h, Color color)
	{
		DrawRectangleLines(TFT_X(x0), TFT_Y(y0), w, h, color);
	}

	void fillRect(int x0, int y0, int w, int h, Color color)
	{
		DrawRectangle(TFT_X(x0), TFT_Y(y0), w, h, color);
	}

	void drawCircle(int x0, int y0, int r, Color color)
	{
		DrawCircleLines(TFT_X(x0), TFT_Y(y0), r, color);
	}

	void fillCircle(int x0, int y0, int r, Color color)
	{
		DrawCircle(TFT_X(x0), TFT_Y(y0), r, color);
	}

	void drawRoundRect(int x0, int y0, int w, int h, int radius, Color color)
	{
		Rectangle rec;
		rec.x = TFT_X(x0);
		rec.y = TFT_Y(y0);
		rec.width = w;
		rec.height = h;

		float roundness = (rec.width > rec.height) ? (float)radius / rec.height * 2 : (float)radius / rec.width;

		DrawRectangleRounded(rec, (float)radius, 5, color);
	}

	void fillRoundRect(int x0, int y0, int w, int h, int radius, Color color)
	{
		Rectangle rec;
		rec.x = TFT_X(x0);
		rec.y = TFT_Y(y0);
		rec.width = w;
		rec.height = h;

		float roundness = (rec.width > rec.height) ? (float)radius / rec.height * 2 : (float)radius / rec.width;

		DrawRectangleRoundedLines(rec, (float)radius, 5, 1, color);
	}

	void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, Color color)
	{
		Vector2 v1 = { TFT_X(x0), TFT_Y(y0) };
		Vector2 v2 = { TFT_X(x1), TFT_Y(y1) };
		Vector2 v3 = { TFT_X(x2), TFT_Y(y2) };
		DrawTriangleLines(v1, v2, v3, color);
	}

	void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, Color color)
	{
		Vector2 v1 = { TFT_X(x0), TFT_Y(y0) };
		Vector2 v2 = { TFT_X(x1), TFT_Y(y1) };
		Vector2 v3 = { TFT_X(x2), TFT_Y(y2) };
		DrawTriangle(v1, v2, v3, color);
	}

	void fillScreen(Color color)
	{
		DrawRectangle(24, 24, TFT_WIDTH, TFT_HEIGHT, color);
	}

	void drawString(const char* string, int32_t x, int32_t y, uint8_t font)
	{
		DrawText(string, TFT_X(x), TFT_Y(y), font, WHITE);
	}

	void drawString(const char* string, int32_t x, int32_t y)
	{
		DrawText(string, TFT_X(x), TFT_Y(y), 10, WHITE);
	}

	void drawPixel(int x, int y, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawPixel(x, y, color);
	}

	void drawLine(int x0, int y0, int x1, int y1, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawLine(x0, y0, x1, y1, color);
	}

	void drawFastVLine(int x0, int y0, int length, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawFastVLine(x0, y0, length, color);
	}

	void drawFastHLine(int x0, int y0, int length, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawFastHLine(x0, y0, length, color);
	}

	void drawRect(int x0, int y0, int w, int h, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawRect(x0, y0, w, h, color);
	}

	void fillRect(int x0, int y0, int w, int h, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		fillRect(x0, y0, w, h, color);
	}

	void drawCircle(int x0, int y0, int r, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawCircle(x0, y0, r, color);
	}

	void fillCircle(int x0, int y0, int r, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		fillCircle(x0, y0, r, color);
	}

	void drawRoundRect(int x0, int y0, int w, int h, int radius, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawRoundRect(x0, y0, w, h, radius, color);
	}

	void fillRoundRect(int x0, int y0, int w, int h, int radius, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		fillRoundRect(x0, y0, w, h, radius, color);
	}

	void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		drawTriangle(x0, y0, x1, y1, x2, y2, color);
	}

	void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		fillTriangle(x0, y0, x1, y1, x2, y2, color);
	}

	void fillScreen(int rgb565)
	{
		Color color = RGB565_TO_COLOR(rgb565);
		fillScreen(color);
	}

	void pushImage(int32_t x0, int32_t y0, int32_t w, int32_t h, const uint16_t* data)
	{
		for (size_t x = 0; x < w; x++)
		{
			for (size_t y = 0; y < h; y++)
			{
				drawPixel(x0 + x, y0 + y, data[x + y * w]);
			}
		}
	}

	void pushSprite(int x, int y)
	{

	}
};


class TFT_eSprite : public TFT_eSPI
{

public:

	explicit TFT_eSprite(TFT_eSPI* tft)
	{
	}

	~TFT_eSprite(void)
	{
	}

	void* createSprite(int16_t width, int16_t height, uint8_t frames = 1)
	{
		return nullptr;
	}

	void* getPointer(void)
	{
		return nullptr;
	}

	bool created(void)
	{
		return true;
	}

	void deleteSprite(void)
	{
	}

	void* frameBuffer(int8_t f)
	{
		return nullptr;
	}

	void* setColorDepth(int8_t b)
	{
		return nullptr;
	}

	int8_t getColorDepth(void)
	{
		return 2;
	}

	void setPaletteColor(uint8_t index, uint16_t color)
	{
	}

	uint16_t getPaletteColor(uint8_t index)
	{
		return 2;
	}

	void setBitmapColor(uint16_t fg, uint16_t bg)
	{
	}

	void drawChar(int32_t x, int32_t y, uint16_t c, uint32_t color, uint32_t bg, uint8_t font)
	{
	}

	void fillSprite(uint32_t color)
	{
	}

	void setWindow(int32_t x0, int32_t y0, int32_t x1, int32_t y1)
	{
	}

	void pushColor(uint16_t color)
	{
	}

	void pushColor(uint16_t color, uint32_t len)
	{
	}

	void writeColor(uint16_t color)
	{
	}

	void setScrollRect(int32_t x, int32_t y, int32_t w, int32_t h, uint16_t color = TFT_BLACK)
	{
	}

	void scroll(int16_t dx, int16_t dy = 0)
	{
	}

	void setRotation(uint8_t rotation)
	{
	}

	uint8_t getRotation(void)
	{
		return 0;
	}

	bool getRotatedBounds(int16_t angle, int16_t* min_x, int16_t* min_y, int16_t* max_x, int16_t* max_y)
	{
		return true;
	}

	bool getRotatedBounds(TFT_eSprite* spr, int16_t angle, int16_t* min_x, int16_t* min_y,
		int16_t* max_x, int16_t* max_y)
	{
		return true;
	}

	void getRotatedBounds(int16_t angle, int16_t w, int16_t h, int16_t xp, int16_t yp,
		int16_t* min_x, int16_t* min_y, int16_t* max_x, int16_t* max_y)
	{
	}

	uint16_t readPixel(int32_t x0, int32_t y0)
	{
		return 0;
	}

	uint16_t readPixelValue(int32_t x, int32_t y)
	{
		return 0;
	}

	void pushSprite(int32_t x, int32_t y)
	{
	}

	void pushSprite(int32_t x, int32_t y, uint16_t transparent)
	{
	}

	bool pushSprite(int32_t tx, int32_t ty, int32_t sx, int32_t sy, int32_t sw, int32_t sh)
	{
		return true;
	}

	bool pushToSprite(TFT_eSprite* dspr, int32_t x, int32_t y)
	{
		return true;
	}

	bool pushToSprite(TFT_eSprite* dspr, int32_t x, int32_t y, uint16_t transparent)
	{
		return true;
	}

	int16_t drawChar(uint16_t uniCode, int32_t x, int32_t y, uint8_t font)
	{
		return 0;
	}

	int16_t drawChar(uint16_t uniCode, int32_t x, int32_t y)
	{
		return 0;
	}

	void drawGlyph(uint16_t code)
	{
	}

	void printToSprite(std::string string)
	{
	}

	void printToSprite(char* cbuffer, uint16_t len)
	{
	}

	int16_t printToSprite(int16_t x, int16_t y, uint16_t index)
	{
		return 0;
	}
};