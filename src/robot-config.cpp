#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Fright = motor(PORT4, ratio36_1, false);
motor Fleft = motor(PORT3, ratio36_1, false);
motor Bright = motor(PORT2, ratio36_1, false);
motor Bleft = motor(PORT1, ratio36_1, false);
motor Mcage = motor(PORT7, ratio36_1, false);
motor Lleft = motor(PORT9, ratio36_1, false);
motor Lright = motor(PORT10, ratio36_1, true);
controller Controller1 = controller(primary);
motor Ltop = motor(PORT8, ratio36_1, true);
gyro Gyro = gyro(Brain.ThreeWirePort.A);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}