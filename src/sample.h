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
    unsigned int dataHeight;
    unsigned int dataWidth;

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
    /**
    *
    * Get height of the data sample(picture height)
    * @return the data height
    *
    */
    int getDataHeight() {return dataHeight;};
    /**
    *
    * Get width of the data sample(picture width)
    * @return the data width
    *
    */
    int getDataWidth() {return dataWidth;};
    /**
    *
    * Loads data to sample from the given file
    * @param filePath to the sample data file
    *
    */
    void loadData(std::string filePath);

    /**
    *
    * Inform sample that it has been scaned
    * @param path
    *
    */
    void sampleScaned(double beamVergency, double beamXDeflection, double beamZDeflection);
};

#endif // Sample_H
