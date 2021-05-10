#ifndef LIGHTBEAM_H
#define LIGHTBEAM_H

#include <memory>
#include <vector>
#include <QObject>

class ElectronBeam {
    std::unique_ptr<int> position;
    std::unique_ptr<double> scale;
    std::unique_ptr<double> vergency;
    std::unique_ptr<double> deflectionXAxis;
    std::unique_ptr<double> deflectionZAxis;

    std::vector<QObject*>beamObj;

public:
    ElectronBeam(int, double, double, double, double);

    void decPosition() { (*position)--; }

    void decScale(double dec) { (*scale) -= dec; }

    void incScale(double dec) { (*scale) += dec; }

    double getVergency() { return *vergency; }

    void setVergency(double ver) { (*vergency) = ver; }

    int getPosition() { return *position; }
    void setPosition(int newPos) { *position = newPos; }

    double getScale() {  return *scale; }
    void setScale(double newScale) { *scale = newScale ; }
    void insertBeam(QObject* beam) { beamObj.push_back(beam); }
    void deleteBeam();


    //double calcScale(){ return vergency/100 }
};

#endif // LIGHTBEAM_H
