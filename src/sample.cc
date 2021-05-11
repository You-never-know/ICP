#include "sample.h"
#include "lightbeam.h"
#include <string>
#include <iostream>
#include <fstream>

Sample::Sample() {
    samplePosition = -1;
    sampleRotation = 0;   
    dataWidth = 0;
    dataHeight = 0;
    samplesData.clear();
}


int Sample::getPosition() { return samplePosition; }

void Sample::setPosition(int position) { this->samplePosition = position; }

int Sample::getRotation() { return sampleRotation; }

void Sample::setRotation(int rotation) { this->sampleRotation = rotation; }

bool Sample::loadData(std::string filePath) {
    using namespace std;
    this->samplesData.clear();
    ifstream inputFile;
    inputFile.open(filePath, ios::in);
    if (!inputFile.is_open()) {
        return false;
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
        return false;
    }
    start = end + delimeter.length();
    end = line.find(delimeter);
    try {
        dataWidth = stoi(line.substr(start, end - start));
    } catch(const std::invalid_argument& ia) {
        return false;
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
            cout << subString << endl;
            try {
                data = stoi(subString);
                this->samplesData.push_back(data);
            } catch (const std::invalid_argument& ia) {
                this->samplesData.clear();
                return false;}
            start = end + delimeter.length();
            end = line.find(delimeter, start);
        }
        start = 0U;
    }
    return true;
}
