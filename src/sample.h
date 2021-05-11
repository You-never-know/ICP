#ifndef SAMPLE_H
#define SAMPLE_H

#include <QtGlobal>
#include <vector>

#include "lightbeam.h"

class Sample {
    std::vector <quint8> samplesData;
    int samplePosition;
    int sampleRotation;
    bool flip;
public:
    Sample();

    void setPosition(int position);

    int getPosition();

    void setRotation(int rotation);

    int getRotation();

    void setFlip(bool flip);

    bool getFlip();


};

#endif // Sample_H
