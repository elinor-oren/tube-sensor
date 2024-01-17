# The Paddingtone
## About
The Paddingtone is a handheld noise monitoring device designed for deployment within the London Underground, stylized in the iconic Underground roundel design. The device is powered by an external battery pack and is easy to transport on the tube, allowing for unobtrusive data collection across Underground lines and stations. The Paddingtone harnesses a Sound Level Meter to collect real-time noise exposure data and provides a safety evaluation of ambient noise levels. This is then visually communicated via an LCD screen and a colour-coded NeoPixel LED array.

https://github.com/elinor-oren/tube-sensor/assets/127933946/9f28a4b6-523c-4c38-82ec-e9a6560cfd23


Together, these components facilitate the collection of environmenal exposure data on the Underground and illuminate the unsafe acoustic conditions for London Undergound commuters. Offering a tangible and visually appealing solution, this project seeks to contribute to the broader discourse on environmental determinants of well-being and foster a healthier public transportation experience.

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

## :small_orange_diamond: Materials + Libraries

![image](https://github.com/elinor-oren/tube-sensor/assets/127933946/0d2ac74d-9797-409e-97cb-e8cfe1c93c10)

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
## :small_orange_diamond: Connecting + Testing the Components
### Circuitry
The decibel sensor and Neopixel LED support 3.3-5V logic, but the LCD Display requires 5V logic. As such, we will be connect to the Arduino Uno to create a 5V circuit. A 5V power supply, such as a portable battery pack, must be connected to the Arduino Uno's USB port to use the device. 

The following connections were used for each component:

* DFRobot Gravity Sound Level meter - connected to Analog pin A0, GND, VCC.
* Waveshare LCD1602 - this LCD1602 requires much fewer connections than most LCDs and uses the I2C communication protocol, which simply means connecting the corresponding pins to the SDA (or A4) pin and SCL (or A5) pin on the Arduino Uno. connected to GND, VCC as well. 
* Neopixel 8 - connected to digital pin 6 for the DIN Arduino signal, GND, VCC. (Be sure that you're not connected to DO or data_out.)
  
<img width="405" alt="schematic_circuit" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/bb6f9408-84ac-45bb-adb6-183870be81d6">
<img height="399" alt="breadboard_circuit" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/ef5e5c21-7ccf-4866-bd77-3cf7ae2c7d09">

I recreated the above circuit on a PCB and soldered the wires in place. I’ve used a copper PCB to stand in as a lighter version of the breadboard to ensure comfort when transporting the Paddingtone device. I laid out my parts and attached additional f/m cables between components and the board to be sure I’d have enough slack to fit everything in the encasement. 

The device has a power consumption of 0.10-0.13A, which means using a portable battery with 5000mAH should allow you to power the device for ~50 hours. 

### Testing
In the final code, the LED and LCD display components depend on the sound sensor’s data readings as an input. It is essential to confirm that each component works individually. Start with the sound sensor component before proceeding to the LED and LCD display.

### :sound: 1. Sound Level Meter 
The Sound Level Meter is almost ready to go out of the packaging.
- [ ] Use the circuit diagram above and the test script below to get the sound meter running with your Arduino.

```
/***************************************************
 DFRobot Gravity: Analog Sound Level Meter
 <https://www.dfrobot.com/wiki/index.php/Gravity:_Analog_Sound_Level_Meter_SKU:SEN0232>

 ***************************************************
 This sample code is used to test the analog sound level meter.

 Created 2017-06-26
 By Jason <jason.ling@dfrobot.com@dfrobot.com>

 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

#define SoundSensorPin A0  //this pin read the analog voltage from the sound level meter
#define VREF  5.0  //voltage 

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    float voltageValue,dbValue;
    voltageValue = analogRead(SoundSensorPin) / 1024.0 * VREF;
    dbValue = voltageValue * 50.0;  //convert voltage to decibel value
    Serial.print(dbValue,0);
    Serial.println(" dBA");
    delay(125); //modify this to increase delay between readings
}
```
  
- [ ] Be sure to view the Serial Monitor to confirm that your data is being output.
<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/b6079d93-9099-4f8c-90e2-32efc867c583">

>source: [Gravity Analog Sound Level Meter Wiki](https://wiki.dfrobot.com/Gravity__Analog_Sound_Level_Meter_SKU_SEN0232)

The final code uses the same set-up as the sample code.

<img width="430" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/dac9d925-01a8-4aeb-a4f6-543da63ac2e8">


### 🔦 2. LED
The Neopixel is an 8-LED RGB strip and is very bright at high settings. The example sketches Neopixel 8 allow you to test as you go. 
- [ ] install the `<Adafruit_NeoPixel.h>` library [here](https://github.com/adafruit/Adafruit_NeoPixel).

- [ ] Use the example sketch below to test the LED
```
#include <Adafruit_NeoPixel.h>
  #include <avr/power.h>
#define PIN        6
#define NUMPIXELS 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(DELAYVAL);
  }
}
```

The `setLED()` function sets all LEDS to a predetermined color...
   
   <img width="430" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/787dc7fd-813a-4c0c-87f0-2e9de69160bd">

   depending on the decibel level.

   <img width="314" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/4c242c73-6aa3-4792-b0e4-c35168c03811">


### 📋 3. LCD Display
- [ ] install the `DFRobot_RGBLCD1602.h` library [here](https://github.com/dfrobot/DFRobot_RGBLCD1602/tree/master).
- [ ] Use the simple "Hello World" sketch below to ensure your LCD is connected properly. 

```
#include "DFRobot_RGBLCD1602.h"

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x60 ,/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show

void setup() {
    /**
     *  @brief initialize the LCD and master IIC
     */ 
    lcd.init();
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("hello, world!");

    delay(1000);
}

void loop() {
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(millis()/1000);
    delay(100);
}
```
In the final code, the LCD displays the `noiseLevel` variable output from the LED and the `dbValue` variable output from the Sound Level Meter.

   <img width="377" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/ec1635f0-006b-4405-842f-3fa00c6cc359">


### Final Display
Plug in your Arduino to your powersource when the components are completed! A working "Paddingtone" will most likely be assembled in a quiet lab and will glow green like this:

<img width="337" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/35a5657b-54b4-461d-9dad-02f004cb560d">


> [!NOTE] 
> The LED brightness has been turned down to avoid glare when using the device in the underground. These images do not reflect that but the code does.

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
## :small_orange_diamond: Assembling the Encasement
The Fusion 360 and gcode files for the top, bottom, and top + bottom parts of the encasement are available in `Final Physical Prototype Files`. The encasement is too large to print both the top and bottom at the same time on the Prusa i3, but this may be possible for machines with larger beds. Printing the entire encasement takes about  6-7 hours. 

<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/20d7c9c4-c78a-4400-84ee-55c612d23065">


The device is designed so that the sound sensor's microphone has protected yet visually disreet access to the ambient environment through a hole in the "o." 

<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/95765174-3a6e-4fd1-a442-ebf8e5944d15">

### Prototyping the Encasement
The initial test face was a scaled up version of a [Prusamaker Underground Keychain](https://www.printables.com/en/model/39900-london-underground-sign-keyring). I printed this as a first iteration to mark the proper dimensions and then modeled the Paddingtone face.

<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/0b376bbd-86fb-4b02-8ba1-cef8d55f136e">
<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/bf656c7d-037c-4cbe-9b35-22c394278e9d">

The top face of the roundel slips over the bottom container. 

<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/b92c2914-c582-4371-80ed-b5fde1521ade">


Be sure to print the encasement with white filament if you would like to paint the roundel in the classic underground colours; the nameplate is Ultramarine blue, the outer circle is two layers of Vermillion red over a base layer of Crimson red, the inner circle is white.

<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/6f173dac-ff10-4055-ab61-59337e2da3d8">

> PLA doesn’t take well to paint, so be sure to print an extra face to experiment with varnishes. The paint on my Paddingtone chipped immediately after I finished.

### Placing the Components 

Once your Paddingtone is ready for assembly, tape your components in place starting with the Neopixel, the LCD display, and finally the Sound Level Meter. Then, slip the top piece over bottom - if there is some wiggle room, add a piece of double-sided tape to secure this fit.

![image](https://github.com/elinor-oren/tube-sensor/assets/127933946/ec12f522-33a7-4c96-b823-9b9bff30e80d)

Be sure to thread the thinner (USB B) end of USB cable through the hole of the encasement before plugging it into the Arduino.

<img width="384" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/7bfdd35e-cb10-4571-a0b8-f3bada6a3429">


### Modifications 
If you would like to change the name of the device, be sure to account for this. The London Underground font used is [P22 Johnson](https://fontsgeek.com/fonts/P22-Johnston-Underground-Regular) and can be easily imported to Fusion 360. 


![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

## :small_orange_diamond: Deploying The Paddingtone
### Data Visualization 

<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/48e1e403-b962-4541-b94d-a5e72962cb87">

After taking in environmental noise, data is displayed via the following outputs.

<img width="400" alt="device_function" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/d5e33c2f-cd8e-40f3-9000-948f051e982b">

The device is light enough to carry with you on your commute. 

https://github.com/elinor-oren/tube-sensor/assets/127933946/0f459c9d-fea1-47e8-8aed-b2e4d2bb5345




