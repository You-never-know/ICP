#ifndef MICROSCOPY_H
#define MICROSCOPY_H

#include <unordered_map>
#include <iostream>
#include <memory>
#include <string>
#include "lense.h"
#include "lightbeam.h"
#include "sample.h"

class Microscopy {
    std::unordered_map<enum LenseType, std::unique_ptr < Lense>> lenses;
    std::unique_ptr <Sample> sample;


public:
    Microscopy();
    /**
    * Inserts  lense into microscope
    * 
    * @param lense type and lenses
    * 
    */
    void LenseInsert(enum LenseType, Lense newLense);
    /**
    * Inserts sample into microscope
    * 
    * @param Sample
    * 
    */
    void SampleInsert(Sample sample);

    bool checkPosition(int pos);

    Lense GetLense(enum LenseType key);

    std::unordered_map<enum LenseType, std::unique_ptr < Lense>>* GetAllLenses();

    void deleteAllLenses() { lenses.clear();}

    Sample *GetSample();

    /**
    * Deletes lense by type
    * 
    * @param Sample
    * 
    */
    void DeleteLense(enum LenseType key);

    /**
    * get nearest type of lense given by position
    * 
    * @param postion
    * @return type
    */
    enum LenseType GetNearestType(int);
};

#endif // MICROSCOPY_H
