#include "lightbeam.h"

ElectronBeam::ElectronBeam(int pos, double newScale,double verg ,double deflectionX ,double deflectionZ)
{
  position = std::make_unique<int>(pos);
  scale = std::make_unique<double>(newScale);
  vergency = std::make_unique<double>(verg);
  deflectionXAxis = std::make_unique<double>(deflectionX);
  deflectionZAxis = std::make_unique<double>(deflectionZ);

}
