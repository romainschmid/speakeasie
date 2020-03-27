#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define MX_LINE 10
#define MX_COL 10

typedef unsigned char uint8;  // 8 bits non signé
typedef char int8;  // 8 bits signé

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT (MX_LINE * MX_COL)

// create struct to store all variables in one
typedef struct
{
  uint8 red;
  uint8 green;
  uint8 blue;
  uint8 ind;
  uint8 seg;
}PIXEL_t;

PIXEL_t matrix[MX_LINE][MX_COL];

uint8 line, col;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
    uint8 red = 255;
    uint8 green = 0;
    uint8 blue = 0;

    for(line = 0 ; line < MX_LINE ; line++)
    {
        for(col = 0 ; col < MX_LINE ; col++)
        {
            matrix[line][col].red = red;
            matrix[line][col].blue = blue;
            matrix[line][col].green = green;
        }
    }
    strip.show();

}