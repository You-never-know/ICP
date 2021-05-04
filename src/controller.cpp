#include "controller.h"

Controller::Controller()
{
    //Microscopy newMicro =  { }; // TODO: INIT OBJ

   // micro = std::make_unique<Microscopy>(newMicro);
}

Controller::Controller(Microscopy newMicro)
{
   // micro = std::make_unique<Microscopy>(newMicro);
}

bool Controller::addLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis) {
    std::cout << "Hello" << std::endl;
    return true;
}
