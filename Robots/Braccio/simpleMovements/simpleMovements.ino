
/*
  simpleMovements.ino

 This  sketch simpleMovements shows how they move each servo motor of Braccio

 Created on 18 Nov 2015
 by Andrea Martino

 This example is in the public domain.
 */

#include <Braccio.h>
#include <Servo.h>

class ServoSettings {
public:
  Servo s;
  int safepos;
  int maxrange;
};

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

ServoSettings* servos = new ServoSettings[6];

int pos = 0;

void setup() {
  /*
  // Initialization functions and set up the initial position for Braccio
  // All the servo motors will be positioned in the "safety" position:
  // Base (M1):90 degrees
  // Shoulder (M2): 45 degrees
  // Elbow (M3): 180 degrees
  // Wrist vertical (M4): 180 degrees
  // Wrist rotation (M5): 90 degrees
  // gripper (M6): 10 degrees
  */
  Braccio.begin();
  servos[0].s = base;
  servos[0].safepos = 90;

  servos[1].s = shoulder;
  servos[1].safepos = 45;

  servos[2].s = elbow;
  servos[2].safepos = 180;

  servos[3].s = wrist_ver;
  servos[3].safepos = 180;

  servos[4].s = wrist_rot;
  servos[4].safepos = 90;

  servos[5].s = gripper;
  servos[5].safepos = 10;
}

void loop() {
  for (int i = 0; i < 6; i++) {
    for (pos = 0; pos <= servos[i].safepos; pos++) {
      servos[i].s.write(pos);
      delay(15);  //random(5,15));
    }
    for (pos = servos[i].safepos; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
      servos[i].s.write(pos);                            // tell servo to go to position in variable 'pos'
      delay(15);                                         // waits 15ms for the servo to reach the position
    }
    servos[i].s.write(servos[i].safepos);
  }

  /*
   Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   M1=base degrees. Allowed values from 0 to 180 degrees
   M2=shoulder degrees. Allowed values from 15 to 165 degrees
   M3=elbow degrees. Allowed values from 0 to 180 degrees
   M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
   M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
   M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */

  // //(step delay, M1, M2, M3, M4, M5, M6);
  // Braccio.ServoMovement(10, 90, 150, 90, 10, 90, 73);

  // //Wait 1 second
  // delay(1000);

  // Braccio.ServoMovement(10, 180, 165, 0, 0, 180, 10);

  // //Wait 1 second
  // delay(1000);
}
