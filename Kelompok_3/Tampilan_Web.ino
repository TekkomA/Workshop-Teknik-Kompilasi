#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" 

//SSID and Password of your WiFi router
const char* ssid = "Dewansyah";
const char* password = "monaco2tc1";

ESP8266WebServer server(80); 

void handleRoot(){
  server.send(200,"text/html",MAIN_page);
}

void setup(void){
  Serial.begin(9600);
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
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();          //Handle client requests
}
