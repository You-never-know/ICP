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
  std::unordered_map<enum LenseType,std::unique_ptr<Lense>> lenses;
  std::unique_ptr<Sample> sample;


public:
    Microscopy();
    void LenseInsert(enum LenseType,Lense newLense);
    void SampleInsert(Sample sample);
};

#endif // MICROSCOPY_H
