#include <Servo.h>

Servo servo; 

const int NUM_SERVOS = 2; // change to 7

int number = 0;

int BCDToSS[16][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}, // 9
  {1,1,1,0,1,1,1}, // A
  {0,0,1,1,1,1,1}, // B
  {1,0,0,1,1,1,0}, // C
  {0,1,1,1,1,0,1}, // D
  {1,0,0,1,1,1,1}, // E
  {1,0,0,0,1,1,1}  // F
};

void setup() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    s[i].attach(i); // initialize pins
    s[i].write(0);  // initialize angle
  }
}

void loop() {
  servo.write((BCDToSS[number%16][0] * 80) + 10);
  delay(1000);
  number++;
  
  for (int i = 0; i < NUM_SERVOS; i++)
      s[i].write(90);
  delay(2000);
  for (int i = 0; i < NUM_SERVOS; i++)
    s[i].write(0);
  delay(2000);
}
