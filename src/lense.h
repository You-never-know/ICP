/** @file lense.h
*   @brief header file for class Lense
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#ifndef LENSE_H
#define LENSE_H

#include "electronbeam.h"

enum LenseType {
    Condenser, ObjectiveAperture, Intermediate, Projector, Error
};

class Lense {
    LenseType type;
    int position;
    double vergency;
    double deflectionXAxis;
    double deflectionZAxis;
public:
    Lense(LenseType type, int position, double vergency, double deflectionXAxis, double deflectionZAxis);

    Lense();

    /**
    * Gets lense's position
    * 
    * @return position of lense
    * 
    */
    int getPosition();

    /**
    * Sets lense's position
    * 
    * @param position of lense
    */
    void setPosition(int position);
    /**
    * Gets lense's vergency
    * 
    * @return vergency of lense
    */
    double getVergency();
    /**
    * Sets lense's vergency
    * 
    * @param vergency of lense
    */
    void setVergency(double vergency);
    /**
    * Gets lense's DeflectionX
    * 
    * @return DeflectionX
    */
    double getDeflectionXAxis();
    /**
    * Sets lense's DeflectionX
    * 
    * @param DeflectionX of lense
    */
    void setDeflectionXAxis(double deflection);
    /**
    * Gets lense's DeflectionZ
    * 
    * @return DeflectionZ
    */
    double getDeflectionZAxis();
    /**
    * Sets lense's DeflectionZ
    * 
    * @param DeflectionZ of lense
    */
    void setDeflectionZAxis(double deflection);
    /**
    * Gets lense's type
    * 
    * @return type of lense
    */
    enum LenseType getType();

};

#endif // LENSE_H
