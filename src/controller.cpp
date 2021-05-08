#include "controller.h"
#include "lense.h"

Controller::Controller(QQmlApplicationEngine * engine)
{


   micro = std::make_unique<Microscopy>();
   this->engine = engine;


}


int Controller::modifyLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis, bool create) {
    if (micro == nullptr) {
        return -1;
    }
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
    } else {
        if (!micro->checkPosition(lensePosition)) {
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
        micro->DeleteLense(lenseType);
        micro->LenseInsert(lenseType,selectedLense);
    }
    return lensePosition;
}


void Controller::deleteLense(int type) {
    if (micro == nullptr) {
        return;
    }
    LenseType lenseType = getLenseType(type);
    micro->DeleteLense(lenseType);
}



bool Controller::checkLense(int pos,enum LenseType type )
{
    if (micro == nullptr) {
        return -1;
    }
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
    if (micro == nullptr) {
        return -1;
    }
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getPosition();
}


double Controller::getLenseVergency(int lenseType) {
    if (micro == nullptr) {
        return 0.0;
    }
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getVergency();
}


double Controller::getLenseXAxisDeflection(int lenseType) {
    if (micro == nullptr) {
        return 0.0;
    }
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getDeflectionXAxis();
}


double Controller::getLenseZAxisDeflection(int lenseType) {
    if (micro == nullptr) {
        return 0.0;
    }
    LenseType type = getLenseType(lenseType);
    return micro->GetLense(type).getDeflectionZAxis();
}

int Controller::changeSamplePosition(QString position) {
    if (micro == nullptr) {
        return -1;
    }
    bool flag;
    int newSamplePosition = position.toInt(&flag);
    Sample * sample = micro->GetSample();
    if (sample == nullptr) {
        return -1;
    }
    int currectSamplePosition = sample->getPosition();
    if (flag == false || currectSamplePosition == newSamplePosition) {
        return currectSamplePosition;
    }
    if (!micro->checkPosition(newSamplePosition)) {
        return -1;
    }
    sample->setPosition(newSamplePosition);
    return newSamplePosition;
}

int Controller::changeSampleRotation(QString rotation) {
    if (micro == nullptr) {
        return -1;
    }
    bool flag;
    int sampleRotation = rotation.toInt(&flag);
    Sample * sample = micro->GetSample();
    if (sample == nullptr || flag == false) {
        return 0;
    }
    sample->setRotation(sampleRotation);
    return sampleRotation;
}


void Controller::saveConfiguration(QString fileName) {
    ;
}

void Controller::loadConfiguration(QString fileName) {
    ;
}

void Controller::startAnimation() {

  if (beam.getPosition()<= -START_POS)
      return;

  QString returnedValue;
  QMetaObject::invokeMethod(engine->rootObjects().first(), "createBeam",
  Q_RETURN_ARG(QString, returnedValue),
  Q_ARG(QVariant,beam.getPosition()),Q_ARG(QVariant,beam.getXscale()));
  beam.decPosition();
  qDebug() << beam.getPosition();
  beam.decXscale();


}

void Controller::restartAnimation() {
    ;
}

void Controller::clearAnimation() {
    ;
}
