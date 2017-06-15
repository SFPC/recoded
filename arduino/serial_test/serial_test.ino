// Total number of channels supported by the hardware device
const uint8_t numChannels = 4;
const uint8_t ledPins[] = {7, 2, 8, 4};
const uint8_t encoderPins[] = {9, 5, 10, 6};
unsigned long currentEncoderValues[] = {0, 0, 0, 0};
unsigned long previousEncoderValues[] = {0, 0, 0, 0};
const unsigned long encoderValueThreshold = 2048;

int ledStates[] = {LOW, LOW, LOW, LOW};
int incomingByte = 0; // for incoming serial data

/*
 * Receives a byte from the serial port and decodes it to toggle LED states 
 * Reads encoder values and sends them as a space-delimited string 
 * in the form "a 3210 208 1234 4003 z"
 */
void setup()
{
  Serial.begin(57600);
  for (uint8_t i = 0; i < numChannels; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    pinMode(encoderPins[i], INPUT);
  }
  // Flash LEDs twice when starting up
  flashLEDs();
  delay(100);
  flashLEDs();
}

void loop()
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    for (int i = 0; i < numChannels; i++)
    {
      digitalWrite(ledPins[i], (incomingByte >> i) & 0x1);
    }
  }
  Serial.print("a ");
  for (uint8_t i = 0; i < numChannels; i++)
  {
    previousEncoderValues[i] = currentEncoderValues[i];
    currentEncoderValues[i] = pulseIn(encoderPins[i], HIGH);
    Serial.print(currentEncoderValues[i]);
    Serial.print(" ");
  }
  Serial.print("z");
  Serial.println();
  delay(5);
}

void flashLEDs()
{
  for (int i = 0; i < numChannels; i++)
  {
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 0; i < numChannels; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(60);
  }
  delay(200);
  for (int i = 0; i < numChannels; i++)
  {
    digitalWrite(ledPins[i], LOW);
    delay(60);
  }
}