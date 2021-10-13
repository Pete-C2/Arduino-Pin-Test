/*
  Board Test

  Tests an Arduino board to verify that all the pins are working correctly.

  Copyright (C) 2021 Peter Crighton
*/

// the setup function runs once when you press reset or power the board
void setup() {
 Serial.begin(9600);

}

boolean testPinState(int pin1, int pin2, int expected)
{
  boolean pinTest = true; // Assume no faults
  if (digitalRead(pin1) == HIGH)
  {
    Serial.print("    Pin ");
    Serial.print(pin1);
    Serial.println(" is high");
    if (expected == LOW)
    {
      pinTest = false;
    }
  }
  else
  {
    Serial.print("    Pin ");
    Serial.print(pin1);
    Serial.println(" is low");
    if (expected == HIGH)
    {
      pinTest = false;
    }
  }
  if (digitalRead(pin2) == HIGH)
  {
    Serial.print("    Pin ");
    Serial.print(pin2);
    Serial.println(" is high");
    if (expected == LOW)
    {
      pinTest = false;
    }
  }
  else
  {
    Serial.print("    Pin ");
    Serial.print(pin2);
    Serial.println(" is low");
    if (expected == HIGH)
    {
      pinTest = false;
    }
  }
  
  return pinTest;
}

boolean pinPairTest(int pin1, int pin2, int delay_time)
{
  boolean pairTest = true; // Assume no faults
  Serial.print("Pins ");
  Serial.print(pin1);
  Serial.print(" & ");
  Serial.println(pin2);

  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT);
  Serial.print("  Pin ");
  Serial.print(pin1);
  Serial.println(" pull-up");
  if (not(testPinState(pin1, pin2, HIGH)))
  {
    pairTest = false;
  }
  delay(delay_time);

  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT_PULLUP);
  Serial.print("  Pin ");
  Serial.print(pin2);
  Serial.println(" pull-up");
  if (not(testPinState(pin1, pin2, HIGH)))
  {
    pairTest = false;
  }
  delay(delay_time);

  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, LOW);
  Serial.print("  Pin ");
  Serial.print(pin1);
  Serial.println(" out low");
  if (not(testPinState(pin1, pin2, LOW)))
  {
    pairTest = false;
  }
  delay(delay_time);

  pinMode(pin2, INPUT);
  digitalWrite(pin1, HIGH);
  Serial.print("  Pin ");
  Serial.print(pin1);
  Serial.println(" out high");
  if (not(testPinState(pin1, pin2, HIGH)))
  {
    pairTest = false;
  }
  delay(delay_time);

  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin2, LOW);
  Serial.print("  Pin ");
  Serial.print(pin2);
  Serial.println(" out low");
  if (not(testPinState(pin1, pin2, LOW)))
  {
    pairTest = false;
  }
  delay(delay_time);

  pinMode(pin1, INPUT);
  digitalWrite(pin2, HIGH);
  Serial.print("  Pin ");
  Serial.print(pin2);
  Serial.println(" out high");
  if (not(testPinState(pin1, pin2, HIGH)))
  {
    pairTest = false;
  }
  delay(delay_time);

  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  return pairTest;
}

boolean pinAnalogTest(int analog_pin, int digital_pin, int delay_time, int tolerance)
{
  boolean analogTest = true; // Assume no faults
  int analog_value = 0;
  Serial.print("Analog pin ");
  Serial.print(analog_pin);
  Serial.print(" driven by digital pin ");
  Serial.println(digital_pin);
  
  pinMode(digital_pin, OUTPUT);
  digitalWrite(digital_pin, LOW);
  analog_value = analogRead(analog_pin);
  if (analog_value > tolerance)
  {
    analogTest = false;
  }
  Serial.print("Digital 0V reads ");
  Serial.println(analog_value);
  delay(delay_time);

  digitalWrite(digital_pin, HIGH);
  analog_value = analogRead(analog_pin);
  if (analog_value < (1023 - tolerance))
  {
    analogTest = false;
  }
  Serial.print("Digital 5V reads ");
  Serial.println(analog_value);
  delay(delay_time);

  pinMode(digital_pin, INPUT);
  return analogTest;
}

// the loop function runs over and over again forever
void loop() {
  int delay_time = 10; //ms
  int analog_tolerance = 5; // difference from zero / 1023 that is acceptable for analog 0 and 5V
  // Uno pins
  /*int pins[][2] = {{2,3},{4,5},{6,7},{8,9},{10,11},{12,13}, // Uno Digital
                    {14,15},{16,17},{18,19}}; // Uno Analog
  boolean analog_test = false;
  */
  // Mega pins
  /*int pins[][2] = {{2,3},{4,5},{6,7},{8,9},{10,11},{12,13},{14,15},{16,17},{18,19},{20,21},
                   {22,23},{24,25},{26,27},{28,29},{30,31},{32,33},{34,35},{36,37},{38,39},
                   {40,41},{42,43},{44,45},{46,47},{48,49},{50,51},{52,53}, // Mega Digital
                   {54,55},{56,57},{58,59},{60,61},{62,63},{64,65},{66,67},{68,69}}; // Mega Analog
  boolean analog_test = false;
                   */
  // Nano pins
  int pins[][2] = {{2,3},{4,5},{6,7},{8,9},{10,11},{12,13}, // Nano Digital
                  {14,15},{16,17},{18,19}}; // Nano Analog
  int analog_pins[][2] = {{A0,15},{A1,14},{A2,17},{A3,16},{A4,19},{A5,18},{A6,19},{A7,19}}; // Nano Analog only inputs [0] = analog input [1] = digital drive pin
  boolean analog_test = true;
  
  boolean success = true; // Assume no faults
  Serial.println("Start testing Arduino Pins");
  Serial.println("==========================");
  Serial.println("");
 

  int num_pin_pairs = sizeof(pins)/sizeof(pins[0]);
  for (int pin_test = 0; pin_test < num_pin_pairs; pin_test++)
  {
    if (not(pinPairTest(pins[pin_test][0], pins[pin_test][1], delay_time)))
    {
      success = false;
    }
  }
  if (analog_test)
  {
    int num_analog_inputs = sizeof(analog_pins)/sizeof(analog_pins[0]);
    for (int pin_test = 0; pin_test < num_analog_inputs; pin_test++)
    {
      if (not(pinAnalogTest(analog_pins[pin_test][0], analog_pins[pin_test][1], delay_time, analog_tolerance)))
      {
        success = false;
      }
    }
  }
  if (success)
        Serial.println("All tests passed");
  else
        Serial.println("!! Some tests failed !!");

  Serial.println("");
  Serial.println("========================");
  Serial.println("End testing Arduino Pins");
  Serial.println("");
 delay(2000);
}
