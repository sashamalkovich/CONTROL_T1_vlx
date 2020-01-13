#ifndef _LIB_VLX_H_
#define _LIB_VLX_H_

#include <VL53L0X.h>
#include <Wire.h>

class LibVlx {

public:
    explicit LibVlx();

    ~LibVlx();

    void setup();

    byte get(uint16_t &, uint16_t &);

private:
    int analogValue[2];
    int lastAnalogValue[2];
    unsigned int MIDI_CHANNEL;
    unsigned int VLX_Control;
    unsigned int MIN_VLX;
    unsigned int MAX_VLX;
    unsigned int distance;

    byte vlxSensor(byte, byte, int, int *, int *, uint16_t &, uint16_t &);

    VL53L0X sensor;
};

#endif //_LIB_VLX_H_
