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
// Gyro                 gyro          C               
// Controller2          controller                    
// Lencoder             encoder       E, F            
// Rencoder             encoder       G, H            
// Hencoder             encoder       A, B            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>
using namespace vex;

competition Competition;

bool auton = false;

void pre_auton(void) {
  
  vexcodeInit();
  Mcage.resetRotation();
  Gyro.startCalibration();
  
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

void moveY(int degrees, bool blocking=true, int rpm=75) {

  Fleft.setStopping(hold);
  Fright.setStopping(hold);
  Bleft.setStopping(hold);
  Bright.setStopping(hold);

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  Fleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Fright.rotateFor(-degrees, vex::rotationUnits::deg, false);
  Bleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Bright.rotateFor(-degrees, vex::rotationUnits::deg, blocking);

}

float disterror;
float differror;
float distintegral;
float diffintegral;
float distderivative;
float diffderivative;
float distspeed;
float diffspeed;
float distP = 0;
float distI = 0;
float distD = 0;
float diffP = 0;
float diffI = 0;
float diffD = 0;
float maxspeed = 0;
void moveStraight(int distance, int max, int time) {

  Lencoder.resetRotation();
  Rencoder.resetRotation();
  Brain.Timer.clear();

  float prevdisterror = 0;
  float prevdifferror = 0;

  while (Brain.Timer.value() < time) {

    disterror = distance - ((-(Lencoder.rotation(vex::rotationUnits::raw)) + Rencoder.rotation(vex::rotationUnits::raw)) / 2);
    differror = -(Lencoder.rotation(vex::rotationUnits::raw)) - Rencoder.rotation(vex::rotationUnits::raw);
    if (abs(disterror) < 60 && disterror != 0) {
      distintegral = distintegral + disterror;
    } else {
      distintegral = 0;
    }

    if (abs(differror) < 60 && differror != 0) {
      diffintegral = diffintegral + differror;
    } else {
      diffintegral = 0;
    }

    distderivative = disterror - prevdisterror;
    diffderivative = differror - prevdifferror;

    prevdisterror = disterror;
    prevdifferror = differror;

    distspeed = (disterror * distP) + (distintegral * distI) + (distderivative * distD);
    diffspeed = (differror * diffP) + (diffintegral * diffI) + (diffderivative * diffD);

    if (distspeed > maxspeed) {
      distspeed = maxspeed;
    }
    if (distspeed <- maxspeed) {
      distspeed = -maxspeed;
    }

    

  }

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

void moveX(int degrees, bool blocking=true, int rpm=65) {

  Fleft.setStopping(hold);
  Fright.setStopping(hold);
  Bleft.setStopping(hold);
  Bright.setStopping(hold);

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

void turnLeft(int degrees, int rpm=50) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  int target = Gyro.value(vex::rotationUnits::deg) - degrees + 2;
  while (Gyro.value(vex::rotationUnits::deg) > target) {

    Fleft.spin(vex::directionType::rev);
    Fright.spin(vex::directionType::rev);
    Bleft.spin(vex::directionType::rev);
    Bright.spin(vex::directionType::rev);

  }

  Fleft.stop(hold);
  Fright.stop(hold);
  Bleft.stop(hold);
  Bright.stop(hold);

}

void turnRight(int degrees, int rpm=50) {

  Fleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Fright.setVelocity(rpm, vex::velocityUnits::rpm);
  Bleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Bright.setVelocity(rpm, vex::velocityUnits::rpm);

  int target = Gyro.value(vex::rotationUnits::deg) + degrees - 2;
  while (Gyro.value(vex::rotationUnits::deg) < target) {

    Fleft.spin(vex::directionType::fwd);
    Fright.spin(vex::directionType::fwd);
    Bleft.spin(vex::directionType::fwd);
    Bright.spin(vex::directionType::fwd);

  }

  Fleft.stop(hold);
  Fright.stop(hold);
  Bleft.stop(hold);
  Bright.stop(hold);

}

void moveLift(int degrees, bool blocking=true, int rpm=100) {

  Lleft.setVelocity(rpm, vex::velocityUnits::rpm);
  Lright.setVelocity(rpm, vex::velocityUnits::rpm);
  Ltop.setVelocity(rpm, vex::velocityUnits::rpm);

  Lleft.rotateFor(degrees, vex::rotationUnits::deg, false);
  Lright.rotateFor(degrees, vex::rotationUnits::deg, false);
  Ltop.rotateFor(degrees, vex::rotationUnits::deg, blocking);

}

void closeCage() {

  Mcage.spin(vex::directionType::fwd, 70, vex::velocityUnits::rpm);
  wait(200, msec);

}

void openCage() {

  Mcage.rotateTo(0,deg,100,rpm,false);
  Mcage.stop(hold);

}

void autonomous(void) {
  
  if (!auton) {
    // RED
    moveLift(40);
    openCage();
    moveY(200);
    closeCage();
    turnRight(90, 80);
    moveY(100);
    openCage();
    moveY(-80);
    turnLeft(88, 70);
    moveLift(-10);
    moveY(510, true, 40);
    closeCage();
    moveLift(30);
    moveY(-510, true, 40);
    turnLeft(102);
    moveLift(35);
    moveY(400, true, 40);
    moveLift(32);
    moveY(240, true, 40);
    openCage();
    wait(200, msec);
    moveY(-100);
  } else {
    // BLUE
    moveLift(40);
    openCage();
    moveY(200);
    closeCage();
    turnLeft(90, 80);
    moveY(100);
    openCage();
    moveY(-80);
    turnRight(88, 70);
    moveLift(-10);
    moveY(510, true, 40);
    closeCage();
    moveLift(30);
    moveY(-510, true, 40);
    turnRight(104);
    moveLift(35);
    moveY(400, true, 40);
    moveLift(25);
    moveY(235, true, 40);
    openCage();
    wait(200, msec);
    moveY(-100);

    /*
    moveY(-1000, true, 40);
    moveY(80);
    turnRight(90);
    moveY(500);
    moveLift(-20);
    openCage();
    moveLift(20);
    moveY(-300);
    closeCage();
    */
  }
  /*
  if (!auton) {
    // RED
    closeCage();
    moveLift(50);
    moveY(270);
    openCage();
    moveY(-420);
    moveX(400);
    moveY(-265);
    turn(370);
    moveLift(80);
    openCage();
    moveY(180, true, 50);
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
    //BLUE
    closeCage();
    wait(100, msec);
    moveLift(80);
    moveX(-50);
    moveY(270);
    moveLift(-50);
    openCage();
    moveLift(50);
    wait(100, msec);
    moveY(-380);
    moveX(-380);
    moveY(-260); 
    turnLeft(90);
    moveLift(50);
    openCage();
    moveY(185, true, 50);
    closeCage();
    wait(200, msec);
    moveLift(90);
    moveY(-290);
    turnRight(90);
    wait(200, msec);
    moveY(255);
    wait(200, msec);
    moveX(300);
    turnLeft(10);
    wait(200, msec);
    moveY(485);
    moveLift(-80);
    openCage();
    wait(200, msec);
    moveLift(80);
    moveY(-200);
  }
  */

}

int counter = 0;
int toDisplay = 0;

void usercontrol(void) {

  while (1) {
 
    if (Controller1.ButtonUp.pressing()) {

      Fleft.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
      Fright.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);
      Bleft.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
      Bright.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);

    } else if (Controller1.ButtonDown.pressing()) {
    
      Fleft.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);
      Fright.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
      Bleft.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);
      Bright.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);

    } else if (Controller1.ButtonLeft.pressing()) {
      
      Fleft.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);
      Fright.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);
      Bleft.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
      Bright.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
      
    } else if (Controller1.ButtonRight.pressing()) {

      Fleft.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
      Fright.spin(vex::directionType::fwd, 30, vex::velocityUnits::rpm);
      Bleft.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);
      Bright.spin(vex::directionType::rev, 30, vex::velocityUnits::rpm);

    } else {

      Fleft.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
    Bleft.spin(vex::directionType::fwd, Controller1.Axis3.value() - Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
    Fright.spin(vex::directionType::fwd, -Controller1.Axis3.value() + Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
    Bright.spin(vex::directionType::fwd, -Controller1.Axis3.value() - Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);

    }

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
    
    if (Controller1.ButtonL1.pressing()) {
      Mcage.spin(vex::directionType::fwd, 50, vex::velocityUnits::rpm);
    } else if (Controller1.ButtonL2.pressing()) {
      if(fabs(Mcage.rotation(deg))>=5){
        Mcage.rotateTo(0,deg,100,rpm);
      }
      else{
        Mcage.stop(hold);
      }
    } else {
      Mcage.stop(coast);
    }

    if (counter == 100) {
      counter = 0;
      Controller2.Screen.clearScreen();
      Controller2.Screen.setCursor(1, 1);
      Controller2.Screen.print("CLAW %f", Mcage.temperature(percent));
      if (Mcage.temperature(percent) >= 75) {
        Controller1.rumble(".");
        Controller2.rumble("...");
      }
      Controller2.Screen.newLine();
      switch (toDisplay) {
        case 0: 
        Controller2.Screen.print("LIFT LEFT %f", Lleft.temperature(percent));
        Controller2.Screen.newLine();
        toDisplay++;
        break;
        case 1: 
        Controller2.Screen.print("LIFT RIGHT %f", Lright.temperature(percent));
        Controller2.Screen.newLine();
        toDisplay++;
        break;
        case 2: 
        Controller2.Screen.print("LIFT TOP %f", Ltop.temperature(percent));
        Controller2.Screen.newLine();
        toDisplay = 0;
        break;
      }
      
    }

    


    counter++;
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