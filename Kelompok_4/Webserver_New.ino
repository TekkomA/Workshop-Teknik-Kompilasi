#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "files.h"

#define output LED_BUILTIN
#define PIN_POTENSIO A0

String outputState = "off";
String html;
String text = "";

bool state = false;
bool potensioState = false;

const char* ssid = "ZaCK"; //Enter Wi-Fi SSID
const char* password =  "2444666668888888000000";

int data = 0;

void handleHTML();
void handleHTMLPotensio();
void handleCSS();
void handlePic1();
void handlePic2();
void handlePic3();
void handlePotensio();

ESP8266WebServer server(80);  //port 80

void setup(void) {
  pinMode(PIN_POTENSIO, INPUT);
  pinMode(output, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/data.txt", handlePotensio);
  server.on("/index.html", handleHTML);
  server.on("/index2.html", handleHTMLPotensio);
  server.on("/assets/css/main.css", handleCSS);
  server.on("/images/jumbotron.png", handlePic1);
  server.on("/images/icon/001-led.png", handlePic2);
  server.on("/images/icon/002-resistor.png", handlePic3);
  server.begin();
  Serial.println("Web server started!");
}

void loop(void) {
  if(WiFi.status() == WL_CONNECTED){
    data = analogRead(PIN_POTENSIO);
//    data++;
//    if(data >= 255){
//      data = 0;
//    }
    delay(20);
    server.handleClient();
  }else{
    WiFi.begin(ssid, password);
    Serial.print("Connecting to: ");
    Serial.print(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  }
}

void handleHTML(){
  if(potensioState){
    html = html1 + htmlScript + html2;
  }else{
    html = html1 + html2;
  }
  if(state){
    digitalWrite(output, HIGH);
    state = !state;
  }else{
    digitalWrite(output, LOW);
    state = !state;
  }
  server.send(200, "text/html", html.c_str());
}

void handleHTMLPotensio(){
  html = html1 + htmlScript + html2;
  potensioState = true;
  server.send(200, "text/html", html.c_str());
}

void handleCSS(){
  server.send_P(200, "text/css", css);
}

void handlePic1(){
  server.send_P(200, "images/jpg", jumbotron, sizeof(jumbotron));
}

void handlePic2(){
  server.send_P(200, "images/jpg", led, sizeof(led));
}

void handlePic3(){
  server.send_P(200, "images/jpg", resistor, sizeof(resistor));
}

void handlePotensio(){
  text = "Nilai : " + (String)data;
  server.send(200, "text/html", text);
}
