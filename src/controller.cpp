#include "controller.h"
#include "lense.h"

Controller::Controller()
{
   micro = std::make_unique<Microscopy>();
}


int Controller::addLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis) {
    bool flag;
    int lensePosition;
    double lenseVergency;
    double lenseXAxisDeflection;
    double lenseZAxisDeflection;
    LenseType lenseType;
    lensePosition = position.toInt(&flag);
    // indicate error while conversion
    if (flag == false) {
        return -1;
    }
    lenseVergency = vergency.toDouble(&flag);
    if (flag == false) {
        return -1;
    }
    lenseXAxisDeflection = deflectionXAxis.toDouble(&flag);
    if (flag == false) {
        return -1;
    }
    lenseZAxisDeflection = deflectionZAxis.toDouble(&flag);
    if (flag == false) {
        return -1;
    }
    switch (type) {
        case 0:
            lenseType = Condenser;
            break;
        case 1:
            lenseType = ObjectiveAperture;
            break;
        case 2:
            lenseType = Intermediate;
            break;
        case 3:
            lenseType = Projector;
            break;
        default:
            return -1;
    }

    Lense new_lense = Lense{lenseType, lensePosition, lenseVergency, lenseXAxisDeflection, lenseZAxisDeflection};
    micro->LenseInsert(lenseType ,new_lense);
    return lensePosition;
}
