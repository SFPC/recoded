// Total number of input channels supported by the hardware
const uint8_t numChannels = 5;
const uint8_t ledPins[] = {2, 4, 7, 8, 12};
const uint8_t encoderPins[] = {5, 6, 9, 10, 11};
unsigned long currentEncoderValues[] = {0, 0, 0, 0, 0};
unsigned long previousEncoderValues[] = {0, 0, 0, 0, 0};
const unsigned long encoderValueThreshold = 2048;

// Number of active parameters in the sketch
const uint8_t numParams = 4;

/*
 * Tests the LEDs and encoders. 
 * If the encoder value is over a given threshold, the corresponding LED is lit.
 */
void setup()
{
  Serial.begin(57600);
  for (uint8_t i = 0; i < numChannels; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    pinMode(encoderPins[i], INPUT);
  }
}

void loop()
{
  for (uint8_t i = 0; i < numParams; i++)
  {
    previousEncoderValues[i] = currentEncoderValues[i];
    currentEncoderValues[i] = pulseIn(encoderPins[i], HIGH);

    Serial.print(currentEncoderValues[i]);
    if (i < numParams - 1)
    {
      Serial.print(" ");
    }
    if (currentEncoderValues[i] > encoderValueThreshold)
    {
      digitalWrite(ledPins[i], HIGH);
    }
    else
    {
      digitalWrite(ledPins[i], LOW);
    }
  }
  Serial.println();
}