using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Fright;
extern motor Fleft;
extern motor Bright;
extern motor Bleft;
extern motor Mcage;
extern motor Lleft;
extern motor Lright;
extern controller Controller1;
extern motor Ltop;
extern gyro Gyro;
extern controller Controller2;
extern encoder Lencoder;
extern encoder Rencoder;
extern encoder Hencoder;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );