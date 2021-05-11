/** @file sample.cc
*   @brief source code for class Sample
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#include "sample.h"
#include "electronbeam.h"

Sample::Sample() {
    samplePosition = -1;
    sampleRotation = 0;
    flip = false;
}


int Sample::getPosition() { return samplePosition; }

void Sample::setPosition(int position) { this->samplePosition = position; }

int Sample::getRotation() { return sampleRotation; }

void Sample::setRotation(int rotation) { this->sampleRotation = rotation; }

void Sample::setFlip(bool flip) { this->flip = flip; }

bool Sample::getFlip() { return flip; }
