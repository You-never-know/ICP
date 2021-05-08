#ifndef LIGHTBEAM_H
#define LIGHTBEAM_H
#include <memory>

class ElectronBeam
{
  std::unique_ptr<int> position;
  std::unique_ptr<double> xscale;
public:
    ElectronBeam(int,double);
    void decPosition() { (*position)--; }
    void decScale() { (*xscale)-=0.005; }
    int getPosition() { return *position; }
    double getScale() {  return *xscale; }
    void setScale(double newScale) { *xscale = newScale ;}
};

#endif // LIGHTBEAM_H
