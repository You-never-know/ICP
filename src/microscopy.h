#ifndef MICROSCOPY_H
#define MICROSCOPY_H
#include <unordered_map>
#include <iostream>
#include <memory>
#include <string>

#include "lense.h"
#include "lightbeam.h"
#include "sample.h"

class Microscopy
{
  std::unordered_map<std::string,std::unique_ptr<Lense>> lenses;
public:
    Microscopy();
};

#endif // MICROSCOPY_H
