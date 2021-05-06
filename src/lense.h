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
    int getPosition();
    void setPosition(int position);
    double getVergency();
    void setVergency(double vergency);
    double getDeflectionXAxis();
    void setDeflectionXAxis(double deflection);
    double getDeflectionZAxis();
    void setDeflectionZAxis(double deflection);
    enum LenseType getType();

};

#endif // LENSE_H
