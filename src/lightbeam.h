#ifndef LIGHTBEAM_H
#define LIGHTBEAM_H
#include <memory>

class ElectronBeam
{
  std::unique_ptr<int> position;
  std::unique_ptr<float> xscale;
public:
    ElectronBeam(int,float);
    void decPosition();
    void decXscale();
    int getPosition();
    float getXscale() {  return *xscale; }
};

#endif // LIGHTBEAM_H
