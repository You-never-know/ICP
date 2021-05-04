#include "controller.h"

Controller::Controller()
{
   micro = std::make_unique<Microscopy>();
}

bool Controller::addLense(int type, QString position, QString vergency, QString deflectionXAxis, QString deflectionZAxis) {
    std::cout << "Hello" << std::endl;
    return true;
}
