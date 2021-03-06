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
    int scannedLeftIndex;
    int scannedRightIndex;
    int scannedUpIndex;
    int scannedDownIndex;

public:
    Sample();

    /**
    * @brief Sets position of sample
    * 
    * @param position of sample
    * 
    */
    void setPosition(int position);
    /**
    * @brief Gets position of sample
    * 
    * @return position of sample
    * 
    */
    int getPosition();

    /**
    * @brief Sets position of rotation
    * 
    * @param position of rotation
    * 
    */
    void setRotation(int rotation);
    /**
    * @brief Get position of rotation
    * 
    * @return position of rotation
    * 
    */
    int getRotation();
    /**
    * 
    * @brief Sets flip
    * @param state of flip
    * 
    */
    void setFlip(bool flip);
    /**
    * 
    * @brief Gets flip
    * @return state of flip
    * 
    */
    bool getFlip();
    /**
    *
    * @brief Get height of the data sample(picture height)
    * @return the data height
    *
    */
    int getDataHeight() {return dataHeight;};
    /**
    *
    * @brief Get width of the data sample(picture width)
    * @return the data width
    *
    */
    int getDataWidth() {return dataWidth;};
    /**
    *
    * @brief Loads data to sample from the given file
    * @param filePath to the sample data file
    *
    */
    void loadData(std::string filePath);

    /**
    *
    * @brief Inform sample that it has been scaned
    * @param path
    *
    */
    void sampleScaned(double beamScale, double beamXDeflection, double beamZDeflection);
    /**
    *
    * @brief Get data from the given pixel
    * @param xPosition of the wanted pixel
    * @param yPosition of the wanted pixel
    *
    */
    int getSampleData(int xPosition, int yPosition) {
        if (xPosition >= this->getDataWidth() or yPosition >= this->getDataHeight()) {
            return -1;
        }
        int index = yPosition * this->dataWidth + xPosition;
        if (index >= this->getDataHeight() * this->getDataWidth() - 1) {
            return -1;
        }
        return this->samplesData.at(index);
    }
    /**
    *
    * @brief Get upper index of the data
    * @return the upper index
    *
    */
    int getUpIndex() {return scannedUpIndex;}
    /**
    *
    * @brief Get bottom index of the data
    * @return the bottom index
    *
    */
    int getDownIndex() {return scannedDownIndex;}
    /**
    *
    * @brief Get left index of the data
    * @return the left index
    *
    */
    int getLeftIndex() {return scannedLeftIndex;}
    /**
    *
    * @brief Get right index of the data
    * @return the right index
    *
    */
    int getRightIndex() {return scannedRightIndex;}
};

#endif // Sample_H
