#include <ESP8266WiFi.h>                                                    // esp8266 library
#include <FirebaseArduino.h>                                                // firebase library
#include <DHT.h>                                                            // dht11 temperature and humidity sensor library

#define FIREBASE_HOST "test-7c972.firebaseio.com"                          // the project name address from firebase id
#define FIREBASE_AUTH "5C6ruFGKRhaepwL7p8EcM4cQZweh2r3DQ38RMMjC"            // the secret key generated from firebase

#define WIFI_SSID "kanu"                                             // input your home or public wifi name 
#define WIFI_PASSWORD "hello1212"                                    //password of wifi ssid
                                                     
int h=0;
void setup() {
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  delay(1000);                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                              // connect to firebase                                                              //Start reading dht sensor
}

void loop() { 
  h=h+1;
  String people = String(h) + String("%");                                                               //convert integer temperature to string temperature
  delay(4000);
  
  Firebase.setString("/Newval", people);                                  //setup path and send readings                             //setup path and send readings
   
}
