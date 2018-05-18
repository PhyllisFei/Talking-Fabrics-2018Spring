//send code

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write('H');
  delay(1000);
  Serial.write('L');
  delay(1000);
}
