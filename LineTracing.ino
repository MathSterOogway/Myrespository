#include <QTRSensors.h>//manifesting ma division to
#define ADIR 8
#define ASPEED 9
#define BSPEED 10
#define BDIR 11
const int offsetA = 1;
const int offsetB = 1;
QTRSensors qtr;
const uint8_t SensorCount = 5;
uint16_t sensorValues[SensorCount];
int threshold[SensorCount];
float Kp = 0;
float Ki = 0;
float Kd = 0;

uint8_t multiP = 1;
uint8_t multiI  = 1;
uint8_t multiD = 1;
uint8_t Kpfinal;
uint8_t Kifinal;
uint8_t Kdfinal;
float Pvalue;
float Ivalue;
float Dvalue;

boolean onoff = false;

int val, cnt = 0, v[3];

uint16_t position;
int P, D, I, previousError, PIDvalue, error;
int lsp, rsp;
int lfspeed = 230;
void setup() {
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){3, A1, A2, A3, A4}, SensorCount);
  qtr.setEmitterPin(2);
  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  for (uint16_t i = 0; i < 400; i++) {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);
  for (uint8_t i = 0; i < SensorCount; i++){
    threshold[i] = (qtr.calibrationOn.minimum[i] + qtr.calibrationOn.maximum[i])/2;

  }
  delay(1000);
}
void loop() {
  robot_control();
  
}
void robot_control(){
  position = qtr.readLineBlack(sensorValues);
  error = 2000 - position;
  while(sensorValues[0]>=980 && sensorValues[1]>=980 && sensorValues[2]>=980 && sensorValues[3]>=980 && sensorValues[4]>=980){ // A case when the line follower leaves the line
    if(previousError>0){       
      motor_drive(-230,230);
    }
    else{
      motor_drive(230,-230); 
    }
    position = qtr.readLineBlack(sensorValues);
  }
  PID_Linefollow(error);
}
void PID_Linefollow(int error){
  P = error;
  I = I + error;
  D = error - previousError;
  Pvalue = (Kp/pow(10,multiP))*P;
  Ivalue = (Ki/pow(10,multiI))*I;
  Dvalue = (Kd/pow(10,multiD))*D;
  float PIDvalue = Pvalue + Ivalue + Dvalue;
  previousError = error;
  lsp = lfspeed - PIDvalue;
  rsp = lfspeed + PIDvalue;
  if (lsp > 255){
    lsp = 255;
  }
  if (lsp < -255){
    lsp = -255;
  }
  if (rsp > 255){
    rsp = 255;
  }
  if (rsp < -255){
    rsp = -255;
  }
  motor_drive(lsp,rsp);
}
void motor_drive(int left, int right){
  
  if(right>0)
  {
    digitalWrite(ADIR, HIGH);
    analogWrite(ASPEED, right);
  }
  else 
  {
    digitalWrite(ADIR, LOW);
    analogWrite(ASPEED, right);
  }
  
 
  if(left>0)
  {
    digitalWrite(BDIR, HIGH);
    analogWrite(BSPEED, left);
  }
  else 
  {
    digitalWrite(BDIR, LOW);
    analogWrite(BSPEED, left);
  }
}
