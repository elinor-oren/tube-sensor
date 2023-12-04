//Sound Sensor needs
#define SoundSensorPin A0  //this pin read the analog voltage from the sound level meter
#define VREF 5.0           //voltage on AREF pin,default:operating voltage

//LED Strip needs
#include <Adafruit_NeoPixel.h> //* 5V-powered NeoPixels may require a logic level shifter (e.g. 75HCT245),
#define NUMPIXELS    8    
#define PIN 6

Adafruit_NeoPixel pixels(NUMPIXELS, PIN);
float dbValue;


void setup() {
  Serial.begin(115200);
  pixels.begin();

}

void loop() {
pixels.clear();
//reads the decibel value
  float voltageValue;
  voltageValue = analogRead(SoundSensorPin) / 1024.0 * VREF;
  dbValue = voltageValue * 50.0;  //convert voltage to decibel value
  setLED(); //turns on approproiate led color
  Serial.print(dbValue, 1);
  Serial.println(" dBA");
  delay(5000); //set frequency of calling for dBValue
}

void setLED() {
    pixels.clear();
    if (dbValue > 100) {
     pixels.setPixelColor(0, 150, 0, 0);//red
     pixels.show();
     Serial.println("red");

  } else if (dbValue < 100 && dbValue > 70) {
     pixels.setPixelColor(0, 75, 75, 0);//yellow
     pixels.show();
    Serial.println("yellow");


  } else if (dbValue < 70 && dbValue > 0) {
     pixels.setPixelColor(0, 0, 150, 0);//green
     pixels.show();
    Serial.println("green");

    }
}
/***************************************************
Ethan's tips: /
//when using fill to light all of the LEDS make sure to put 8 for count (bc 8 pixels), 
// consider using map() if changing different amounts of LEDs

/***************************************************
 Adapted from: DFRobot Gravity: Analog Sound Level Meter
 <https://www.dfrobot.com/wiki/index.php/Gravity:_Analog_Sound_Level_Meter_SKU:SEN0232>
 ****************************************************/