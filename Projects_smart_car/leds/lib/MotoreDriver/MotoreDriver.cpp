#include "MotoreDriver.h"
#include "Arduino.h"

#define Led          D9
//#define ENASpeed     D10
#define pinR1        D1   //14 
#define pinL1        D2   //12 
#define pinR2        D3   //13 
#define pinL2        D4   //15
#define S0           D5
#define S1           D6
#define S2           D7
#define S3           D8
#define ColorsOutput D0





int _speed;

int x;
int y;
int maxspeed;
int _red  ;
int _green ;
int _blue ;
int _led;

ControlTime ColorSensor;
color RGBcolor;




void Controler_ColorSensor(int _pin,int _time){
    ColorSensor.delay = _time;
    ColorSensor.pin = _pin;
    ColorSensor.running = true;
    

};

bool TimeToToggle_ColorSensor(){
    int CurrentTime = millis();
    if(CurrentTime - ColorSensor.LastTime > ColorSensor.delay){
        ColorSensor.LastTime = CurrentTime;
        return true;

    }
    return false;
};

void UpdateSensor(){
    if(ColorSensor.running && TimeToToggle_ColorSensor()  ){
        if(_red==1){
            followRed();
        }else if(_green == 2){
             followGreen();
        }else if(_blue == 3){
             followBlue();
        }
       
        
    }


};
void followRed(){
    ReadSensor();
    int red = RGBcolor.red;
    int green = RGBcolor.green;
    int blue = RGBcolor.blue;

       Serial.print("R:");
    Serial.println(red);
    Serial.print("G:");
    Serial.println(green);
    Serial.print("B:");
    Serial.println(blue);
    
    if(( blue >= 90 && blue <= 130 && red >= 20 && red <=60 &&  green >= 100 && green <= 190 ) || (blue >= 40 && blue <= 60 && red >= 110 && red <=150 &&  green >= 100 && green <= 130)){
        
       carForward();
      Serial.println("REEEEEEEEEED");
          
    } else if (green >= 10 && green <= 40 && red >= 10 && red <= 40  && blue >= 10 && blue <= 40) { 
       
       carForwardLeft();
      
       
          Serial.println("wighttttttttt");
          while(!(RGBcolor.blue >= 100 && RGBcolor.blue <= 130 && RGBcolor.red >= 20 && RGBcolor.red <=60 &&  RGBcolor.green >= 100 && RGBcolor.green <= 190 )){
               carForwardLeft();
               Serial.println("wighttttttttt");
               ReadSensor();



          }
         
       
       

     }else if(red > 200 && green > 200 && blue > 200){
        carStop();

     }else{ 
       carForwardRight();
          Serial.println("yellooooooooooooooo");
     }
     //Serial.println("RED BOTTON");
        };
        void followGreen(){
            Serial.println("GREEN BOTTON");
             ReadSensor();
    int red = RGBcolor.red;
    int green = RGBcolor.green;
    int blue = RGBcolor.blue;

       Serial.print("R:");
    Serial.println(red);
    Serial.print("G:");
    Serial.println(green);
    Serial.print("B:");
    Serial.println(blue);
    
    if( blue >= 60 && blue <= 90 && red >= 40 && red <=60 &&  green >= 30 && green <= 60 ){
        
       carForward();
      Serial.println("Grennnnnnnnnnnnn");
          
    } else if (green >= 10 && green <= 40 && red >= 10 && red <= 40  && blue >= 10 && blue <= 40) { 
       
       carForwardLeft();
      
       
          Serial.println("wighttttttttt");
          while(!(RGBcolor.blue >= 60 && RGBcolor.blue <= 90 && RGBcolor.red >= 40 && RGBcolor.red <=60 &&  RGBcolor.green >= 30 && RGBcolor.green <= 60 )){
               carForwardLeft();
               Serial.println("wighttttttttt");
               ReadSensor();

          }
         

     }else if(red > 200 && green > 200 && blue > 200){
        carStop();

     }else{ 
       carForwardRight();
          Serial.println("yellooooooooooooooo");
     }
        };

        void followBlue(){
            Serial.println("BLUE BOTTON");
              ReadSensor();
    int red = RGBcolor.red;
    int green = RGBcolor.green;
    int blue = RGBcolor.blue;

       Serial.print("R:");
    Serial.println(red);
    Serial.print("G:");
    Serial.println(green);
    Serial.print("B:");
    Serial.println(blue);
    
    if( blue >= 40 && blue <= 60 && red >= 110 && red <=150 &&  green >= 100 && green <= 130 ){
        
       carForward();
      Serial.println("bluuuuuuuuuuuuuuuue");
          
    } else if (green >= 10 && green <= 40 && red >= 10 && red <= 40  && blue >= 10 && blue <= 40) { 
       
       carForwardLeft();
      
       
          Serial.println("wighttttttttt");
          while(!(RGBcolor.blue >= 40 && RGBcolor.blue <= 60 && RGBcolor.red >= 110 && RGBcolor.red <=150 &&  RGBcolor.green >= 100 && RGBcolor.green <= 130 )){
               carForwardLeft();
               Serial.println("wighttttttttt");
               ReadSensor();



          }
         
       
       

     }else if(red > 200 && green > 200 && blue > 200){
        carStop();

     }else
      { 
       
       carForwardRight();
          Serial.println("yellooooooooooooooo");

     }


        };
          
      
     /* else if( green >= 0 && green <= 10){

        carForwardRight();

        if(blue >= 40 && blue <= 60 && red >= 20 && red <=30 ){

            carForwardLeft();
        }
          
      
    }*/
    




void carForward(){

        analogWrite(pinR1, maxspeed);
        analogWrite(pinL1 , 0);
        analogWrite(pinR2 , maxspeed);
        analogWrite(pinL2 , 0);

};
void carForwardRight(){

        analogWrite(pinR1, 0);
        analogWrite(pinL1 , maxspeed);
        analogWrite(pinR2 , maxspeed);
        analogWrite(pinL2 , 0);


};
void carForwardLeft(){

        analogWrite(pinR1, maxspeed);
        analogWrite(pinL1 , 0);
        analogWrite(pinR2 , 0);
        analogWrite(pinL2 , maxspeed);

};
void carBackward() {

        analogWrite(pinR1, 0);
        analogWrite(pinL1, maxspeed);
        analogWrite(pinR2 , 0);
        analogWrite(pinL2, maxspeed);
    

};

void carStop(){
          analogWrite(pinR1, 0);
        analogWrite(pinL1, 0);
        analogWrite(pinR2 , 0);
        analogWrite(pinL2, 0);

};
void moveControl()
{
   
   

     if(x > 400 )
    {
    
   
    carForward();

   
    }
    else if( x < -400)
    {

    carBackward();
    

    }else if(x==0 && y==0){

        carStop();
       

   }else if(y > 400){

        carForwardLeft();

   }else if( y < -400 ){

        
        carForwardRight();

   }


}


void initMotores(){

    pinMode(Led, OUTPUT);
    pinMode(pinL1, OUTPUT);
    pinMode(pinL2 , OUTPUT);
    pinMode(pinR1, OUTPUT);
    pinMode(pinR2, OUTPUT);
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(ColorsOutput, INPUT);
    digitalWrite(S0,HIGH);
    digitalWrite(S1,LOW);
   // analogWrite(ENASpeed,maxspeed);


    

};
void setSpeedMotore(int speed){
    maxspeed = speed;
    Serial.println(maxspeed);

};
void setX(int _x){
    x = _x;

};
void setY(int _y){
    y = _y;

};
int getX(){
return x;

};
int getY(){
  return y;
};

int getSpeedMotore(){
    return _speed;
};
void setled(int led){

    _led=led;
   // Serial.println(_led);
     digitalWrite(Led, _led);

};


void ReadSensor(){

    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    int _red = pulseIn(ColorsOutput,LOW);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    int _green = pulseIn(ColorsOutput,LOW);
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
     int _blue = pulseIn(ColorsOutput,LOW);
    RGBcolor.red = _red;
    RGBcolor.green = _green;
    RGBcolor.blue = _blue;


   /* Serial.print("R:");
    Serial.println(red);
    Serial.print("G:");
    Serial.println(green);
    Serial.print("B:");
    Serial.println(blue);
   */
   
    

};
void setcolor1(int color){
  _red = color;


};
void setcolor2(int color){
 _green = color +1 ;
};
void setcolor3(int color){
 _blue = color+2 ;
};

void updateMotore(){
  
   
 if(_red == 1){
   UpdateSensor();
   
    
 }else if(_green == 2){
     UpdateSensor();

 }else if(_blue == 3){
     UpdateSensor();

 }else{
     moveControl();
 }
 
//Serial.println(_tem);


};



