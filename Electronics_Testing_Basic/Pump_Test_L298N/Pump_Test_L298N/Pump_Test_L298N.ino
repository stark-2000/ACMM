// Motor A connections
int enA = 4;


void setup() 
{
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT); 
 
  // Turn off motors - Initial state
  digitalWrite(enA, LOW);
}

void loop() 
{
  digitalWrite(enA, HIGH);
  delay(15000);

  digitalWrite(enA, LOW);
  delay(2000);
}
 
  
