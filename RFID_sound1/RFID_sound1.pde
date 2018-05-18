import processing.serial.*;
import processing.sound.*;

Serial myPort;
String inBuffer = " ";

SoundFile soundfile1; 
SoundFile soundfile2; 

void setup() {
  size(512, 512);
  frameRate(10);
  println(Serial.list());

  //myPort = new Serial(this, Serial.list()[3], 9600);
  myPort = new Serial(this, Serial.list()[4], 9600);

  soundfile1 = new SoundFile(this, "cry_cartoon.wav");
  soundfile2 = new SoundFile(this, "snoring_baby.wav");
  
  //crying
  soundfile1.play();
}

void draw() {
  if (inBuffer != " ") {
    drawTag(inBuffer);
  }
}

void serialEvent(Serial myPort) {
  while (myPort.available() > 13) {
    inBuffer = myPort.readString();   
    inBuffer = inBuffer.trim();
    if (inBuffer != null) {
      println(inBuffer);
    }
  }
}

void drawTag(String tagVal) {
  background(0);

  if (tagVal.equals("18002700C9F6")) {
    fill(255, 0, 0);
    ellipse(width/2, height/2, 100, 100);
    // stop crying with the blue snap
    soundfile1.stop();
    soundfile2.stop();
  }
  
  if (tagVal.equals("0300B4A34155")) {
    fill(255, 255, 0);
    ellipse(width/2, height/2, 100, 100);
    // start snoring
    soundfile2.play();
  }
  inBuffer = " ";
}
