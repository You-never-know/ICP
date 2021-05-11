/** @file sample.h
*   @brief header file for class Sample
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#ifndef SAMPLE_H
#define SAMPLE_H

#include <QtGlobal>
#include <vector>

#include "electronbeam.h"

class Sample {
    std::vector <quint8> samplesData;
    int samplePosition;
    int sampleRotation;
    bool flip;
public:
    Sample();

    /**
    * Sets position of sample
    * 
    * @param position of sample
    * 
    */
    void setPosition(int position);

    /**
    * Gets position of sample
    * 
    * @return position of sample
    * 
    */
    int getPosition();

    /**
    * Sets position of rotation
    * 
    * @param position of rotation
    * 
    */
    void setRotation(int rotation);
    /**
    * Get position of rotation
    * 
    * @return position of rotation
    * 
    */
    int getRotation();
    /**
    * 
    * Sets flip
    * @param state of flip
    * 
    */
    void setFlip(bool flip);
    /**
    * 
    * Gets flip
    * @return state of flip
    * 
    */
    bool getFlip();


};

#endif // Sample_H
