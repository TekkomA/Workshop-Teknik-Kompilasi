
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" 

#define LEDpin D0

//SSID and Password of your WiFi router
const char* ssid = "Dewansyah";
const char* password = "monaco2tc1";

//bool ledState = false;

ESP8266WebServer server(80); 

void handleRoot(){
  server.send(200,"text/html",MAIN_page);
}

//void ledControl(){
//   server.send(200,"text/html",MAIN_page);
//   if (ledState == false){
//      digitalWrite(LEDpin,HIGH);
//      ledState = true; 
//   }
//   else {
//      digitalWrite(LEDpin,LOW);
//      ledState = false;
//   }
//}

//Fungsi Control LED
void ledOn(){
  server.send(200,"text/html",MAIN_page);
  digitalWrite(LEDpin,HIGH);
  delay(1000);
}

void ledOff(){
  server.send(200,"text/html",MAIN_page);
  digitalWrite(LEDpin,LOW);
  delay(1000);
}

void setup(void){
  Serial.begin(9600);
  pinMode(LEDpin,OUTPUT);
  WiFi.begin(ssid, password);     
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
 
  server.on("/", handleRoot); 
  //Mengakses alamat /LEDON atau /LEDOFF dan memanggil fungsi led control
  server.on("/LEDON",ledOn);
  server.on("/LEDOFF",ledOff);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();          //Handle client requests
}
