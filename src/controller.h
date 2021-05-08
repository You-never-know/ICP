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

class Controller : public QObject
{
     Q_OBJECT

     std::unique_ptr<Microscopy> micro;
     QQmlApplicationEngine * engine;
     ElectronBeam beam = ElectronBeam(START_POS,0.2);

public:
    Q_INVOKABLE explicit Controller(QQmlApplicationEngine * engine);
    Q_INVOKABLE int modifyLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis, bool create);
    Q_INVOKABLE bool checkLense(int,enum LenseType);
    Q_INVOKABLE int getLensePosition(int lenseType);
    Q_INVOKABLE double getLenseVergency(int lenseType);
    Q_INVOKABLE double getLenseXAxisDeflection(int lenseType);
    Q_INVOKABLE double getLenseZAxisDeflection(int lenseType);
    LenseType getLenseType(int type);
    Q_INVOKABLE void deleteLense(int type);
    Q_INVOKABLE int changeSamplePosition(QString position);
    Q_INVOKABLE int changeSampleRotation(QString rotation);
    Q_INVOKABLE void saveConfiguration(QString fileName);
    Q_INVOKABLE void loadConfiguration(QString fileName);

    Q_INVOKABLE void startAnimation();
    Q_INVOKABLE void endAnimation();
    Q_INVOKABLE void restartAnimation();

};

#endif // CONTROLLER_H
