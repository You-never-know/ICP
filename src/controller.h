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


class Controller : public QObject {
    Q_OBJECT

            std::unique_ptr<Microscopy>
    micro;
    QQmlApplicationEngine *engine;
    int topYMicroscopyPosition = 150;
    int bottomYMicroscopyPosition = -145;
    const double default_scale = 0.2;
    bool continueAnimation = true;
    
    ElectronBeam beam = ElectronBeam(topYMicroscopyPosition, default_scale, 0.005, 0, 0, 0, 0);


public:
    
    /**
    * @brief Animation setter  
    * 
    * @param true to run and false to stop
    * 
    */
    void setAnimation(bool anim) { continueAnimation = anim ; }

    /**
    * @brief Animation getter  
    * 
    * @return state of animation
    * 
    */
    bool getAnimation() { return continueAnimation; }

    /**
    * @brief Constructor for initializing scene connected to qml 
    *
    * @param engine which loads and connects qml file
    * 
    */

    Q_INVOKABLE explicit Controller(QQmlApplicationEngine *engine);

    /**
    * @brief Func that modifies or creates lense  
    * 
    * @return lense position if it succeed otherwise -1
    * @param type of lens, position of lense, vergency of lense , deflection of X axis , deflection of Z and flag
    */
    Q_INVOKABLE int
    modifyLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis,
                bool create);

    /**
    * @brief Checks position and type of lense 
    * 
    * @return true if correct type and position is given otherwise false
    * @param Lense type and position
    */
    Q_INVOKABLE bool checkLense(int, enum LenseType);

    /**
    * @brief Called by qml to start animation
    * 
    */
    Q_INVOKABLE void prepAnimation();

    /**
    * @brief Getter for lense position
    * 
    * @return position if lense is found otherwise false
    * @param Lense type
    */
    Q_INVOKABLE int getLensePosition(int lenseType);
    /**
    * @brief Getter for lense vergency
    * 
    * @return lense vergency
    * @param Lense type
    */
    Q_INVOKABLE double getLenseVergency(int lenseType);
    /**
    * @brief Getter for XAxisDeflection
    * 
    * @return XAxisDeflection
    * @param Lense type
    */
    Q_INVOKABLE double getLenseXAxisDeflection(int lenseType);
    /**
    * @brief Getter for ZAxisDeflection
    * 
    * @return ZAxisDeflection
    * @param Lense type
    */
    Q_INVOKABLE double getLenseZAxisDeflection(int lenseType);

    /**
    * @brief Getter for top position of microscope
    * 
    * @return top of microscope
    * 
    */
    int getTopPosition() { return topYMicroscopyPosition; };

    /**
    * @brief Getter for bottom position of microscope
    * 
    * @return bottom position of microscope
    * 
    */
    int getBottomPosition() { return bottomYMicroscopyPosition; };
    /**
    * @brief Getter for top position opositionf microscope
    * 
    * @return top position of microscope
    * 
    */
    void setTopPosition(int newTopPosition) { topYMicroscopyPosition = newTopPosition; };
    /**
    * @brief Setter for bottom position of microscope
    * 
    * @param lense type
    * 
    */
    void setBottomPosition(int newBottomPosition) { bottomYMicroscopyPosition = newBottomPosition; };
    /**
    * @brief Setter for bottom position of microscope
    * 
    * @param lense type
    * @return 
    */
    LenseType getLenseType(int type);

    /**
    * @brief Delete lense by type
    * 
    * @param type of lense
    * 
    */
    Q_INVOKABLE void deleteLense(int type);

    /**
    * @brief Changes sample position if possible
    * 
    * @param position of sample from GUI
    * @return new position of sample
    */
    Q_INVOKABLE int changeSamplePosition(QString position);

    /**
    * @brief Changes sample position if possible
    *
    * @param position of sample
    */
    void changeSamplePosition(int position);

    /**
    * @brief Changes sample rotation
    *
    * @param rotation of sample
    */
    void changeSampleRotation(int position);

    /**
    * @brief Changes sample rotation
    *
    * @param rotation of sample from GUI
    * @return new rotation of sample
    */
    Q_INVOKABLE int changeSampleRotation(QString rotation);

    Q_INVOKABLE bool saveConfiguration(QString fileName);

    Q_INVOKABLE bool loadConfiguration(QString fileName);
    /**
    * @brief Catches beam objects from qml
    * 
    * @param pointer to qml object
    * 
    */
    Q_INVOKABLE void catchBeam(QObject* beam);

    void createLoadedObject(std::string decider, std::vector <std::string> parameters);
    /**
    * @brief Start Animation
    *
    */
    Q_INVOKABLE void startAnimation();
    /**
    * @brief Clears Animation
    *
    */
    Q_INVOKABLE void clearAnimation();
    /**
    * @brief Resets Animation
    *
    */
    Q_INVOKABLE void restartAnimation();

    void showResult();
    

};

#endif // CONTROLLER_H
