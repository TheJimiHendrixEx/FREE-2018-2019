#include "RoboArm.h"

//Arm contrsuctor
Arm::Arm()
{
}
void Arm::swivel(int angle) {
  swivel_s.write(angle);
};
void Arm::move_bot1(int angle) {
  bottom1_s.write(angle);
};
void Arm::move_bot2(int angle) {
  bottom2_s.write(angle);
};
void Arm::move_mid(int angle) {
  middle_s.write(angle);
};
void Arm::move_top(int angle) {
  top_s.write(angle);
};
void Arm::move_wrist(int angle) {
  wrist_s.write(angle);
};
void Arm::begin_(int bot1, int bot2, int sw, int mid, int top, int wrist){
  bottom1_s.attach(bot1);
  bottom2_s.attach(bot2);
  swivel_s.attach(sw);
  middle_s.attach(mid);
  top_s.attach(top);
  wrist_s.attach(wrist);
}

JoystickArm::JoystickArm(int pin[4])
{  
  joy[0] = pin[0];
  joy[1] = pin[1];
  joy[2] = pin[2];
  joy[3] = pin[3];
}

void JoystickArm::Read()
{
  for (int i = 0; i < len; i++)
  {
    acc[i] = (analogRead(joy[i]) - 512) / 50;
    servoPosition[i] = constrain((servoPosition[i] + acc[i]), 1, 180);
  }
  swivel(servoPosition[0]);
  move_bot1(servoPosition[1]);
  move_bot2(servoPosition[1]);
  if(mode == LOW){
    move_mid(servoPosition[2]);
    move_top(servoPosition[3]);
  }
  else{
    move_wrist(servoPosition[2]);
   }
  delay(50);
}

void JoystickArm::toggle(){
   curr_state = digitalRead(button);
   if (curr_state != last_state)
   {
      if (count%2 == 1){
        mode = HIGH;
      }
      else
      {
        mode = LOW;  
      }
      count++;
   }
}

void JoystickArm::btn(int bt){
  button = bt;
  pinMode(bt, INPUT_PULLUP);
}
