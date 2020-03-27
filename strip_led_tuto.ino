#include <Adafruit_NeoPixel.h>

typedef unsigned char uint8;  // 8 bits non signé
typedef char int8;  // 8 bits signé

#define MX_LINE           10
#define MX_COL            10

typedef struct
{
  uint8 red;
  uint8 green;
  uint8 blue;
  uint8 ind;
  uint8 seg;
}PIXEL_t;

PIXEL_t matrix[MX_LINE][MX_COL];

#define LED_PIN    6
 
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT (MX_LINE * MX_COL)
 
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int8 line,col;

void setup() 
{
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


void loop() 
{
    uint8 red = 0;
    uint8 green = 100;
    uint8 blue = 0;

    uint8 ledNo = 0;
    uint8 fxStep = 0;
  
    for( line = 0 ; line < MX_LINE ; line++)
    {
        for( col = 0 ; col < MX_COL ; col++)
        {
        matrix[line][col].red = red++;
        matrix[line][col].green = green--;
        matrix[line][col].blue = blue;  
        }
    }

  for( line = 0 ; line < MX_LINE ; line++)
  {
    for( col = 0 ; col < MX_COL ; col++)
    {
    ledNo = CalcLedNo(line,col);
    strip.setPixelColor(ledNo, matrix[line][col].red, matrix[line][col].green, matrix[line][col].blue);
    strip.show();
    delay(50);       
    }
  }
       //calcul du numéro de la led qui correspond à la position de la matrice
    for( fxStep = 0 ; fxStep <= MX_LINE ; fxStep++)
    { 
        for( line = 0 ; line < MX_LINE ; line++)
        {
            for( col = 0 ; col < MX_COL ; col++)
                {
        ledNo = CalcLedNo(line,col);
        if(line == fxStep)
          strip.setPixelColor(ledNo, matrix[line][col].red, matrix[line][col].green, matrix[line][col].blue);
        else
           strip.setPixelColor(ledNo, 0,0,0);
    
      }
         strip.show();
        delay(50);     
    }
  }

       //calcul du numéro de la led qui correspond à la position de la matrice
  for( fxStep = 0 ; fxStep <= MX_LINE ; fxStep++)
  { 
    for( col = 0 ; col < MX_COL ; col++)
     {
      for( line = 0 ; line < MX_LINE ; line++)
      {
        ledNo = CalcLedNo(line,col);
        if(col == fxStep)
          strip.setPixelColor(ledNo, matrix[line][col].red, matrix[line][col].green, matrix[line][col].blue);
        else
           strip.setPixelColor(ledNo, 0,0,0);
    
      }
         strip.show();
        delay(50);     
     }
  }

  
}

char CalcLedNo(char line, char col)
{
    if((line % 2) == 0)
    {
        return col + (line * MX_COL);
    }
    else
    {   
          return (MX_COL - col - 1)  + (line * MX_COL);
    }
}