// ****** xBee Test ****** //

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Sender();
  Receiver();
}

void Sender() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print('1');
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.print('0');
  delay(1000);
}

void Receiver() {
  while (Serial.available()) {
    if (Secial.read() == 'H') {
    digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
