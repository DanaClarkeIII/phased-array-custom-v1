
#ifndef DCPhasedArray_h
#define DCPhasedArray_h

#include "Arduino.h"

class DCPhasedArray {
public:
  DCPhasedArray(float freq, float elementSpacing);
  void applyPhaseShift(float degrees);
private:
  float frequency;
  float elementSpacing;
  float wavelength;
  float calculatePhaseShift(float degrees);
};

#endif
