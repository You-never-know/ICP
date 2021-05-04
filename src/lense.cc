#include "lense.h"
#include "lightbeam.h"

Lense::Lense(LenseType type, int position, double vergency, double deflectionXAxis, double deflectionZAxis)
{
    this->type = type;
    this->position = position;
    this->vergency = vergency;
    this->deflectionXAxis = deflectionXAxis;
    this->deflectionZAxis = deflectionZAxis;
}
