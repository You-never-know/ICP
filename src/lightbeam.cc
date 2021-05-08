#include "lightbeam.h"

ElectronBeam::ElectronBeam(int pos, float scale)
{
  position = std::make_unique<int>(pos);
  xscale = std::make_unique<float>(scale);
}
