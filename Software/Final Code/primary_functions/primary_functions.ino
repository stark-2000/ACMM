//--------------------Sequence of Operations----------------------
// kneading mechanism
// Aloo ''
// Encrusting and FB ''
// Hot box ''


//dough actuator         = M - Bi  = DA = 0
//Flat and bakening      = M - Bi  = FB = 1

//flour distributor      = M - Uni = FD = 2
//kneader                = M - Uni = K  = 3
//aloo Screw feeder      = M - Uni = AS = 4

//Oil pump               = P       = OP = 5 -- 12 Volt - 60ml/min
//Water pump             = P       = WP = 6 --  6 Volt - 35ml/min

//aloo cutter            = S       = AC = 7
//chapatti striker       = S       = CS = 8
//oil sprayer            = S - cam = OS = 9
//mist sprayer           = S - cam = MS = 10

//ACMM FAN               = F       = AF = 11
//Hotbox Suction         = F       = HS = 12
//Hotbox blower          = F       = HB = 13

//DHT11 = DT                            = 14
//IR                                    = 15
//MQ                                    = 16
//Reed Switch = RS                      = 17

//ES UP - Prismatic    = ESU            = 18
//ES Down - Prismatic  = ESD            = 19 
//ES open - FB         = ESO            = 20
//ES close - FB        = ESC            = 21

//Heating coil          = R = HC        = 22
//hair dryer            = R = HD        = 23

void keepContainerFilled(){
  //check if oil counter is 10*
  if (oilCount > 200){
     pump(0,2*1000);
     oilCount = 0;
  }
  //check if water counter is 10*
  if (waterCount > 200){
    pump(1,2*1000);
    waterCount = 0;
  }
}

void kneading(){
  //linear actuator down
  digitalWrite(DA_IN1,HIGH);
  digitalWrite(DA_IN2,LOW);
  
  //if limit switch is pressed not actuator 
  if (digitalRead(ESD) == 1){
    digitalWrite(DA_IN1,LOW);
    digitalWrite(DA_IN2,LOW);
  }
  
  //linear actuator down
  digitalWrite(DA_IN1,LOW);
  digitalWrite(DA_IN2,HIGH);
  
  //if limit switch is pressed not actuator 
  if (digitalRead(ESU) == 1){
    digitalWrite(DA_IN1,LOW);
    digitalWrite(DA_IN2,LOW);
  }

  //pour powder
  digitalWrite(FD,HIGH);
  
  while (true){
    if (digitalRead(RS) == 1)
      reedCount +=1 
    if (reedCount > 5){
      break
    }
  }
  reedCount = 0;
  digitalWrite(FD,LOW);  
  
  //add water
  pump(2,1000);
  
  //start kneading blade
  digitalWrite(K,HIGH); 
  
  //add dough for lubricity
  while (true){
    if (digitalRead(RS) == 1)
      reedCount +=1 
    if (reedCount > 2){
      break
    }
  }
  reedCount = 0;
  //linear actuator down
  digitalWrite(K,LOW);

  //linear actuator down
  digitalWrite(DA_IN1,LOW);
  digitalWrite(DA_IN2,HIGH);
  
  //if limit switch is pressed not actuator 
  if (digitalRead(ESD) == 1){
    digitalWrite(DA_IN1,LOW);
    digitalWrite(DA_IN2,LOW);
  }
  
}

void aloo(){
   while (true){
     // start screw feeder
     digitalWrite(AS,HIGH);
     // if sensor triggered call servo AC 0-90*
     if (digitalRead(IR) == HIGH){
        AC.write(90);
        delay(0.5);
        AC.write(0);
        // stop screw feeder
        digitalWrite(AS,LOW);  
     }
   }
}

void EFB(){
  //spray oil*
  for(int i = 0; i <= 5; i++){
    OS.write(180);
    delay(100);
    OS.write(0);
  }
  
  //FB open to flat the dough
  digitalWrite(DA_IN1,HIGH);
  digitalWrite(DA_IN2,LOW);
  
  //if limit switch is pressed not actuator 
  if (digitalRead(ESO) == 1){
    digitalWrite(DA_IN1,LOW);
    digitalWrite(DA_IN2,LOW);
  }
  
  //repeat 2* times
  for (int i = 0; i < 2; i++){
    //FB close to flat the dough
    digitalWrite(DA_IN1,LOW);
    digitalWrite(DA_IN2,HIGH);
    
    //if limit switch is pressed not actuator 
    if (digitalRead(ESC) == 1){
      digitalWrite(DA_IN1,LOW);
      digitalWrite(DA_IN2,LOW);
    }
    //open FB
    //FB open to flat the dough
    digitalWrite(DA_IN1,HIGH);
    digitalWrite(DA_IN2,LOW);
    
    //if limit switch is pressed not actuator 
    if (digitalRead(ESO) == 1){
      digitalWrite(DA_IN1,LOW);
      digitalWrite(DA_IN2,LOW);
    }
  }
  //turn on heating pan
  digitalWrite(HC,HIGH);
  //FB close and hold to cook for 1* min
  
    //FB close to flat the dough
    digitalWrite(DA_IN1,LOW);
    digitalWrite(DA_IN2,HIGH);
    
    //if limit switch is pressed not actuator 
    if (digitalRead(ESC) == 1){
      digitalWrite(DA_IN1,LOW);
      digitalWrite(DA_IN2,LOW);
    }
    delay(3000); // waiting to cook;
    //open FB
    //FB open to flat the dough
    digitalWrite(DA_IN1,HIGH);
    digitalWrite(DA_IN2,LOW);
    
    //if limit switch is pressed not actuator 
    if (digitalRead(ESO) == 1){
      digitalWrite(DA_IN1,LOW);
      digitalWrite(DA_IN2,LOW);
    }
  
  //chappati striker to push to hotbox
  CS.write(90);
  delay(100);
  CS.write(0);
  
  //turn off heating pan
  digitalWrite(HC,LOW);
}

void hotBox(){
  //check if chappati is present
  digitalWrite(HB,HIGH);
  if (IRC == 1){
    //turn on heating fan
    digitalWrite(DB,HIGH);
    digitalWrite(HD,HIGH);
    //if humidity falls spray water
    while (true){
      MS.write(180);
      delay(100);
      MS.write(0);
      delay(100);
      if(dht.readHumidity() > 30){
        break;
      }
    }
    //if humidity is high - increase air blow and vent flow
    if(dht.readHumidity() > 30){
        break;
    }
    //if temp is high turn off coil
    if (dht.readTemperature() > 50){
       digitalWrite(HB,HIGH);
       digitalWrite(DB,HIGH);
    }
    else if  (dht.readTemperature() > 70){
      digitalWrite(HD,LOW); 
    }
  }
  else{
    digitalWrite(DB,LOW);
  }
}
