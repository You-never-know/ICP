/** @file microscopy.h
*   @brief header file for class Mircoscopy
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/

#ifndef MICROSCOPY_H
#define MICROSCOPY_H

#include <unordered_map>
#include <iostream>
#include <memory>
#include <string>
#include "lense.h"
#include "electronbeam.h"
#include "sample.h"

class Microscopy {
    std::unordered_map<enum LenseType, std::unique_ptr < Lense>> lenses;
    std::unique_ptr <Sample> sample;


public:
    Microscopy();
    /**
    * @brief Inserts lense into microscope
    * 
    * @param lense type and lenses
    * 
    */
    void LenseInsert(enum LenseType, Lense newLense);
    /**
    * @brief Inserts sample into microscope
    * 
    * @param Sample
    * 
    */
    void SampleInsert(Sample sample);
    /**
    * @brief Checks position of lense
    * 
    * @return if it succeeds true otherwise false
    * @param postion of sample
    * 
    */
    bool checkPosition(int pos);
    /**
    * @brief Gets Lense specified by type
    * 
    * @return Lense with reqired type
    * @param type of lense
    * 
    */
    Lense GetLense(enum LenseType key);
    /**
    * @brief Gets container of lenses 
    * 
    * @return pointer to container with lenses
    * 
    * 
    */
    std::unordered_map<enum LenseType, std::unique_ptr < Lense>>* GetAllLenses();
    /**
    * @brief Clears container
    * 
    * 
    */
    void deleteAllLenses() { lenses.clear();}
    /**
    * @brief Returns Sample
    * 
    * 
    */
    Sample *GetSample();

    /**
    * @brief Deletes lense by type
    * 
    * @param Sample
    * 
    */
    void DeleteLense(enum LenseType key);

    /**
    * @brief get nearest type of lense given by position
    * 
    * @param postion
    * @return type
    */
    enum LenseType GetNearestType(int);
};

#endif // MICROSCOPY_H
