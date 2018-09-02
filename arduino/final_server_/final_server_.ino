
#include <SPI.h>
#include <ESP8266WiFi.h>


char ssid[] = "******";               
char pass[] = "******";               
WiFiServer server(80);                    

IPAddress ip(192, 168,43,16);           
IPAddress gateway(192,168,43,1);          
IPAddress subnet(255,255,255,0);          

void setup() {
  Serial.begin(9600);                   
  WiFi.config(ip, gateway, subnet);      
  WiFi.begin(ssid, pass);                 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);}
  server.begin();                   
}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {

      while(true){
      String request1 = client.readStringUntil('\r');
      delay(10);
      String request2 = client.readStringUntil('\r');
      
      Serial.println(1);
      delay(10);
      Serial.println(request1.toFloat());
      delay(10);
      Serial.println(2);
      delay(10);
      Serial.println(request2.toFloat());
      delay(10);
      client.flush();
      }
     
    }
    client.stop();
  }
}
