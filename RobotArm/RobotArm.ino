#include "RoboArm.h"
#define joyx1 A0
#define joyy1 A1
#define joyx2 A2
#define joyy2 A3
#define bot1 11
#define bot2 10
#define sw 5
#define mid 6
#define top 9
#define wrist 3

int joy[4] = {joyx1, joyy1, joyx2, joyy2};
JoystickArm arm(joy);

void setup() {
  arm.begin_(bot1, bot2, sw, mid, top, wrist);
  arm.btn(4);
}

void loop() {
   arm.Read();
   arm.toggle();
}
