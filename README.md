# Arduino Pin Test
Program to test the digital and analog pin I/O header pins. The program checks that the inputs and outputs correctly drive static voltage levels. This is useful if you buy a secondhand Arduino or think you might have damaged one or more of the I/O pins.

TXD and RXD are not explictly tested (but are exercised in producing the serial output).
Digital and analog pins are exercised as digital inputs and outputs including the pull-ups.

More complex testing is not included.

Requires:
- An [Arduino](https://www.arduino.cc/)

## Basic use

Ensure that no hardware is connected to the Arduino. 

Connect pairs of pins together:
* 2,3
* 4,5
* 6,7
* 8,9
* 10,11
* 12,13
* 14,15
* 16,17
* 18,19

All pairs of pins will be tested:
* Pull-up on one of each pair at a time is read correctly on both pins
* Pull-up on one pin and output drive low on the other pin correctly reads as low on both pins
* Input without pull-up on one pin and output drive high on the other pin correctly reads as high on both pins

## Changelog


### V1.0

- Initial code. Tests all pins an a Uno board
