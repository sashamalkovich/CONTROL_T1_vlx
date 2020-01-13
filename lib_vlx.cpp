#include "lib_vlx.h"

LibVlx::LibVlx() {
  //setup();
  MIN_VLX = 50;
  MAX_VLX = 320;
  VLX_Control = 15;
}

LibVlx::~LibVlx() = default;

void LibVlx::setup() {
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

byte LibVlx::get(uint16_t &DUR_MIN, uint16_t &DUR_MAX) {
  return vlxSensor(VLX_Control, MIDI_CHANNEL, 0, analogValue, lastAnalogValue, DUR_MIN, DUR_MAX);
}

byte LibVlx::vlxSensor(byte control, byte channel, int sensor_number, int *analogValue, int *lastAnalogValue, uint16_t &DUR_MIN, uint16_t &DUR_MAX) {
  distance = sensor.readRangeContinuousMillimeters();
  if (distance > DUR_MIN && distance < DUR_MAX) {
    analogValue[sensor_number] = map(distance, DUR_MIN, DUR_MAX, 0, 127);
    lastAnalogValue[sensor_number] = analogValue[sensor_number];
    return analogValue[sensor_number];
  }
  else {
    if (distance < DUR_MIN && distance > DUR_MIN - 20) {
      return 0;
    }
    if (distance > DUR_MAX && distance < DUR_MAX + 50) {
      return 127;
    }
    return 128;
  }
}
