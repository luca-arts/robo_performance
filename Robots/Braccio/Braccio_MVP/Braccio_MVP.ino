#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

const int max_range = 90;
const int movement_delay = 15;

void setup() {
  // put your setup code here, to run once:
  Braccio.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int pos = 0; pos <= max_range; pos++) {
    base.write(pos);
    delay(movement_delay);
  }
  for (int pos = max_range; pos >= 0; pos -= 1) {  // goes from max_range degrees to 0 degrees
    base.write(pos);                               // tell servo to go to position in variable 'pos'
    delay(movement_delay);                         // waits 15ms for the servo to reach the position
  }
}
