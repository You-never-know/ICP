#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <iostream>
#include <memory>

#include <QObject>
#include <QPoint>
#include <QDebug>

#include "microscopy.h"
#include "lense.h"

class Controller : public QObject
{
     Q_OBJECT
     std::unique_ptr<Microscopy> micro;

public:
    Q_INVOKABLE explicit Controller();
    Q_INVOKABLE int modifyLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis, bool create);
    Q_INVOKABLE bool checkLense(int,enum LenseType);
    Q_INVOKABLE int getLensePosition(int lenseType);
    Q_INVOKABLE double getLenseVergency(int lenseType);
    Q_INVOKABLE double getLenseXAxisDeflection(int lenseType);
    Q_INVOKABLE double getLenseZAxisDeflection(int lenseType);
    LenseType getLenseType(int type);
    Q_INVOKABLE void deleteLense(int type);
};

#endif // CONTROLLER_H
