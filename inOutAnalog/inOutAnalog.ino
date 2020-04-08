int inValue = 0;
int outValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  inValue = analogRead(0);
  outValue = inValue / 4;

//new added
  if (outValue > 180) {
    digitalWrite(9, LOW);
  } else {
    digitalWrite(9, HIGH);
  }

//  analogWrite(9, outValue);
  Serial.println(outValue);
  delay(10);
}
