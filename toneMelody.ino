/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

int freq = 2000;
int channel = 0;
int resolution = 8;

int tonePin = 12;

int melody[] = {
  NOTE_C6, NOTE_E6, NOTE_C6, NOTE_G5, NOTE_F5, NOTE_G5, NOTE_B5, NOTE_D6,
  NOTE_C6, NOTE_G5, NOTE_C5,
};
int noteDurations[] = {
  8,8,8,8,8,8,8,8,
  4,4,2,
};

void setup() {
  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(tonePin, channel);
}

void loop() {
    for (int thisNote = 0; thisNote < 11; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      ledcWriteTone(channel, melody[thisNote]);
      delay(noteDuration);
      ledcWriteTone(channel, 0);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
}

