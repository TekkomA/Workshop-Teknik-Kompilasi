#include "ESP8266WiFi.h"

//Nama Wifi dan Passwordnya
const char ssid[] = "Dewansyah";
const char pass[] = "monaco2tc1";

void setup() {
  Serial.begin(115200);
  //Menghubungkan ke Wifi
  WiFi.begin(ssid,pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Print IP Address dan MAC Address
  Serial.print(" Connected to ");Serial.println(ssid); 
  Serial.printf("IP address: %s\n", WiFi.localIP().toString().c_str());
  Serial.print("MAC: ");Serial.println(WiFi.macAddress());
  delay(100);

}

void loop() {
  //Scan Wifi yang terjangkau
  Serial.println("");
  Serial.println("List Available Wifi :");
  int n = WiFi.scanNetworks();
  Serial.println("");
  if (n == 0) {
    Serial.println("No Wifi Available");
  } else {
    Serial.print(n);
    Serial.println(" Wifi Networks Found");
    //Looping sejumlah Wifi yang terdeteksi
    for (int i = 0; i < n; ++i) {
      // Print SSID,RSSI,dan MAC Address wifi yang terdeteksi
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.println(")");
      Serial.print(") MAC:");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" Unsecured":" Secured");
      delay(10);
    }
  }
  Serial.println("");
  delay(10000);
}
