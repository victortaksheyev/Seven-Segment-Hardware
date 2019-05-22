#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

uint8_t servonum = 0;

int BCDToSS[16][7] = {
  {1,0,0,1,0,0,1}, // 0
  {0,0,0,0,1,1,1}, // 1
  {1,0,1,1,0,1,0}, // 2
  {1,0,0,1,1,1,0}, // 3
  {0,0,0,0,1,0,0}, // 4
  {1,1,0,1,1,0,0}, // 5
  {1,1,0,1,0,0,0}, // 6
  {1,0,0,0,1,1,1}, // 7
  {1,0,0,1,0,0,0}, // 8
  {1,0,0,1,1,0,0}, // 9
  {1,0,0,0,0,0,0}, // A
  {0,1,0,1,0,0,0}, // B
  {1,1,1,1,0,0,1}, // C
  {0,0,0,1,0,1,0}, // D
  {1,1,1,1,0,0,0}, // E
  {1,1,1,0,0,0,0}  // F
};

void setup() {
  Serial.begin(9600);
//  Serial.println("16 channel Servo test!");
  pinMode(3, OUTPUT);
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}
int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
//  Serial.println(analog_value);
  return analog_value;
}

void setNum(int num) {
  int offset = 9;
  for(int i = 0; i < 7; i++){
    pwm.setPWM(i + offset, 0, pulseWidth(BCDToSS[num][i] * 90));
  }
}
 int x = 0;
 bool once = false;
void loop() {
//    setNum(0);
  int incomingByte;
  char mystr[2];
//  Serial.write(5);
//  if (Serial.available() > 0) {   // see if there's incoming serial data
//   Serial.readBytes(mystr, 1);  // read it and store it in the variable
//   Serial.println(mystr);
   
//      setNum(2);
//      delay(1000);
//    setNum(2);
////    
//   }// else { }
// 
//  Serial.write(9);
//  delay(1000);
//Serial.write(5);
delay(100);
//  Serial.println(Serial.available()); //return number of bytes availible to read
delay(500);
  if (Serial.available() > 0) {   // see if there's incoming serial data
    delay(500);
   x = Serial.read();  // read it and store it in the variable
   delay(500);

//    Serial.println(5);
   } else { 
//    Serial.println("If is false");
delay(500);
    x = Serial.read();  // read it and store it in the variable
    delay(500);
    }

//    Serial.write(x);
//   
//  Serial.println(x);
  delay(500);
  if (x || once){
  delay(500);
  digitalWrite(3, HIGH);
  once = true;
  delay(500);
}else {
  digitalWrite(3, LOW);
  delay(500);
  }
  delay(1000);

  

   
   
//  for(int j = 0; j < 16; j++) {
//    setNum(j);
////    Serial.write(j);
//    delay(1000);
//  }
}
