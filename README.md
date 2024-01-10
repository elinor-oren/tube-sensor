# The Paddingtone
This repository is for an environmental noise sensor project for the CASA0016 course. 

## About
The Paddingtone is a handheld noise monitoring device designed for deployment within the London Underground, stylized in the iconic Underground roundel design. This device is powered by an external battery pack and is easy to transport on the tube, allowing for unobtrusive data collection across Underground lines and stations. The Paddingtone provides a real-time safety evaluation of ambient noise levels in order to 1. facilitate the collection of noise exposure patterns on the Underground, and 2. illuminate the unsafe acoustic conditions for commuters. Offering a tangible and visually appealing solution, this project seeks to contribute to the broader discourse on environmental determinants of well-being and foster a healthier public transportation experience.

<img width="400" alt="device_function" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/d5e33c2f-cd8e-40f3-9000-948f051e982b">

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

## :small_orange_diamond: Materials + Libraries

![image](https://github.com/elinor-oren/tube-sensor/assets/127933946/0d2ac74d-9797-409e-97cb-e8cfe1c93c10)

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
## :small_orange_diamond: Connecting + Testing the Components
### Circuitry
The decibel sensor, LCD Display, and Neopixel LED strip require a 5V circuit to be powered. A 5V power supply, such as a battery pack, must be connected to the USB port to use the device. 

The following connections were used for each component:

* DFRobot Gravity Sound Level meter - connected to Analog pin A0 for the dataout Arduino signal. 
* Waveshare LCD1602 - the LCD1602 uses the I2C communication protocol, which simply means connecting to the SDA (or A4) pin and SCL (or A5) pin on the Arduino Uno.
* Neopixel 8 - connected to digital pin 6 for the dataout Arduino signal.
* 
<img width="405" alt="schematic_circuit" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/bb6f9408-84ac-45bb-adb6-183870be81d6">
<img height="399" alt="breadboard_circuit" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/ef5e5c21-7ccf-4866-bd77-3cf7ae2c7d09">

### Testing
In the final code, the light and display components depend on the sound sensor’s data readings to properly display, so it is essential to confirm that each work individually first. Start with the sound sensor component. 
1. The Sound Level Meter is almost ready to go out of the packaging, and you can use the circuit diagram above and test script to get the device running with your Arduino. Be sure to view the Serial Monitor to confirm that your data is being output. 


2. The example sketches Neopixel 8 allow you to test as you go.


3. Use a simple "Hello World" sketch to ensure your LCD is connected properly.


A completely working "Paddingtone" should look like this.

![IMG_3672](https://github.com/elinor-oren/tube-sensor/assets/127933946/5a70f176-59bc-41d9-9cdd-3a1d11cc0e39)

### Modifications 
The LED brightness has been turned down to avoid glare when using the device in the underground. These images do not reflect that but the code does.

![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
## :small_orange_diamond: Assembling the Encasement

The device is designed so that the sound sensor's microphone has protected yet visually disreet access to the ambient environment through a hole in the "o." 

<img width="400" alt="image" src="https://github.com/elinor-oren/tube-sensor/assets/127933946/95765174-3a6e-4fd1-a442-ebf8e5944d15">

### Prototyping the Encasement
The initial test face was a scaled up version of a [Prusamaker Underground Keychain](https://www.printables.com/en/model/39900-london-underground-sign-keyring). I printed this as a first iteration to mark the proper dimensions and then modeled the Paddingtone face.

![IMG_3649 2](https://github.com/elinor-oren/tube-sensor/assets/127933946/3bbb8d39-429e-4e87-af4b-1104c1629d34)
![IMG_3646 2](https://github.com/elinor-oren/tube-sensor/assets/127933946/c2a4f05e-eceb-4269-b303-99ef41e70065)

### Modifications 
If you would like to change the name of the device, be sure to account for this. The London Underground font used is [P22 Johnson](https://fontsgeek.com/fonts/P22-Johnston-Underground-Regular) and can be easily imported to Fusion 360. 


![-----------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
