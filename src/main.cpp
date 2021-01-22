#include <Arduino.h>
#include <Adafruit_Neopixel.h>
#include <Stream.h>

#define PIN1           17
#define PIN2           18
#define NUMPIXELS1     3
#define NUMPIXELS2     3

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);

void serialFlush(Stream* s){
  while(s->available() > 0){
    char t = s->read();
  }
}

void setup(){
  pixels1.begin();
  pixels2.begin();
  for(int i=0; i<3; i++){
    pixels1.setPixelColor(i, pixels1.Color(0,30,120));
    pixels2.setPixelColor(i, pixels2.Color(0,30,120));
  }
  pixels1.show();
  pixels2.show();

  Serial.begin(115200);
  Serial1.begin(115200, SERIAL_8N1, 16, 4);
  Serial.println("Startup Serial");
}

void loop(){
  // Read the input
  if(Serial1.available() && Serial.available()){
    int val_1 = Serial1.read();
    int val_2 = Serial.read();

    serialFlush(&Serial);
    serialFlush(&Serial1);

    // Echo the input
    Serial.println(val_1);
    Serial.println(val_2);

    if(abs(val_1) > 0){
      if(abs(val_1) >= 55){
        pixels1.setPixelColor(0, pixels1.Color(150,0,0));
        pixels1.setPixelColor(1, pixels1.Color(0,0,0));
        pixels1.setPixelColor(2, pixels1.Color(0,0,0));
        pixels1.show();
      }
      if(abs(val_1) >= 40 && abs(val_1) < 55){
        pixels1.setPixelColor(0, pixels1.Color(150,0,0));
        pixels1.setPixelColor(1, pixels1.Color(100,50,0));
        pixels1.setPixelColor(2, pixels1.Color(0,0,0));
        pixels1.show();
      }
      if(abs(val_1) >= 20 && abs(val_1) < 40){
        pixels1.setPixelColor(0, pixels1.Color(150,0,0));
        pixels1.setPixelColor(1, pixels1.Color(100,50,0));
        pixels1.setPixelColor(2, pixels1.Color(0,150,0));
        pixels1.show();
      }
    }

    if(abs(val_2) > 0){
      if(abs(val_2) >= 55){
        pixels2.setPixelColor(0, pixels2.Color(150,0,0));
        pixels2.setPixelColor(1, pixels2.Color(0,0,0));
        pixels2.setPixelColor(2, pixels2.Color(0,0,0));
        pixels2.show();
      }
      if(abs(val_2) >= 40 && abs(val_2) < 55){
        pixels2.setPixelColor(0, pixels2.Color(150,0,0));
        pixels2.setPixelColor(1, pixels2.Color(100,50,0));
        pixels2.setPixelColor(2, pixels2.Color(0,0,0));
        pixels2.show();
      }
      if(abs(val_2) >= 20 && abs(val_2) < 40){
        pixels2.setPixelColor(0, pixels2.Color(150,0,0));
        pixels2.setPixelColor(1, pixels2.Color(100,50,0));
        pixels2.setPixelColor(2, pixels2.Color(0,150,0));
        pixels2.show();
      }
    }
  }
}