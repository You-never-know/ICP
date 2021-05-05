#ifndef LENSE_H
#define LENSE_H
#include "lightbeam.h"

enum LenseType  { Condenser , ObjectiveAperture , Intermediate , Projector };

class Lense
{
    LenseType type;
    int position;
    double vergency;
    double deflectionXAxis;
    double deflectionZAxis;
public:
    Lense(LenseType type, int position, double vergency, double deflectionXAxis, double deflectionZAxis);
};

#endif // LENSE_H
