#include <SoftwareSerial.h>

SoftwareSerial SoftSerial (2, 3);
unsigned char buffer[64];       // buffer array for data receive over serial port
int count = 0;                  // counter for buffer array
long value;

void setup() {
  SoftSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (SoftSerial.available()) {
    //value = 0;
    while (SoftSerial.available()) {
      buffer[count++] = SoftSerial.read();      // writing data into array
      //      value [count++] = SoftSerial.read();
      if (count == 64)break;
    }
    Serial.write(buffer, count);    // if no data transmission ends, write buffer to hardware serial port
    clearBufferArray();             // call clearBufferArray function to clear the stored data from the array
    count = 0;                      // set counter of while loop to zero
    //value = buffer;
  }
  if (Serial.available())             // if data is available on hardware serial port ==> data is coming from PC or notebook
    SoftSerial.write(Serial.read());    // write it to the SoftSerial shield
  //  while (Serial.available()) {
  //    value = Serial.read();
  //  }
  //  for ( int i = 0; i < 12; i++) {
  //    value[i] = buffer[i];
  //    Serial.print(value[i]);
  //
  //  }
  value = (buffer, HEX);
  //Serial.println(buffer[10]);
  if (value == 3301671259654) {
    Serial.println("H");
//    digitalWrite(LED_BUILTIN, HIGH);
  }
  delay(200);
}



void clearBufferArray() {
  for (int i = 0; i < count; i++) {
    buffer[i] = NULL;
  }
}
