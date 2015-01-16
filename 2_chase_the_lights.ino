const int button = 6;
const int light1 = 7;
const int light2 = 8;
const int light3 = 9;
const int targetLight = 10;
const int light5 = 11;
const int light6 = 12;
const int light7 = 13;

void setup()
{
  pinMode(button, INPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(targetLight, OUTPUT);
  pinMode(light5, OUTPUT);
  pinMode(light6, OUTPUT);
  pinMode(light7, OUTPUT);

  
}

int debounceAndRead(const int button)
{
  int val;
  if (digitalRead(button) == HIGH)
  {
    val = HIGH;
  }
  else
  {
     val = LOW; 
  }
  
  delay (50); // delay the program to allow for button to return to prev state
  
  return val;
}
void loop()
{
  /*
  if (debounceAndRead(button) == HIGH)
  {
     analogWrite(targetLight, 10);
     delay(2000);
  }
  else
  {
    digitalWrite(targetLight, LOW);
  }
  
  for (int i = light1; i < light7 + 1; i++)
  {
   
    
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW); 
    delay(50);
  }
  
  */
  int index = light1;
  int status = debounceAndRead(button); 
  
  // while the button is not clicked and not all lights have been traversed
  while (index < light7 + 1 && status != HIGH)
  {
   
    digitalWrite(index, HIGH);
    delay(50);
    digitalWrite(index, LOW); 
    delay(50);
     
     index++; 
     status = debounceAndRead(button);
  }
  
  if (status == HIGH)
  {
    digitalWrite(index, HIGH);
    delay(1000);
    
    // if the target light, flash button multiple times to indicate a win
    if (index == targetLight)
    {
        digitalWrite(index, LOW);
        delay (400);
        digitalWrite(index, HIGH);
        delay (400);
        digitalWrite(index, LOW);
        delay (400);
        digitalWrite(index, HIGH);
        delay (400);
        digitalWrite(index, LOW);
        delay (400);
        digitalWrite(index, HIGH);
        delay (400);
        digitalWrite(index, LOW);
        delay (400);
        digitalWrite(index, HIGH);
        delay (400);
        digitalWrite(index, LOW);
        
    }
    
      digitalWrite(index, LOW);
      delay (2000);

  }
}
  
