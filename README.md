# arduino-gas-leakage-detection
A project for Microprocessor systems, using a gas sensor, LCD and LEDs.
## 1. Introduction
This Arduino project is used for gas leakage detection by a gas sensor which senses the hydrogen concentration in the air. This sensor can detect hydrogen gas concentrations anywhere from 100 -10000 ppm. The sensor analog output voltage is shown on the LCD screen. When the sensor senses hydrogen above a certain predetermined level, a red light starts to blink, and a warning message is shown on the LCD screen. When the output voltage is below that level a green LED will be on. The same output is shown on the serial monitor.
## 2. Components
The following components are used: 
*	Arduino Uno
*	Solderless breadboard
*	Jumper wires
*	2 x 220Ohm resistors
*	Gas sensor MQ-8
*	1 x green LED
*	1 x red LED
* LCD screen 
## 3. Set up and connections
The 5V and GND from the Arduino are connected to the positive and negative rail of the breadboard, respectively. 
The Gas sensor that is used in this project comes with a board with four pins and a built-in potentiometer that allows for adjustment of the sensor sensitivity according to how accurate you want to detect gas. First, the sensor is plugged in to the breadboard and then the VCC pin is connected with the positive 5V rail, the GND with the negative rail and the analog output AO to the A0 on the Arduino. 

<img src="/images/gas-sensor.png" height="200" width="200">

The red and green LEDs, which have a polarity, are connected with the Arduino pins 9 and 10 on their positive, longer lead, and with a 220Ohm resistor on their negative lead. 
For the LCD, first 16 header pins needed to be soldered so we can connect it to the breadboard. The connections are as following: The VSS pin to negative, VDD to positive. The V0 pin which is used for controlling the backlight brightness is supposed to be connected with a potentiometer, but since I did not have one, I connected it to ground which gives it maximum brightness. Next the register select pin RS is connected to the digital pin 12, the RW to ground and the Enable to digital pin 11. I used four pins for data d4 – d7 which are connected to digital pins 2-5. The Anode and Cathode pins are connected to the positive and negative rail. 

<img src="/images/Fritzing-connections.png" height="350" width="650">

## 4. Result 
To test the gas leakage detection project, we use a lighter and press the button to release gas near the sensor. The result is picture a. when the gas level is low and b. when gas is applied. 
 
Picture a : Gas level low, no leakage

<img src="/images/no-leakage.jpg" height="250" width="360">

Picture b : Gas level high, gas leakage detected

<img src="/images/high-gas.jpg" height="250" width="360">
