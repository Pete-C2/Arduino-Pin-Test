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

// the loop function runs over and over again forever
void loop() {
  int delay_time = 10; //ms
  int pins[][2] = {{2,3},{4,5},{6,7},{8,9},{10,11},{12,13},{14,15},{16,17},{18,19}};
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
