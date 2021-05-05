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
    Q_INVOKABLE int addLense(int, QString, QString, QString, QString);
    Q_INVOKABLE bool checkLense(int,enum LenseType);
};

#endif // CONTROLLER_H
