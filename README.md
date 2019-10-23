# E-21 Neopixel Blaster

**Project Status:** Ready to manufacture

If you are new to GitHub and would like to create a derivative of this project, please have a look at GitHub instructions to [fork a repo](https://help.github.com/en/articles/fork-a-repo)

## Description

Out of our passion to solve the issue of time waste in the robot creation process, EZ-Builder was born. The EZ-Builder software platform reduces the time it takes to get from idea to implementation. Since 2011 we have been listening to the challenges robot builders encounter and continue to provide them with an ever expanding toolbox of solutions. Join us on this journey!

We didn't stop at the software, we also made time saving hardware solutions. This Neopixel Blaster reference design is one of them. The Neopixel blaster connects WS2812 Addressable RGB LEDs to EZ-Builder. By utilizing EZ-builder the Neopixel Blaster can create animations and display all kinds of colors with WS2812B LEDs. A unique feature of this board is that it allows any EZ-Builder compatible board to use Neopixel LEDs, no libraries or precision timing required. We want to share these files with you so you can create your own version for your community and customers to enjoy!

**Features:** 
- 8 channels 
- Control up to 80 LEDs per channel
- Each LED can display 1 of 16 million different colors
- Mini programming header
- 5V tolerant I/O pins
- RGB LED status indicator
- EZ-Builder behavior control available
- Voltage requirement: 6-18VDC (7.4V Typical)
- Current draw: WS2812B off - 7mA, WS2812B white - 46mA
- Dimensions: 29.7(W) x 35.7(L) x 11.5(H) (mm)
- Weight: 5g

**Major components:** 
- PIC16F1704-I/ST 8-bit PIC microcontroller (custom firmware provided)
- NCP1117ST50T3GOSCT 5V Linear voltage regulator
- WS2812B Addressable RGB LED

**Manufacturing notes:** 
1. Supplier: programs custom firmware into the PIC16F1704-I/ST at their facility before sending to manufacturer
2. Manufacturer: Single side placement and soldering of SMT components
3. Manufacturer: Single Side soldering of THT components

**Note:** This reference design pairs with either a WS2812B NeoPixel LED or a Blaster Bit from here: https://github.com/synthiam/E-22_Blaster_Bit

## Contents

[**Documentation:**](https://github.com/synthiam/E-21_Neopixel_Blaster/tree/master/E-21%20Documentation) Schematic PDF, Datasheet PDF, BOM, Test Procedures

[**Hardware:**](https://github.com/synthiam/E-21_Neopixel_Blaster/tree/master/E-21%20Hardware) Altium PCB design File, Altium SCH Design File, Gerbers

[**Firmware:**](https://github.com/synthiam/E-21_Neopixel_Blaster/tree/master/E-21%20Firmware) Code, Compiled Hex

*Altium Libraries are also available <a href="https://github.com/synthiam/Synthiam_Altium_Librairies">here</a>*

## Photos

<p align="left">
<img src="https://live.staticflickr.com/65535/33867577428_49946a17c2_k.jpg" width="683" height="383">
<img src="https://live.staticflickr.com/65535/32801181517_8283eb2b66_k.jpg" width="683" height="383">
<img src="https://live.staticflickr.com/65535/33867577528_87d887444d_k.jpg" width="683" height="383"></p>

## Roll Out Video

This Roll-out Video includes:

1. Feature set 
2. Hook-up guide 
3. Using Synthiam EZ-Builder Software Behavior Control
4. Custom firmware location
5. Schematic overview
6. Bill of Materials (BOM) overview
7. Assembly instructions 

Link: https://youtu.be/iWZ4e5sMYgQ

<a href="https://youtu.be/iWZ4e5sMYgQ"><img src="https://media.giphy.com/media/iJVrOCN7n2OYXmgoqS/giphy.gif" width="683" height="383"></a>

## EZ-Builder Behavior Control

The EZ-Builder Neopixel Blaster Control makes it easy to control the Neopixel LEDs. The LED colors can be chained and activated with a simple code segment. 

Link: https://synthiam.com/Software/Manual/Neopixel-Blaster-16172

<a href="https://synthiam.com/Software/Manual/Neopixel-Blaster-16172"><img src="https://media.giphy.com/media/lOanb8dWhZGgvfvEgq/giphy.gif" width="683" height="383"></a>

## Contact

For profit use of these files requires written consent. Contact partners@synthiam.com. For everyone else, party on!

For support check out our Synthiam Community: https://synthiam.com/Community

## License

This project is released under the following licenses:

**Hardware:** Creative Commons Plus Attribution-NonCommercial 4.0 International (CC+ BY-NC 4.0)

**Firmware:** Apache 2.0 + “Commons Clause” License Condition v1.0

Please see [LICENSE.md](https://github.com/synthiam/E-21_Neopixel_Blaster/blob/master/LICENSE.md) for license details.

<a href="https://synthiam.com"><img src="https://live.staticflickr.com/65535/47791527651_358dffb302_m.jpg"></a>

