#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h> //BEN ISO AKSES HTTPS

#define LED_PIN 5 
//Konfigurasi WiFi
const char *ssid = "Redmi";
const char *password = "123456789";
 
//IP Address Server yang terpasang XAMPP
const char *host = "kopasdri.com";
WiFiClientSecure klien;   //BEN ISO AKSES HTTPS

const int httpPort = 443;

bool Parsing = false;
String dataPHP, dataxx[8];

void setup() {
  Serial.begin(115200);
  //pinMode(5, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  //Jika koneksi berhasil, maka akan muncul address di serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  klien.setInsecure(); //BEN ISO AKSES HTTPS
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}
 
//int value = 0;
 
void loop() {
  // Proses Pengiriman -----------------------------------------------------------
  delay(1000);
  //++value;
 
  // Membaca Sensor Analog -------------------------------------------------------
  /*int datasensor=analogRead(A0);
  Serial.println(datasensor);
*/ 
  Serial.print("connecting to ");
  Serial.println(host);
 
// Mengirimkan ke alamat host dengan port 80 -----------------------------------
  
  if (!klien.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  int data = random(0,50);
// Isi Konten yang dikirim adalah alamat ip si esp -----------------------------
  String url = "/kompilasi/add_data.php?temperature=";
  url += data;
  url += "&id=1";
 
  Serial.print("Requesting URL: ");
  Serial.println(url);
 
// Mengirimkan Request ke Server -----------------------------------------------
  klien.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

  
  unsigned long timeout = millis();
  while (klien.available() == 0) {
    if (millis() - timeout > 1000) {
      Serial.println(">>> Client Timeout !");
      klien.stop();
      return;
    }
  }
 
// Read all the lines of the reply from server and print them to Serial
  while (klien.available()) {
    //String line = klien.readStringUntil('\r');
    dataPHP = klien.readStringUntil('\n');
    int q = 0;
    Serial.print("Data Masuk : ");
    Serial.print(dataPHP);
    Serial.println();

    dataxx[q] = "";
    for (int i = 0; i < dataPHP.length(); i++) {
        if (dataPHP[i] == '#') {
            q++;
            dataxx[q] = "";
        }
        else {
            dataxx[q] = dataxx[q] + dataPHP[i];
        }
    }
    Serial.println(dataxx[1].toInt());
    digitalWrite(LED_PIN, dataxx[1].toInt());
    Parsing = false;
    dataPHP = "";
  }
  
  Serial.println();
  Serial.println("closing connection");
}
