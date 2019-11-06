/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed 16 Oct 2019                                           */
/*    Description:  936A Tower Takeover competition code                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Fright               motor         4               
// Fleft                motor         3               
// Bright               motor         2               
// Bleft                motor         1               
// Mcage                motor         7               
// Lleft                motor         9               
// Lright               motor         10              
// Controller1          controller                    
// Ltop                 motor         8               
// Gyro                 gyro          A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

competition Competition;

bool auton = false;

void pre_auton(void) {
  
  vexcodeInit();

  Brain.Screen.drawRectangle(0, 0, 240, 272, red);

  while (!Competition.isEnabled()) {

    if (Brain.Screen.xPosition() <= 240 && auton) {

      auton = false;
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(0, 0, 240, 272, red);

    } else if (Brain.Screen.xPosition() >= 241 && !auton) {

      auton = true;
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(241, 0, 240, 272, blue);

    }

  }

}

void moveY(int degrees, bool blocking=true, int rpm=70) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  Fleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Fright.rotateFor(-degrees, vex::rotationUnits::deg, false);
  Bleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Bright.rotateFor(-degrees, vex::rotationUnits::deg, blocking);

}

/* void backward(int degrees, bool blocking=true, int rpm=200) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  Fleft.rotateFor(-degrees, vex::rotationUnits::deg, blocking);
  Fright.rotateFor(degrees, vex::rotationUnits::deg, blocking);
  Bleft.rotateFor(-degrees, vex::rotationUnits::deg, blocking);
  Bright.rotateFor(degrees, vex::rotationUnits::deg, blocking);

}

void left(int degrees, bool blocking=true, int rpm=200) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  Fleft.rotateFor(-degrees, vex::rotationUnits::deg, blocking);
  Fright.rotateFor(-degrees, vex::rotationUnits::deg, blocking);
  Bleft.rotateFor(degrees, vex::rotationUnits::deg, blocking);
  Bright.rotateFor(degrees, vex::rotationUnits::deg, blocking);

} */

void moveX(int degrees, bool blocking=true, int rpm=70) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  Fleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Fright.rotateFor(degrees, vex::rotationUnits::deg, false);
  Bleft.rotateFor(-degrees, vex::rotationUnits::deg, false);
  Bright.rotateFor(-degrees, vex::rotationUnits::deg, blocking);

}

void turn(int degrees, bool blocking=true, int rpm=70) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  Fleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Fright.rotateFor(degrees, vex::rotationUnits::deg, false);
  Bleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Bright.rotateFor(degrees, vex::rotationUnits::deg, blocking);

}

/*
void turnLeft(int degrees, int rpm=100) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  int target = Gyro.value(vex::rotationUnits::deg) - degrees;
  while (Gyro.value(vex::rotationUnits::deg) > target) {

    Fleft.spin(vex::directionType::rev);
    Fright.spin(vex::directionType::rev);
    Bleft.spin(vex::directionType::rev);
    Bright.spin(vex::directionType::rev);

  }

  Fleft.stop();
  Fright.stop();
  Bleft.stop();
  Bright.stop();

}

void turnRight(int degrees, int rpm=100) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  int target = Gyro.value(vex::rotationUnits::deg) + degrees;
  while (Gyro.value(vex::rotationUnits::deg) < target) {

    Fleft.spin(vex::directionType::fwd);
    Fright.spin(vex::directionType::fwd);
    Bleft.spin(vex::directionType::fwd);
    Bright.spin(vex::directionType::fwd);

  }

  Fleft.stop();
  Fright.stop();
  Bleft.stop();
  Bright.stop();

}
*/

void moveLift(int degrees, bool blocking=true, int rpm=100) {

  Lleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Lright.setVelocity(rpm, vex::velocityUnits::rpm);
  Ltop.setVelocity(rpm, vex::velocityUnits::rpm);

  Lleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Lright.rotateFor(degrees, vex::rotationUnits::deg, false);
  Ltop.rotateFor(degrees, vex::rotationUnits::deg, blocking);

}

void closeCage() {

  Mcage.spin(vex::directionType::fwd, 200, vex::velocityUnits::rpm);

}

void openCage() {

  Mcage.spin(vex::directionType::rev, 200, vex::velocityUnits::rpm);

}

void autonomous(void) {
  
  if (auton) {
  closeCage();
  moveLift(50);
  moveY(250);
  openCage();
  moveY(-400);
  moveX(400);
  moveY(-265);
  turn(370);
  moveLift(90);
  openCage();
  moveY(290, true, 50);
  closeCage();
  wait(200, msec);
  moveLift(90);
  moveY(-290);
  turn(-360);
  wait(200, msec);
  moveY(255);
  wait(200, msec);
  moveX(-400);
  wait(200, msec);
  moveY(400);
  moveLift(-80);
  openCage();
  wait(200, msec);
  moveLift(80);
  moveY(-200);
  } else {
  closeCage();
  wait(100, msec);
  moveLift(50);
  moveX(-50);
  moveY(250);
  openCage();
  wait(100, msec);
  moveY(-380);
  moveX(-400);
  moveY(-295);
  turn(-370);
  moveLift(90);
  openCage();
  moveY(290, true, 50);
  closeCage();
  wait(200, msec);
  moveLift(90);
  moveY(-290);
  turn(360);
  wait(200, msec);
  moveY(255);
  wait(200, msec);
  moveX(350);
  wait(200, msec);
  moveY(470);
  moveLift(-80);
  openCage();
  wait(200, msec);
  moveLift(80);
  moveY(-200);
  }

}

void usercontrol(void) {

  while (1) {
    
    Fleft.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
    Bleft.spin(vex::directionType::fwd, Controller1.Axis3.value() - Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
    Fright.spin(vex::directionType::fwd, -Controller1.Axis3.value() + Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
    Bright.spin(vex::directionType::fwd, -Controller1.Axis3.value() - Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
 
    int liftSpeed = 100;
    Lleft.setVelocity(100, vex::velocityUnits::rpm);
    Lright.setVelocity(100, vex::velocityUnits::rpm);
    Ltop.setVelocity(liftSpeed, vex::velocityUnits::rpm);
      if (Controller1.ButtonR1.pressing()) {
          
          Lleft.spin(vex::directionType::fwd);
          Lright.spin(vex::directionType::fwd);
          Ltop.spin(vex::directionType::fwd);
          
      } else if (Controller1.ButtonR2.pressing()) {
          
          Lleft.spin(vex::directionType::rev);
          Lright.spin(vex::directionType::rev);
          Ltop.spin(vex::directionType::rev);
      } else {
          Lleft.stop();
          Lright.stop();
          Ltop.stop();
      }

    Mcage.setVelocity(50, vex::velocityUnits::rpm);
    
    if (Controller1.ButtonL1.pressing()) {
      Mcage.spin(vex::directionType::fwd);
    } else if (Controller1.ButtonL2.pressing()) {
      Mcage.spin(vex::directionType::rev);
    } else {
      Mcage.stop();
    }

    wait(20, msec);

  }

}

int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {

    wait(100, msec);

  }

}
//