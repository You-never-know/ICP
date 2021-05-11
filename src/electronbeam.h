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
    /**
    * @brief Constructor for class ElectronBeam
    * 
    */
    ElectronBeam(int, double, double, double, double, double ,double );
    /**
    * @brief Decrements position of beam
    *  
    */
    void decPosition() { position--; }
    /**
    * @brief Decrements scale
    * 
    * @param decrement
    */
    void decScale(double dec) { scale -= dec; }
    /**
    * @brief Increments scale
    * 
    * @param increment
    */
    void incScale(double inc) { scale += inc; }
    /**
    * @brief Gets Vergency of beam
    * 
    * @return vergency of electronbeam
    */
    double getVergency() { return vergency; }
    /**
    * @brief Sets Vergency of beam
    * 
    * @param vergency of electronbeam
    */
    void setVergency(double ver) { vergency = ver; }
    /**
    * @brief Gets position of beam
    * 
    * @return vergency of electronbeam
    */
    int getPosition() { return position; }
    /**
    * @brief Sets position of beam
    * 
    * @param position of beam
    */
    void setPosition(int newPos) { position = newPos; }
    /**
    * @brief Gets scale of beam
    * 
    * @return scale of beam
    */
    double getScale() {  return scale; }
    /**
    * @brief Sets scale of beam
    * 
    * @param scale of beam
    */   
    void setScale(double newScale) { scale = newScale ; }
    /**
    * @brief Inserts beam object to vector
    * 
    * @param beam object
    * 
    */
    void insertBeam(QObject* beam) { beamObj.push_back(beam); }
    /**
    * @brief Setter for DeflectionXRatio
    * 
    * @param New X ratio
    * 
    */
    void setDeflectionXRat(double newXRat) { deflectionXRatio = newXRat; }
    /**
    * @brief Reflection of DeflectionXRatio
    * 
    * 
    */
    void refDeflectionXRat() { deflectionXRatio *= -1; }
    /**
    * @brief Gets DeflectionX
    * 
    * @return DeflectionX
    */
    double getDeflectionX() { return deflectionXAxis;  }
    /**
    * @brief Increments  DeflectionX
    * 
    * @param Increment
    * 
    */
    void insDeflectionX(double X) { deflectionXAxis += X ; }
    /**
    * @brief Gets DeflectionXRation
    * 
    * @return DeflectionXRation
    * 
    */
    double getDeflectionXRat() { return deflectionXRatio; }
    /**
    * @brief Sets DeflectionZRation
    * 
    * @param DeflectionZRation
    * 
    */
    void setDeflectionZRat(double newZRat) { deflectionZRatio = newZRat; }
    /**
    * @brief Gets DeflectionZRation
    * 
    * @return DeflectionZRation
    * 
    */
    double getDeflectionZRat() { return deflectionZRatio ;  }
    /**
    * @brief Reflects Z ratio
    * 
    * 
    */

    void refDeflectionZRat() { deflectionZRatio *= -1; }
    /**
    * @brief Gets DeflectionZ
    * 
    * @return DeflectionZ
    * 
    */ 
    double getDeflectionZ () { return deflectionZAxis; }
    /**
    * @brief Increments DeflectionZ
    * 
    * 
    */ 
    void insDeflectionZ(double Z) { deflectionZAxis += Z; }
    /**
    * @brief Deletes beam
    * 
    * 
    */   
    void deleteBeam();


};

#endif // ELECTRONBEAM_H
