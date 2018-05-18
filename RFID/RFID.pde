import processing.sound.*;
import processing.serial.*;

String myString = null;
Serial myPort;
int valueFromArduino;

SoundFile soundfile1; 
SoundFile soundfile2; 

void setup() {
  size(800, 600);
  background(0);

  setupSerial();

  soundfile1 = new SoundFile(this, "cry_baby.wav");
  soundfile2 = new SoundFile(this, "snoring_baby.wav");

}

void draw() {
  updateSerial();
}

void setupSerial() {
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[ 3], 9600);

  myPort.clear();

  myString = myPort.readStringUntil( 10 );
  myString = null;
}



void updateSerial() {
  while (myPort.available() > 0) {
    valueFromArduino = myPort.read();
    println(valueFromArduino);
    
  }
}
