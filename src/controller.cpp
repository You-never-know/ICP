#include "controller.h"

Controller::Controller()
{
    Microscopy newMicro =  { }; // TODO: INIT OBJ

    micro = std::make_unique<Microscopy>(newMicro);
}

Controller::Controller(Microscopy newMicro)
{
    micro = std::make_unique<Microscopy>(newMicro);
}
