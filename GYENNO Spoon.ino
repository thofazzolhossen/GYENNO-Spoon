#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h" 


#include <Servo.h>

Servo myservo;  // create servo object to control a servo



MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;

void setup()
{
  Serial.begin(9600);

  //MPU6050
  Wire.begin();
  mpu.initialize();


  //Servo
  myservo.attach(3);
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255); 
  data.Z = map(az, -17000, 17000, 0, 255);  // Y axis data
  delay(500);

   int  x= data.X-130;
  
  if(x<0){
     
        myservo.write(90-(-1*(x)) );
        Serial.println( 90-(-1*(x)) );   
  }
 else{
   myservo.write(90+x);
  }

}