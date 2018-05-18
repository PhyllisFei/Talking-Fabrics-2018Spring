#include <SoftwareSerial.h>

SoftwareSerial SoftSerial1 (7, 8);
SoftwareSerial SoftSerial2 (2, 3);
unsigned char buffer[64];       // buffer array for data receive over serial port
int count = 0;                  // counter for buffer array

void setup() {
  SoftSerial1.begin(9600);
  SoftSerial2.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // ***** RFID1 ***** //
  //  SoftSerial1.listen();
  if (SoftSerial1.available()) {
    while (SoftSerial1.available()) {
      buffer[count++] = SoftSerial1.read();      // writing data into array
      if (count == 64)break;
    }
    Serial.write(buffer, count);    // if no data transmission ends, write buffer to hardware serial port
    clearBufferArray();             // call clearBufferArray function to clear the stored data from the array
    count = 0;                      // set counter of while loop to zero
  }

  if (Serial.available()) {
    //    Serial.print('2');
    SoftSerial1.write(Serial.read());
  }

  // ***** RFID2 ***s* //
  //  SoftSerial2.listen();
  if (SoftSerial2.available()) {
    while (SoftSerial2.available()) {
      buffer[count++] = SoftSerial2.read();      // writing data into array
      if (count == 64)break;
    }
    Serial.write(buffer, count);    // if no data transmission ends, write buffer to hardware serial port
    clearBufferArray();             // call clearBufferArray function to clear the stored data from the array
    count = 0;                      // set counter of while loop to zero
  }
  if (Serial.available()) {
    Serial.print('1');
    SoftSerial2.write(Serial.read());
  }
}

void clearBufferArray() {
  // clear all index of array with command NULL
  for (int i = 0; i < count; i++) {
    buffer[i] = NULL;
  }
}
