#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <memory>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QObject>
#include <QPoint>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <unistd.h>
#include <chrono>
#include <thread>
#include "microscopy.h"
#include "lense.h"
#include <thread>

#define START_POS 149
#define DEFAULT_SCALE 0.2

class Controller : public QObject {
    Q_OBJECT

            std::unique_ptr<Microscopy>
    micro;
    QQmlApplicationEngine *engine;
    ElectronBeam beam = ElectronBeam(START_POS, DEFAULT_SCALE, 0.005, 0, 0, 0, 0);
    int topYMicroscopyPosition = 150;
    int bottomYMicroscopyPosition = -145;
    bool continueAnimation = true;


public:

    void setAnimation(bool anim) { continueAnimation = anim ; }
    bool getAnimation() { return continueAnimation; }

    Q_INVOKABLE explicit Controller(QQmlApplicationEngine *engine);

    Q_INVOKABLE int
    modifyLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis,
                bool create);

    Q_INVOKABLE bool checkLense(int, enum LenseType);

    Q_INVOKABLE void prepAnimation();

    Q_INVOKABLE int getLensePosition(int lenseType);

    Q_INVOKABLE double getLenseVergency(int lenseType);

    Q_INVOKABLE double getLenseXAxisDeflection(int lenseType);

    Q_INVOKABLE double getLenseZAxisDeflection(int lenseType);

    int getTopPosition() { return topYMicroscopyPosition; };

    int getBottomPosition() { return bottomYMicroscopyPosition; };

    void setTopPosition(int newTopPosition) { topYMicroscopyPosition = newTopPosition; };

    void setBottomPosition(int newBottomPosition) { bottomYMicroscopyPosition = newBottomPosition; };

    LenseType getLenseType(int type);

    Q_INVOKABLE void deleteLense(int type);

    Q_INVOKABLE int changeSamplePosition(QString position);

    void changeSamplePosition(int position);

    void changeSampleRotation(int position);

    Q_INVOKABLE int changeSampleRotation(QString rotation);

    Q_INVOKABLE bool saveConfiguration(QString fileName);

    Q_INVOKABLE bool loadConfiguration(QString fileName);

    Q_INVOKABLE void catchBeam(QObject* beam);

    void createLoadedObject(std::string decider, std::vector <std::string> parameters);

    Q_INVOKABLE void startAnimation();

    Q_INVOKABLE void clearAnimation();

    Q_INVOKABLE void restartAnimation();
    

};

#endif // CONTROLLER_H
