
#include "DCPhasedArray.h"

// Speed of light
constexpr float c = 3e8;

DCPhasedArray::DCPhasedArray(float freq, float elemSpacing)
: frequency(freq), elementSpacing(elemSpacing) {
  // Calculate the wavelength
  wavelength = c / frequency;
}

float DCPhasedArray::calculatePhaseShift(float degrees) {
  // Convert degrees to radians
  float radians = degrees * (PI / 180.0);

  // Calculate phase shift in radians
  float phaseShiftRadians = (2 * PI * elementSpacing / wavelength) * sin(radians);

  // Return phase shift in degrees, ensuring it's between 0-360
  float phaseShiftDegrees = phaseShiftRadians * (180.0 / PI);
  return fmod(phaseShiftDegrees, 360.0);
}

void DCPhasedArray::applyPhaseShift(float degrees) {
  float phaseShift = calculatePhaseShift(degrees);
  
  // TODO: Write the code to set the appropriate pins based on the calculated phase shift.
  // This is highly dependent on your specific hardware setup and how the phase shift corresponds to pin states.
  
  // Example of setting pins - this is just a placeholder and needs to be replaced with actual logic
  digitalWrite(6, phaseShift > 90 ? HIGH : LOW); // Pin for 0degAnt2, as an example
  digitalWrite(7, phaseShift > 180 ? HIGH : LOW); // Pin for 40degAnt2, as an example
  // Add similar lines for other pins and phase shifts
}
