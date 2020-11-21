int InputValue;

void setup() {
  // put your setup code here, to run once:
  pinMode (D0,OUTPUT); // PIN LED
  pinMode (A0,INPUT); // PIN Potensiometer

  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Baca Data Potensio
  InputValue = analogRead(A0);
  Serial.print("Data Potensio : ");
  Serial.println(InputValue);
  
  //Membuat LED berkedip tiap 1 detik
  digitalWrite(D0,HIGH);
  Serial.println("LED ON  ");
  delay(1000);
  digitalWrite(D0,LOW);
  Serial.println("LED OFF");
  delay(1000);

 
  delay(500);
}
