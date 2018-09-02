 
#include <SPI.h>
#include <ESP8266WiFi.h>
#include<Wire.h>
const int MPU6050_addr=0x68;
float AccX,AccY,AccZ;
int16_t GyroX,GyroY,GyroZ,Temp;


char ssid[] = "******";          
char pass[] = "******";           

unsigned long askTimer = 0;

IPAddress server(***,***,**,**);       
WiFiClient client;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);

  
  WiFi.begin(ssid, pass);             
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

}

void loop () {
  client.connect(server, 80);   
  
  while(true)
  {
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();

  

 client.println(((AccZ*1000)/16384 )+'\r');
 delay(10);
 client.println(((AccY*1000)/16384) +'\r');
  }
                  
}
