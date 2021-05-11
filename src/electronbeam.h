/** @file sample.h
*   @brief header file for class ElectronBeam
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#ifndef ELECTRONBEAM_H
#define ELECTRONBEAM_H

#include <memory>
#include <vector>
#include <QObject>

class ElectronBeam {
    int position;
    double scale;
    double vergency;
    double deflectionXAxis;
    double deflectionXRatio;
    double deflectionZAxis;
    double deflectionZRatio;

    std::vector<QObject*>beamObj;

public:
    ElectronBeam(int, double, double, double, double, double ,double );

    void decPosition() { position--; }

    void decScale(double dec) { scale -= dec; }

    void incScale(double inc) { scale += inc; }

    double getVergency() { return vergency; }

    void setVergency(double ver) { vergency = ver; }

    int getPosition() { return position; }
    
    void setPosition(int newPos) { position = newPos; }

    double getScale() {  return scale; }
    
    void setScale(double newScale) { scale = newScale ; }
    /**
    * Inserts beam object to vector
    * 
    * @param beam object
    * 
    */
    void insertBeam(QObject* beam) { beamObj.push_back(beam); }

    void setDeflectionXRat(double newXRat) { deflectionXRatio = newXRat; }

    void refDeflectionXRat() { deflectionXRatio *= -1; }

    double getDeflectionX() { return deflectionXAxis;  }

    void insDeflectionX(double X) { deflectionXAxis += X ; }

    double getDeflectionXRat() { return deflectionXRatio; }

    void setDeflectionZRat(double newZRat) { deflectionZRatio = newZRat; }

    double getDeflectionZRat() { return deflectionZRatio ;  }

    void refDeflectionZRat() { deflectionZRatio *= -1; }

    double getDeflectionZ () { return deflectionZAxis; }

    void insDeflectionZ(double Z) { deflectionZAxis += Z; }
    
    void deleteBeam();


};

#endif // ELECTRONBEAM_H
