#include "lense.h"
#include "lightbeam.h"
#include <QDebug>

Lense::Lense(LenseType type, int position, double vergency, double deflectionXAxis, double deflectionZAxis)
{
    this->type = type;
    this->position = position;
    this->vergency = vergency;
    this->deflectionXAxis = deflectionXAxis;
    this->deflectionZAxis = deflectionZAxis;
}

Lense::Lense(){
  type = Error;
  position = -999;
  vergency = -999;
  deflectionXAxis = -999;
  deflectionZAxis = -999;
}

int Lense::getPosition() { return position;}
void Lense::setPosition(int position) { this->position = position; }

double Lense::getVergency() { return vergency; }
void Lense::setVergency(double vergency) { this->vergency = vergency; }

double Lense::getDeflectionXAxis() { return deflectionXAxis; }
void Lense::setDeflectionXAxis(double deflection) { this->deflectionXAxis = deflection; }

double Lense::getDeflectionZAxis() { return deflectionZAxis; }
void Lense::setDeflectionZAxis(double deflection) { this->deflectionZAxis = deflection; }

enum LenseType Lense:: getType() { return type; }
