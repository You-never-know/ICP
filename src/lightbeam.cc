#include "lightbeam.h"

ElectronBeam::ElectronBeam(int pos, float scale)
{
  position = std::make_unique<int>(pos);
  xscale = std::make_unique<float>(scale);
}
void ElectronBeam::decPosition()
{
  (*position)--;
}
int ElectronBeam::getPosition()
{
  return *position;
}
void ElectronBeam::decXscale()
{
  (*xscale)-=0.01;
}
