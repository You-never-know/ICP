/** @file microscopy.cc
*   @brief source code for class Microscopy
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#include "microscopy.h"
#include "lense.h"
#include "electronbeam.h"
#include "sample.h"
#include <tuple>
#include <QDebug>

Microscopy::Microscopy() {
    Sample newSample;
    sample = std::make_unique<Sample>(newSample);
    if (sample != nullptr) {
        sample->loadData("../data/sample1.in");
    }
}


void Microscopy::LenseInsert(enum LenseType type, Lense newLense) {
    if (!lenses.count(type)) { // insert only if lense doesn't exist

        lenses.insert(std::make_pair(type, std::move(std::make_unique<Lense>(newLense))));
    }
}


Sample *Microscopy::GetSample() {
    return sample.get();
}


void Microscopy::SampleInsert(Sample newSample) {
    if (!sample) { // only one sample can exist
        sample = std::make_unique<Sample>(newSample);
    }
}


Lense Microscopy::GetLense(enum LenseType key) {
    auto newPair = lenses.find(key);

    if (newPair != lenses.end()) {
        return *newPair->second;
    } else {
        Lense err;
        return err;
    }

}

enum LenseType Microscopy::GetNearestType(int pos) {
    Lense tmp;
    enum LenseType nearest = Error;
    int closestPos = 9999; // inits closest pos for first iteration

    for (auto it = lenses.begin(); it != lenses.end(); it++) {
        tmp = this->GetLense(it->first);
       
        if (abs(tmp.getPosition() - pos) <= closestPos) {

            nearest = tmp.getType();
            closestPos = abs( pos - tmp.getPosition());
        }

    }

    return nearest;
}

std::unordered_map<enum LenseType, std::unique_ptr < Lense>>*

Microscopy::GetAllLenses() {
    return &lenses;
}


void Microscopy::DeleteLense(enum LenseType key) {
    auto newPair = lenses.find(key);
    if (newPair != lenses.end()) {
        lenses.erase(key);
    }

}


bool Microscopy::checkPosition(int pos) {

    for (auto it = lenses.begin(); it != lenses.end(); it++) {
        Lense tmp = this->GetLense(it->first);
        if (tmp.getPosition() == pos) {
            return false;
        }
    }
    if (sample.get() != nullptr) {
        if (sample.get()->getPosition() == pos) {
            return false;
        }
    }
    return true;

}
