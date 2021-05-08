#include "lightbeam.h"

ElectronBeam::ElectronBeam(int pos, double scale)
{
  position = std::make_unique<int>(pos);
  xscale = std::make_unique<double>(scale);
}
