# Arduino Pin Test
Program to test the digital and analog pin I/O header pins. The program checks that the inputs and outputs correctly drive static voltage levels. This is useful if you buy a secondhand Arduino or think you might have damaged one or more of the I/O pins.

TXD and RXD are not explictly tested (but are exercised in producing the serial output).
Digital and analog pins are exercised as digital inputs and outputs including the pull-ups.

More complex testing is not included.

Requires:
- An [Arduino](https://www.arduino.cc/)

## Basic use

Ensure that no hardware is connected to the Arduino. 

Modify the code to include only valid pins. The code has options for Uno and Mega boards. One set will be commented out. Others could easily be added.

Connect pairs of digital pins together (some are the analog pins, but identified by their digital number):

For a Uno:
* 2,3
* 4,5
* 6,7
* 8,9
* 10,11
* 12,13
* 14,15
* 16,17
* 18,19

For a Mega:
* 2,3
* 4,5
* 6,7
* 8,9
* 10,11
* 12,13
* 14,15
* 16,17
* 18,19
* 20,21
* 22,23
* 24,25
* 26,27
* 28,29
* 30,31
* 32,33
* 34,35
* 36,37
* 38,39
* 40,41
* 42,43
* 44,45
* 46,47
* 48,49
* 50,51
* 52,53
* 54,55
* 56,57
* 58,59
* 60,61
* 62,63
* 64,65
* 66,67
* 68,69

For a Nano:
* 2,3
* 4,5
* 6,7
* 8,9
* 10,11
* 12,13
* 14,15
* 16,17
* 18,19
* A6, A7, 19

All pairs of pins will be tested:
* Pull-up on one of each pair at a time is read correctly on both pins
* Pull-up on one pin and output drive low on the other pin correctly reads as low on both pins
* Input without pull-up on one pin and output drive high on the other pin correctly reads as high on both pins
* Analog input read from a digital 0V and 5V

## Changelog

### V3.0

- Added definition for Nano board
- Added test for Nano analog inputs driven by digital input 


### V2.0

- Added definition for Mega board

### V1.0

- Initial code. Tests all pins an a Uno board
