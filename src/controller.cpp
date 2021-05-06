#include "controller.h"
#include "lense.h"
#include <QDebug>

Controller::Controller()
{
   micro = std::make_unique<Microscopy>();

}


int Controller::modifyLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis, bool create) {
    bool flag;
    int lensePosition;
    double lenseVergency;
    double lenseXAxisDeflection;
    double lenseZAxisDeflection;
    LenseType lenseType = getLenseType(type);
    if (lenseType == Error) {
        return -1;
    }

    lensePosition = position.toInt(&flag);
    // indicate error while conversion
    if (flag == false) {
        return -1;
    }
    if (create == true) {
        if (!checkLense(lensePosition,lenseType)){
          return -1;
        }
    }

    lenseVergency = vergency.toDouble(&flag);
    if (flag == false) {
        lenseVergency = 0;
    }
    lenseXAxisDeflection = deflectionXAxis.toDouble(&flag);
    if (flag == false) {
        lenseXAxisDeflection = 0;
    }
    lenseZAxisDeflection = deflectionZAxis.toDouble(&flag);
    if (flag == false) {
        lenseZAxisDeflection = 0;
    }

    // create or modify existing lense
    if (create == true) {
        Lense new_lense = Lense{lenseType, lensePosition, lenseVergency, lenseXAxisDeflection, lenseZAxisDeflection};
        micro->LenseInsert(lenseType ,new_lense);
    } else {
        Lense selectedLense = micro->GetLense(lenseType);
        selectedLense.setPosition(lensePosition);
        selectedLense.setVergency(lenseVergency);
        selectedLense.setDeflectionXAxis(lenseXAxisDeflection);
        selectedLense.setDeflectionZAxis(lenseZAxisDeflection);
    }
    return lensePosition;
}


bool Controller::checkLense(int pos,enum LenseType type )
{
    if(type == (micro->GetLense(type).getType())){
      return false ;
    } // same types are forbidden

    return micro->checkPosition(pos);
}


LenseType Controller::getLenseType(int type) {
    switch (type) {
        case 0:
            return Condenser;
        case 1:
            return ObjectiveAperture;
        case 2:
            return Intermediate;
        case 3:
            return Projector;
        default:
            return Error;
    }
}



int Controller::getLensePosition(int lenseType) {
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getPosition();
}


double Controller::getLenseVergency(int lenseType) {
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getVergency();
}


double Controller::getLenseXAxisDeflection(int lenseType) {
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getDeflectionXAxis();
}


double Controller::getLenseZAxisDeflection(int lenseType) {
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getDeflectionZAxis();
}
