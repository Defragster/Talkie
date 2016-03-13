// Talkie library
// Copyright 2011 Peter Knight
// This code is released under GPLv2 license.
//
// Welcome to the Talkie library examples.
//
// Talkie is a speech synthesiser that works from a fixed vocabulary.
//
// There are hundreds of words in the 'Vocabulary' examples.
//
// Sound is output on digital pin 3. It can drive headphones directly, or add a simple audio amplifier to drive a loudspeaker.
// 

#include <Talkie.h>

Talkie voice;

const uint8_t spDANGER[] PROGMEM = {0x2D, 0xBF, 0x21, 0x92, 0x59, 0xB4, 0x9F, 0xA2, 0x87, 0x10, 0x8E, 0xDC, 0x72, 0xAB, 0x5B, 0x9D, 0x62, 0xA6, 0x42, 0x9E, 0x9C, 0xB8, 0xB3, 0x95, 0x0D, 0xAF, 0x14, 0x15, 0xA5, 0x47, 0xDE, 0x1D, 0x7A, 0x78, 0x3A, 0x49, 0x65, 0x55, 0xD0, 0x5E, 0xAE, 0x3A, 0xB5, 0x53, 0x93, 0x88, 0x65, 0xE2, 0x00, 0xEC, 0x9A, 0xEA, 0x80, 0x65, 0x82, 0xC7, 0xD8, 0x63, 0x0A, 0x9A, 0x65, 0x5D, 0x53, 0xC9, 0x49, 0x5C, 0xE1, 0x7D, 0x2F, 0x73, 0x2F, 0x47, 0x59, 0xC2, 0xDE, 0x9A, 0x27, 0x5F, 0xF1, 0x8B, 0xDF, 0xFF, 0x03};
const uint8_t spMOTOR[]  PROGMEM = {0x66, 0xAA, 0x8C, 0x69, 0x53, 0x92, 0xC4, 0x2D, 0x2F, 0x6B, 0x2A, 0x74, 0xDA, 0x9D, 0xB2, 0xDD, 0xF6, 0x36, 0xAB, 0xCE, 0x78, 0xDA, 0x9D, 0xB2, 0xD5, 0x9A, 0x01, 0xDB, 0x77, 0x45, 0xA0, 0x75, 0xC5, 0xB8, 0x71, 0x59, 0xDA, 0x31, 0xE5, 0x6A, 0x22, 0x63, 0xDE, 0xDA, 0x9A, 0xBB, 0xA3, 0x75, 0x68, 0xAF, 0x7B, 0x3E, 0xC3, 0x9D, 0x97, 0x60, 0x87, 0xE6, 0x8B, 0x4F, 0x78, 0x4B, 0x76, 0xB2, 0x09, 0xAF, 0xFE, 0xFD, 0x7F};
const uint8_t spFIRE[]   PROGMEM = {0x04, 0x18, 0xCE, 0x4D, 0x02, 0x1A, 0xD0, 0x80, 0x04, 0x46, 0x91, 0x55, 0x57, 0x07, 0x6D, 0xD9, 0xCD, 0xAE, 0x4F, 0x55, 0x5D, 0x59, 0x87, 0xAE, 0xB9, 0xD5, 0x6D, 0x5B, 0xDB, 0x7D, 0x93, 0xB6, 0xED, 0xEE, 0xE3, 0x5A, 0x6B, 0x6A, 0xF4, 0x91, 0xD5, 0x73, 0x6B, 0x67, 0xF5, 0x47, 0xBC, 0xD4, 0xA7, 0x9C, 0xA5, 0x34, 0xE4, 0xD0, 0xA6, 0xF0, 0xE4, 0xAA, 0xB8, 0x2D, 0xAB, 0xC3, 0x9B, 0x62, 0xC2, 0xAC, 0x74, 0xF6, 0x9F, 0xFB, 0x72, 0x0B, 0xEC, 0x92, 0xCD, 0xEE, 0xCF, 0x43, 0x69, 0x4C, 0x5B, 0xFF, 0x3F};
const uint8_t spON[]     PROGMEM = {0x65, 0x4A, 0xEA, 0x3A, 0x5C, 0xB2, 0xCE, 0x6E, 0x57, 0xA7, 0x48, 0xE6, 0xD2, 0x5D, 0xBB, 0xEC, 0x62, 0x17, 0xBB, 0xDE, 0x7D, 0x9F, 0xDA, 0x5C, 0x5C, 0x7A, 0xAA, 0xB5, 0x6E, 0xCB, 0xD0, 0x0E, 0xAD, 0x6E, 0xAF, 0xEE, 0xF9, 0x88, 0x67, 0xBC, 0xDC, 0x3D, 0xAC, 0x60, 0xB8, 0x45, 0xF3, 0xB7, 0xBF, 0xC3, 0xDD, 0xA2, 0xBB, 0xAB, 0xCD, 0x89, 0x8F, 0x7F, 0xFE, 0x1F};
const uint8_t spRED[]    PROGMEM = {0x6A, 0xB5, 0xD9, 0x25, 0x4A, 0xE5, 0xDB, 0xC5, 0x4F, 0x6D, 0x88, 0x95, 0x2D, 0xD2, 0xB4, 0x8F, 0x2E, 0x37, 0x0E, 0x33, 0xCF, 0x7E, 0xAA, 0x9A, 0x5C, 0xC3, 0xB4, 0xCB, 0xA9, 0x86, 0x69, 0x76, 0xD3, 0x37, 0xB7, 0xBE, 0xCD, 0xED, 0xEF, 0xB4, 0xB7, 0xB0, 0x35, 0x69, 0x94, 0x22, 0x6D, 0x10, 0x28, 0x42, 0xB9, 0x8B, 0xC8, 0x06, 0x00, 0x50, 0xCF, 0x0E, 0xEE, 0x62, 0xEA, 0xA6, 0xBC, 0xC3, 0x14, 0xBB, 0x4A, 0x9F, 0xFA, 0xA5, 0xAF, 0x25, 0x13, 0x17, 0xDF, 0x9C, 0xBF, 0xFF, 0x07};
const uint8_t spIS[]     PROGMEM = {0xAD, 0xED, 0xD5, 0x58, 0xA4, 0x9E, 0xCE, 0x76, 0xF5, 0xDD, 0xAB, 0x29, 0xF5, 0xD2, 0xDD, 0xEF, 0x7E, 0x0C, 0xC3, 0xA9, 0x06, 0xFA, 0xD3, 0x32, 0x0F, 0x6E, 0x94, 0x22, 0x8F, 0xF3, 0x92, 0xF6, 0x05, 0x43, 0xCC, 0x74, 0x77, 0x3E, 0xC3, 0xF5, 0x95, 0x98, 0xA9, 0xBA, 0x8B, 0x8F, 0x00, 0x7E, 0x73, 0xE5, 0x00, 0x05, 0x28, 0xF0, 0xFF};
const uint8_t spALERT[]  PROGMEM = {0xA5, 0xCF, 0xC6, 0xAB, 0x55, 0x5B, 0xAF, 0x39, 0xDA, 0xC9, 0x54, 0xDD, 0xBC, 0xC6, 0xC2, 0x3C, 0x27, 0x20, 0xCF, 0x1C, 0xD7, 0x30, 0xB0, 0x45, 0x16, 0x69, 0x1D, 0xC3, 0x11, 0xE4, 0x59, 0x8A, 0x7C, 0xB5, 0x9B, 0x8B, 0xD9, 0x30, 0xB7, 0xD3, 0x76, 0x19, 0x9A, 0x25, 0x59, 0x57, 0x59, 0xEC, 0x11, 0xAF, 0xE8, 0xD9, 0xF9, 0x2A, 0x8A, 0x1D, 0xF0, 0x75, 0x3F, 0x73, 0xAC, 0x87, 0x3B, 0xA2, 0x0B, 0xAA, 0x2B, 0xCF, 0xE4, 0x10, 0xA1, 0xDC, 0x45, 0x64, 0x03, 0x00, 0x80, 0x01, 0x66, 0x36, 0x33, 0xC0, 0xAB, 0xD5, 0x0A, 0x68, 0x25, 0x85, 0x02, 0xFF, 0x0F};

void setup() {
  voice.say(spDANGER);
  voice.say(spDANGER);
  voice.say(spRED);
  voice.say(spALERT);
  voice.say(spMOTOR);
  voice.say(spIS);
  voice.say(spON);
  voice.say(spFIRE);
}
void loop() {
}
