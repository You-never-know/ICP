#include "sample.h"
#include "lightbeam.h"

Sample::Sample()
{
    samplePosition = -1;
    sampleRotation = 0;
}


int Sample::getPosition() { return samplePosition; }
void Sample::setPosition(int position) { this->samplePosition = position; }

int Sample::getRotation() { return sampleRotation; }
void Sample::setRotation(int rotation) { this->sampleRotation = rotation; }
