#include "lense.h"
#include <QDebug>
#define ERR_VAL -999

Lense::Lense(LenseType type, int position, double vergency, double deflectionXAxis, double deflectionZAxis) {
    this->type = type;
    this->position = position;
    this->vergency = vergency;
    this->deflectionXAxis = deflectionXAxis;
    this->deflectionZAxis = deflectionZAxis;
}

Lense::Lense() {
    type = Error;
    position = ERR_VAL;
    vergency = ERR_VAL;
    deflectionXAxis = ERR_VAL;
    deflectionZAxis = ERR_VAL;
}

int Lense::getPosition() { return position; }

void Lense::setPosition(int position) { this->position = position; }

double Lense::getVergency() { return vergency; }

void Lense::setVergency(double vergency) { this->vergency = vergency; }

double Lense::getDeflectionXAxis() { return deflectionXAxis; }

void Lense::setDeflectionXAxis(double deflection) { this->deflectionXAxis = deflection; }

double Lense::getDeflectionZAxis() { return deflectionZAxis; }

void Lense::setDeflectionZAxis(double deflection) { this->deflectionZAxis = deflection; }

enum LenseType Lense::getType() { return type; }
