/** @file sample.cc
*   @brief source code for class Sample
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#include "sample.h"
#include "electronbeam.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>


Sample::Sample() {
    samplePosition = -1;
    sampleRotation = 0;   
    flip = false;
    dataWidth = 0;
    dataHeight = 0;
    scannedDownIndex = 0;
    scannedLeftIndex = 0;
    scannedRightIndex = 0;
    scannedUpIndex = 0;
    samplesData.clear();
}


int Sample::getPosition() { return samplePosition; }

void Sample::setPosition(int position) { this->samplePosition = position; }

int Sample::getRotation() { return sampleRotation; }

void Sample::setRotation(int rotation) { this->sampleRotation = rotation; }

void Sample::loadData(std::string filePath) {
    using namespace std;
    this->samplesData.clear();
    ifstream inputFile;
    inputFile.open(filePath, ios::in);
    if (!inputFile.is_open()) {
        return;
    }
    string line;
    string subString;
    string delimeter = " ";
    auto start = 0U;
    unsigned dataHeight;
    unsigned dataWidth;
    // get the size of the data
    getline(inputFile, line);
    auto end = line.find(delimeter);
    try {
       dataHeight = stoi(line.substr(start, end - start));
    } catch(const std::invalid_argument& ia) {
        return;
    }
    start = end + delimeter.length();
    end = line.find(delimeter);
    try {
        dataWidth = stoi(line.substr(start, end - start));
    } catch(const std::invalid_argument& ia) {
        return;
    }
    this->dataHeight = dataHeight;
    this->dataWidth = dataWidth;
    start = 0U;
    unsigned int data;
    // load data
    while (!inputFile.eof()) {
        getline(inputFile, line);
        end = line.find(delimeter, start);
        if (end == string::npos) { continue; }
        while (end != string::npos) {
            subString = line.substr(start, end - start);
            try {
                data = stoi(subString);
                this->samplesData.push_back(data);
            } catch (const std::invalid_argument& ia) {
                this->samplesData.clear();
                return;}
            start = end + delimeter.length();
            end = line.find(delimeter, start);
        }
        start = 0U;
    }
}

void Sample::setFlip(bool flip) { this->flip = flip; }

bool Sample::getFlip() { return flip; }

void Sample::sampleScaned(double beamScale, double beamXDeflection, double beamZDeflection) {
    double sampleScale = 0.5;
    int moveLeft = 0;
    int moveRight = 0;
    int moveUp = 0;
    int moveDown = 0;
    if (beamXDeflection < 0) {
        moveLeft = abs(ceil(beamXDeflection));
    } else {
        moveRight = abs(ceil(beamXDeflection));
    }
    if (beamZDeflection < 0) {
        moveUp = abs(ceil(beamZDeflection));
    } else {
        moveDown = abs(ceil(beamZDeflection));
    }
    if (beamScale != sampleScale) {
        double beam2SampleRatio = beamScale / sampleScale;
        int potentialHeight = floor(beam2SampleRatio*this->getDataHeight());
        int potentialWidth = floor(beam2SampleRatio*this->getDataWidth());

    } else {
        this->scannedLeftIndex = 0 + moveRight;
        this->scannedRightIndex = this->getDataWidth() - 1 - moveLeft;
        this->scannedUpIndex = 0 + moveDown;
        this->scannedDownIndex = this->getDataHeight() - 1 - moveUp;
    }

    // final check
    if (this->scannedLeftIndex < 0) {
        this->scannedLeftIndex = 0;
    }
    if (this->scannedUpIndex < 0) {
        this->scannedUpIndex = 0;
    }
    if (this->scannedRightIndex >= this->getDataWidth()) {
        this->scannedRightIndex = this->getDataWidth() -1;
    }
    if (this->scannedDownIndex >= this->getDataHeight()) {
        this->scannedRightIndex = this->getDataHeight() -1;
    }
}
