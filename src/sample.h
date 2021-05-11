#ifndef SAMPLE_H
#define SAMPLE_H

#include <QtGlobal>
#include <vector>

#include "lightbeam.h"

class Sample {
    std::vector <quint8> samplesData;
    int samplePosition;
    int sampleRotation;
    unsigned int dataHeight;
    unsigned int dataWidth;

public:
    Sample();

    void setPosition(int position);

    int getPosition();

    void setRotation(int rotation);

    int getDataHeight() {return dataHeight;};

    int getDataWidth() {return dataWidth;};

    bool loadData(std::string filePath);

    int getRotation();
};

#endif // Sample_H
