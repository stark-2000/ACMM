//--------------------Sequence of Operations----------------------
// kneading mechanism
// Aloo ''
// Encrusting and FB ''
// Hot box ''


//aloo Screw feeder      = M - Uni = AS = 4

//aloo cutter            = S       = AC = 7

//IR                                    = 15

#include <Servo.h>

Servo AC;

const int AS = 3;
const int IR = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR,INPUT);
  pinMode(AS,OUTPUT);
  AC.attach(5);
  AC.write(90);
  Serial.println("Done Initializing... Starting in 3....");
  delay(1000);
  Serial.println("2....");
  delay(1000);
  Serial.println("1....");
  delay(1000);
  Serial.println("Operation commencing now");
}

void loop() {
  // put your main code here, to run repeatedly:
     Serial.println("Starting screw feeder");
     // if sensor triggered call servo AC 0-90*
     if (digitalRead(IR) == LOW){
        Serial.println("Cutting the aloo");
        // stop screw feeder
        delay(500);
        analogWrite(AS,0);  
        AC.write(0); // cut
        delay(500);
        AC.write(90); // home pos
        Serial.println("Stopping screw feeder");
        while (true){
          delay(1000);
        }
     }
     else{
     analogWrite(AS,255);
     delay(500); 
     }
     delay(100);
}
