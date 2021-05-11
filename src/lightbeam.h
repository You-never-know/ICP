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
    std::unique_ptr<double> deflectionXRatio;
    std::unique_ptr<double> deflectionZAxis;
    std::unique_ptr<double> deflectionZRatio;

    std::vector<QObject*>beamObj;

public:
    ElectronBeam(int, double, double, double, double, double ,double );

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

    void setDeflectionXRat(double X) { *deflectionXRatio = X; }

    double getDeflectionX() { return *deflectionXAxis;  }

    void insDeflectionX(double X) { (*deflectionXAxis) += X ; }

    double getDeflectionXRat() { return *deflectionXRatio; }

    void setDeflectionZRat(double Z) { *deflectionZRatio = Z; }

    double getDeflectionZRat() { return *deflectionZRatio ;  }

    double getDeflectionZ () { return *deflectionZAxis; }

    void insDeflectionZ(double Z) { (*deflectionZAxis) += Z; }
    
    void deleteBeam();


};

#endif // LIGHTBEAM_H
