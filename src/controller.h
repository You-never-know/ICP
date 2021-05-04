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
    Q_INVOKABLE Controller();
    Q_INVOKABLE Controller(Microscopy);
    Q_INVOKABLE bool addLense(int, QString, QString, QString, QString);
    //Q_INVOKABLE QString ahoj();
};

#endif // CONTROLLER_H
