int val = 0;

void setup() {
  // this makes my pin an output pin
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);

  //Let's talk
  //  Serial.begin(9600); //speak at baud rate
}

void loop() {
  val = digitalRead(2);
  if (val == 1) {
    digitalWrite(10, HIGH);
  } else {
    analogWrite(10, LOW);
  }
}
