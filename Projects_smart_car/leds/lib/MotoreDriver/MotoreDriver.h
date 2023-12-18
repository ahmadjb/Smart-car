#ifndef MOTORE_CONTROLER_H
#define MOTORE_CONTROLER_H

enum Direction{

    ClockWise = 0,
    C_ClockWise = 1
   // RClockWise = 2;
  //  LClockWise = 3;
    //RC_ClockWise = 4;
  //  LC_ClockWise = 5;


};


void initMotores();
void carForward();
void carBackward();
void carForwardRight();
void carForwardLeft();
void carStop();
void setX(int x);
void setY(int y);
int getX();
int getY();
void moveControl();
void setSpeedMotore(int speed);
void updateMotore();
int getSpeedMotore();
void repeatPath();
void ReadSensor();
void BlueSensor();
void GreenSensor();
void setcolor1(int color);
void setcolor2(int color);
void setcolor3(int color);
void setled(int led);
void followRed();
void followGreen();
void followBlue();
void Controler_ColorSensor(int pin,int time);
void Controler_UltraSonic(int pin,int time);
bool TimeToToggle_ColorSensor();
bool TimeToToggle_UltraSonic();
void UpdateSensor();
struct ControlTime{
  int pin;
  int delay;
  int LastTime;
  bool running;
};
struct color{
int red;
int green;
int blue;

};



#endif