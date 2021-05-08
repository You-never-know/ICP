#ifndef LIGHTBEAM_H
#define LIGHTBEAM_H
#include <memory>

class ElectronBeam
{
  std::unique_ptr<int> position;
  std::unique_ptr<float> xscale;
public:
    ElectronBeam(int,float);
    void decPosition() { (*position)--; }
    void decScale() { (*xscale)-=0.005; }
    int getPosition() { return *position; }
    float getScale() {  return *xscale; }
    void setScale(float newScale) { *xscale = newScale ;}
};

#endif // LIGHTBEAM_H
