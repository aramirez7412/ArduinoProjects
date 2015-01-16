const int ledOne   = 11;
const int ledTwo   = 12;
const int ledThree = 13;
//int count 

void setup()
{
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
}

void executeLED(const int pin)
{
  
  digitalWrite(pin, HIGH);
  delay(50);
  digitalWrite(pin, LOW);
  delay(50);
  
}

void loop()
{
      for(int innerIndex = ledOne; innerIndex < ledThree+1; innerIndex++)
      {
        executeLED(innerIndex);
      }
}

