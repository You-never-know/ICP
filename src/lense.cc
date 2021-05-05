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
  position = 0;
  vergency = 0;
  deflectionXAxis = 0;
  deflectionZAxis = 0;

}

int Lense::GetPosition()
{
  return position;
}

enum LenseType Lense:: GetType()
{
  return type;
}
