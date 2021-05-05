#ifndef LENSE_H
#define LENSE_H
#include "lightbeam.h"

enum LenseType  { Condenser , ObjectiveAperture , Intermediate , Projector, Error };

class Lense
{
    LenseType type;
    int position;
    double vergency;
    double deflectionXAxis;
    double deflectionZAxis;
public:
    Lense(LenseType type, int position, double vergency, double deflectionXAxis, double deflectionZAxis);
    Lense();
    int GetPosition();
    enum LenseType GetType();

};

#endif // LENSE_H
