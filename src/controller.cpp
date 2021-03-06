/** @file controller.cpp
*   @brief source code for class Controller
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#include "controller.h"
#include "lense.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ios>


Controller::Controller(QQmlApplicationEngine *engine) {


    micro = std::make_unique<Microscopy>();
    this->engine = engine;

}


int
Controller::modifyLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis,
                        bool create) {
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
    if (!flag) {
        return -1;
    }
    if (create == true) {
        if (!checkLense(lensePosition, lenseType)) {
            return -1;
        }
    } else {
        if (!micro->checkPosition(lensePosition) && lensePosition != micro->GetLense(lenseType).getPosition()) {
            return -1;
        }
    }

    lenseVergency = vergency.toDouble(&flag);

    if (!flag){
        lenseVergency = 0.0;

    }
    lenseXAxisDeflection = deflectionXAxis.toDouble(&flag);
    if (!flag) {
        lenseXAxisDeflection = 0.0;
    }
    lenseZAxisDeflection = deflectionZAxis.toDouble(&flag);
    if (!flag) {
        lenseZAxisDeflection = 0.0;
    }

    // create or modify existing lense
    if (create == true) {
        Lense new_lense = Lense{lenseType, lensePosition, lenseVergency, lenseXAxisDeflection, lenseZAxisDeflection};
        micro->LenseInsert(lenseType, new_lense);
    } else {
        Lense selectedLense = micro->GetLense(lenseType);
        selectedLense.setPosition(lensePosition);
        selectedLense.setVergency(lenseVergency);
        selectedLense.setDeflectionXAxis(lenseXAxisDeflection);
        selectedLense.setDeflectionZAxis(lenseZAxisDeflection);
        micro->DeleteLense(lenseType);
        micro->LenseInsert(lenseType, selectedLense);
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


bool Controller::checkLense(int pos, enum LenseType type) {
    if (micro == nullptr) {
        return false;
    }
    enum LenseType Ltype = micro->GetLense(type).getType();

    if (type == Ltype)
        return false;
    // same types are forbidden

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
    Sample *sample = micro->GetSample();
    if (sample == nullptr) {
        return -1;
    }
    int currentSamplePosition = sample->getPosition();
    if (!flag or currentSamplePosition == newSamplePosition) {
        return currentSamplePosition;
    }
    if (!micro->checkPosition(newSamplePosition) or newSamplePosition <= getBottomPosition() or
        newSamplePosition >= getTopPosition()) {
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
    Sample *sample = micro->GetSample();
    if (sample == nullptr or !flag) {
        return 0;
    }
    sample->setRotation(sampleRotation);
    return sampleRotation;
}


void Controller::changeSamplePosition(int position) {
    if (micro == nullptr) {
        return;
    }
    if (position <= getBottomPosition() or position >= getTopPosition()) {
        return;
    }
    Sample *sample = micro->GetSample();
    if (!micro->checkPosition(position)) {
        return;
    }
    sample->setPosition(position);
}


void Controller::changeSampleRotation(int rotation) {
    if (micro == nullptr) {
        return;
    }
    Sample *sample = micro->GetSample();
    sample->setRotation(rotation);
}


bool Controller::saveConfiguration(QString fileName) {
    using namespace std;
    if (micro == nullptr) {
        return false;
    }
    QByteArray utfFileName = fileName.toUtf8();
    const char *finalFileName = utfFileName.data();
    ofstream outputFile;
    outputFile.open(finalFileName, ios::out);
    if (!outputFile.is_open()) {
        return false;
    }
    std::unordered_map<enum LenseType, std::unique_ptr < Lense>>
    *lenses = micro->GetAllLenses();
    if (lenses == nullptr) {
        return false;
    }
    Sample *sample = micro->GetSample();
    if (sample == nullptr) {
        return false;
    }
    outputFile << "S; " << sample->getPosition() << "; " << sample->getRotation() << ";" << endl;
    for (auto const&[key, value]: *lenses) {
        outputFile << "L; " << value->getPosition() << "; " << value->getVergency() << "; "
                   << value->getDeflectionXAxis() << "; " << value->getDeflectionZAxis() << ";" << endl;
    }
    return true;
}


void Controller::createLoadedObject(std::string decider, std::vector <std::string> parameters) {
    size_t sampleParameterCount = 1;
    size_t lenseParameterCount = 4;
    if (decider == "S") { // create sample
        if (parameters.size() != sampleParameterCount) {
            return;
        }
        int samplePosition;
        int sampleRotation;
        try {
            samplePosition = std::stoi(parameters.at(0));
            sampleRotation = std::stoi(parameters.at(1));
        } catch (const std::invalid_argument& ia) {
            return;
        } catch (const std::out_of_range& r) {
            return;
        }
        if (samplePosition <= getBottomPosition() or samplePosition >= getTopPosition()) {
            return;
        }
        changeSamplePosition(samplePosition);
        changeSampleRotation(sampleRotation);
        QMetaObject::invokeMethod(engine->rootObjects().first(), "showLoadedSample",
                                  Q_ARG(QVariant, samplePosition), Q_ARG(QVariant, sampleRotation));
    } else if (decider == "L") { // create lense
        if (parameters.size() != lenseParameterCount) {
            return;
        }
        int lensePosition;
        double lenseVergency;
        double lenseXDeflection;
        double lenseZDeflection;
        try {
            lensePosition = std::stoi(parameters.at(0));
            lenseVergency = std::stod(parameters.at(1));
            lenseXDeflection = std::stod(parameters.at(2));
            lenseZDeflection = std::stod(parameters.at(3));
            QString lenseType;
            QMetaObject::invokeMethod(engine->rootObjects().first(), "createLense", Q_RETURN_ARG(QString, lenseType),
                                      Q_ARG(QVariant, lensePosition), Q_ARG(QVariant, lenseVergency), Q_ARG(QVariant, lenseXDeflection), Q_ARG(QVariant, lenseZDeflection), Q_ARG(QVariant, false));
            bool flag;
            int intLenseType = lenseType.toInt(&flag);
            if (flag) {
                Lense newLense = Lense{getLenseType(intLenseType), lensePosition, lenseVergency, lenseXDeflection, lenseZDeflection};
                micro->LenseInsert(getLenseType(intLenseType), newLense);
            } else {
                return;
            }
        } catch (const std::invalid_argument& ia) {
            return;
        }
    }
}


bool Controller::loadConfiguration(QString fileName) {
    using namespace std;
    if (micro == nullptr) {
        return false;
    }
    QByteArray utfFileName = fileName.toUtf8();
    const char *finalFileName = utfFileName.data();
    ifstream inputFile;
    inputFile.open(finalFileName, ios::in);
    if (!inputFile.is_open()) {
        return false;
    }
    QMetaObject::invokeMethod(engine->rootObjects().first(), "clearMicroscopyToDefault");
    micro->deleteAllLenses();
    string line;
    string subString;
    string delimeter = ";";
    auto start = 0U;
    string decider;
    vector <string> parameters;
    while (!inputFile.eof()) {
        getline(inputFile, line);
        auto end = line.find(delimeter);
        if (end == string::npos) { continue; }
        decider = line.substr(start, end - start);
        start = end + delimeter.length();
        end = line.find(delimeter, start);
        while (end != string::npos) {
            subString = line.substr(start, end - start);
            parameters.push_back(subString);
            start = end + delimeter.length();
            end = line.find(delimeter, start);
        }
        createLoadedObject(decider, parameters);
        start = 0U;
        parameters.clear();
    }
    return true;
}

void Controller::startAnimation() {

    if(beam.getPosition() <= getBottomPosition()) {
        this->showResult();
        return;
    }
    if (!continueAnimation)
        return;

    if(beam.getPosition() == micro->GetSample()->getPosition()) // checks sample position
        micro->GetSample()->sampleScaned(beam.getScale(),beam.getDeflectionX(),beam.getDeflectionZ());

    if (micro->GetLense(micro->GetNearestType(beam.getPosition())).getPosition() == beam.getPosition()) { // checks lense pos if equal then apply lenses attributes
        if(beam.getScale()>=0)
            beam.setVergency(-1 *(micro->GetLense(micro->GetNearestType(beam.getPosition())).getVergency()) / 2000);
        else
            beam.setVergency(micro->GetLense(micro->GetNearestType(beam.getPosition())).getVergency() / 2000);

        beam.setDeflectionXRat(micro->GetLense(micro->GetNearestType(beam.getPosition())).getDeflectionXAxis() / 25);
        beam.setDeflectionZRat(micro->GetLense(micro->GetNearestType(beam.getPosition())).getDeflectionZAxis() / 25);

        if (beam.getScale() >= 0.7)
            beam.decScale(micro->GetLense(micro->GetNearestType(beam.getPosition())).getVergency() / 2000);
            
        
    }

   // qDebug() << micro->GetLense(micro->GetNearestType(beam.getPosition())).getVergency();
    QString returnedValue;
    QMetaObject::invokeMethod(engine->rootObjects().first(), "createBeam",
                              Q_RETURN_ARG(QString, returnedValue),
                              Q_ARG(QVariant, beam.getPosition()), Q_ARG(double, beam.getScale()),Q_ARG(double,beam.getDeflectionX()),Q_ARG(double, beam.getDeflectionZ()));
    beam.decPosition(); // beam moves no matter what


   if (beam.getScale() < 0){
        micro->GetSample()->setFlip(true);
    }

    if (beam.getScale() > 0){
        micro->GetSample()->setFlip(false);
    }

    if (abs(beam.getScale()) <= 0.7){ // controlls vergecny defx and defz

        beam.decScale(beam.getVergency());
        beam.insDeflectionX(beam.getDeflectionXRat());
        beam.insDeflectionZ(beam.getDeflectionZRat());  
    }

    if(abs(beam.getDeflectionX()) >= 18) // edge of x
        beam.refDeflectionXRat();

    if(abs(beam.getDeflectionZ()) >= 18) // edge of z
        beam.refDeflectionZRat();


}
void Controller::prepAnimation(){
    continueAnimation = true;
    startAnimation();

}

void Controller::clearAnimation() {

    this->beam.deleteBeam();
    continueAnimation = false; // stops animation
    beam = ElectronBeam(topYMicroscopyPosition, default_scale, 0.005, 0, 0, 0, 0); // init back to normal

}

void Controller::catchBeam(QObject *beam){
  this->beam.insertBeam(beam); // catches objects from qml
}

void Controller::restartAnimation(){
    this->beam.deleteBeam();
    beam = ElectronBeam(topYMicroscopyPosition, default_scale, 0.005, 0, 0, 0, 0);
}

void Controller::showResult() {
    Sample * sample = micro->GetSample();
    if (sample == nullptr) {return;}
   /* int realPixelWidth = sample->getRightIndex() - sample->getLeftIndex();
    int realPixelHeight = sample->getDownIndex() - sample->getUpIndex();
    double screenScaleX = 1.5;
    double screenScaleZ = 1.5;
    double pixelScaleX = screenScaleX/realPixelWidth;
    double pixelScaleY = screenScaleZ/realPixelHeight;
    int coll = 0;
    int row = 0;
    for (int i = -realPixelHeight/2; i < realPixelHeight/2; i++, row++) {
       for (int j = -realPixelWidth/2; j < realPixelWidth/2; j++, coll++) {
           if (sample->getSampleData(row,coll) == 1) {
            QMetaObject::invokeMethod(engine->rootObjects().first(), "createPixel",
                                      Q_ARG(QVariant, i*3), Q_ARG(QVariant, j*3),Q_ARG(double,pixelScaleX),Q_ARG(double, pixelScaleY), Q_ARG(QString, "black"));
           } else {
              QMetaObject::invokeMethod(engine->rootObjects().first(), "createPixel",
                                         Q_ARG(QVariant, i*3), Q_ARG(QVariant, j*3),Q_ARG(double,pixelScaleX),Q_ARG(double, pixelScaleY), Q_ARG(QString, "white"));
           }
       }
    }*/


}
