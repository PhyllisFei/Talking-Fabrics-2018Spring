int sensorPin1 = A1;
int sensorPin2 = A2;

int sensorValue1 = 0;
int sensorValue2 = 0;

const int motorPin1 = 6;
const int motorPin2 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);

  //get sensor value
  Serial.print("sensorValue1: ");
  Serial.println(sensorValue1);
  Serial.print("sensorValue2: ");
  Serial.println(sensorValue2);

//turn on motor 1
  if (sensorValue1 >= 1023) {
    digitalWrite(motorPin1, HIGH);
    delay(1000);
  } else {
    digitalWrite(motorPin1, LOW);
  }

//turn on motor 2
  if (sensorValue2 > 800) {
    digitalWrite(motorPin2, HIGH);
    delay(1000);
  } else {
    digitalWrite(motorPin2, LOW);
  }
}
