#ifndef ROBO_ARM_H
#define ROBO_ARM_H

#include <Servo.h>
#include <Arduino.h>  

class Arm
{
  private: 
      Servo bottom1_s;
      Servo bottom2_s;
      Servo swivel_s;
      Servo middle_s;
      Servo top_s;
      Servo wrist_s;
  
  public:
      Arm();
      void swivel(int angle);
      void move_bot1(int angle);
      void move_bot2(int angle);
      void move_mid(int angle);
      void move_top(int angle);
      void move_wrist(int angle);
      void move_claw(int angle);
      void begin_(int bot1, int bot2, int sw, int mid, int top, int wrist);
};

class JoystickArm : public Arm
{
  private: 
     int joy[4];
     int servoPosition[4] = {90,90,90,90};
     int len = 4;
     int acc[4] = {0,0,0,0};
     int mode = LOW;
     int last_state = HIGH;
     int curr_state;
     int count = 0;
     int button;

  public:
      JoystickArm(int* pin);
      void Read();  
      void toggle();    
      void btn(int bt);
};
#endif 
