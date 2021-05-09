#ifndef LIGHTBEAM_H
#define LIGHTBEAM_H

#include <memory>

class ElectronBeam {
    std::unique_ptr<int> position;
    std::unique_ptr<double> scale;
    std::unique_ptr<double> vergency;
    std::unique_ptr<double> deflectionXAxis;
    std::unique_ptr<double> deflectionZAxis;

public:
    ElectronBeam(int, double, double, double, double);

    void decPosition() { (*position)--; }

    void decScale(double dec) { (*scale) -= dec; }

    void incScale(double dec) { (*scale) += dec; }

    double getVergency() { return *vergency; }

    void setVergency(double ver) { (*vergency) = ver; }

    int getPosition() { return *position; }

    double getScale() { return *scale; }

    void setScale(double newScale) { *scale = newScale; }

    //double calcScale(){ return vergency/100 }
};

#endif // LIGHTBEAM_H
