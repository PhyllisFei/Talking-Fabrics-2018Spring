//receive code

int incomingByte;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0 ) {
  incomingByte = Serial.read();

    if (incomingByte == 'H') {
      digitalWrite(13, HIGH);
    }
    if (incomingByte == 'L') {
      digitalWrite(13, LOW);
    }
  }
}
