//Sound Sensor needs
#define SoundSensorPin A0  //this pin read the analog voltage from the sound level meter
#define VREF 5.0           //voltage on AREF pin,default:operating voltage
float dbValue;             //declares the variable globally
String noiseLevel;

//LED Strip needs
#include <Adafruit_NeoPixel.h> 
#define NUMPIXELS    8    
#define PIN 6
Adafruit_NeoPixel pixels(NUMPIXELS, PIN); //I don't understand this line


//LCD Screen needs
#include "DFRobot_RGBLCD1602.h"
DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x60 ,/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show


void setup() {
  Serial.begin(9600);
  pixels.begin();
  lcd.init(); //initialize the LCD
}

void loop() {
pixels.clear(); //clears light at first

//reads the decibel value
  float voltageValue;
  voltageValue = analogRead(SoundSensorPin) / 1024.0 * VREF;
  dbValue = voltageValue * 50.0;  //convert voltage to decibel value
  setLED(); //turns on approproiate led color
  Serial.print(dbValue, 0);
  Serial.println(" dBA");
  //delay(1000); //set frequency of calling for dBValue */

//prints data to the LCD screen 
    lcd.setCursor(0,0);
    lcd.print(noiseLevel); //prints the noise level
    lcd.setCursor(0,1);
    lcd.print(dbValue, 0); //prints the decibel level
    lcd.print(" dBA");
      //  }
    //}
    delay(5000); //set frequency of calling for dBValue */

}

void setLED() {
    pixels.clear();
    if (dbValue > 100) {
     pixels.setPixelColor(0, 75, 0, 0);//red
     pixels.show();
    noiseLevel = "Dangerous";
    Serial.println(noiseLevel);

  } else if (dbValue < 100 && dbValue > 70) {
     pixels.setPixelColor(0, 75, 75, 0);//yellow
     pixels.show();
    noiseLevel = "Hazardous ";
    Serial.println(noiseLevel);


  } else if (dbValue < 70 && dbValue > 0) {
     pixels.setPixelColor(0, 0, 75, 0);//green
     pixels.show();
    noiseLevel = "Acceptable";
    Serial.println(noiseLevel);

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