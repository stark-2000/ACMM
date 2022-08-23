//--------------------Sequence of Operations----------------------
// kneading mechanism
// Aloo ''
// Encrusting and FB ''
// Hot box ''


//dough actuator         = M - Bi  = DA = 0
//Flat and bakening      = M - Bi  = FB = 1
//DA_IN1 = 24;
//DA_IN2 = 25;
//FB_IN1 = 26;
//FB_IN2 = 27;

//flour distributor      = M - Uni = FD = 2
//kneader                = M - Uni = K  = 3
//aloo Screw feeder      = M - Uni = AS = 4

//Oil pump               = P       = OP = 5
//Water pump             = P       = WP = 6

//aloo cutter            = S       = AC = 7
//chapatti striker       = S       = CS = 8
//oil sprayer            = S - cam = OS = 9
//mist sprayer           = S - cam = MS = 10

//ACMM FAN               = F       = AF = 11
//Hotbox Suction         = F       = HS = 12
//Hotbox blower          = F       = HB = 13

//DHT11 = DT                            = 14
//IR                                    = 15
//IR-Chappati = IRC                     = 28
//MQ                                    = 16
//Reed Switch = RS                      = 17

//ES UP - Prismatic    = ESU            = 18
//ES Down - Prismatic  = ESD            = 19 
//ES open - FB         = ESO            = 20
//ES close - FB        = ESC            = 21

//Heating coil          = R = HC        = 22
//hair dryer            = R = HD        = 23

#include <Servo.h>
#include "DHT.h"

#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 14     // Digital pin connected to the DHT sensor

DHT dht(DHTPIN, DHTTYPE);

Servo AC;
Servo CS;
Servo OS;
Servo MS;


const int DA = 0;
const int FB = 1;

const int FD = 2;
const int K  = 3;
const int AS = 4;

const int OP = 5;
const int WP = 6;

const int AF = 11;
const int HS = 12;
const int HB = 13;

//const int DT = 14;
const int IR = 15;
const int IRC = 28;
const int MQ = 16;
const int RS = 17;

const int ESU = 18;
const int ESD = 19;
const int ESO = 20;
const int ESC = 21;

const int HC = 22;
const int HD = 23;

const int DA_IN1 = 24;
const int DA_IN2 = 25;
const int FB_IN1 = 26;
const int FB_IN2 = 27;

int oilCount = 0;
int waterCount = 0;
int reedCount = 0;
void setup(){
  
  dht.begin();
  //Bidirectional Motor
  pinMode(DA,OUTPUT);
  pinMode(FB,OUTPUT);
  analogWrite(DA,255);
  analogWrite(FB,255);
  
  //Unidirectional motors
  pinMode(FD,OUTPUT);
  pinMode(K,OUTPUT);
  pinMode(AS,OUTPUT);

  //Pumps
  pinMode(OP,OUTPUT);
  pinMode(WP,OUTPUT);

  //Servos
  pinMode( 7,OUTPUT);
  pinMode( 8,OUTPUT);
  pinMode( 9,OUTPUT);
  pinMode(10,OUTPUT);

  AC.attach(7);
  CS.attach(8);
  OS.attach(9);
  MS.attach(10);
  
  AC.write(0);
  CS.write(0);
  OS.write(0);
  MS.write(0);
  
  //Fan
  pinMode(AF,OUTPUT);
  pinMode(HS,OUTPUT); 
  pinMode(HB,OUTPUT);

  //Sensors
  pinMode(DT,INPUT);
  pinMode(IR,INPUT);
  pinMode(IRC,INPUT);
  pinMode(MQ,INPUT);
  pinMode(RS,INPUT);

  //Limit Switches
  pinMode(ESU,INPUT);
  pinMode(ESD,INPUT);
  pinMode(ESO,INPUT);
  pinMode(ESC,INPUT);

  //AC Appliances
  pinMode(HC,OUTPUT);
  pinMode(HD,OUTPUT);
}

void loop(){
  
}
