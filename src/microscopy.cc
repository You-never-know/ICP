#include "microscopy.h"
#include "lense.h"
#include "lightbeam.h"
#include "sample.h"

Microscopy::Microscopy()
{

}

/*void Microscopy::LenseInsert(enum LenseType type,Lense newLense)
{
  if (!lenses.count(type)){ // insert only if lense doesn't exist

    std::pair <enum LenseType,std::unique_ptr<Lense>> NewItem ; // creats new pair
    lenses.insert(std::make_pair(type,std::move(std::make_unique<Lense>(newLense))));
  }
}
void Microscopy::SampleInsert(Sample newSample)
{
  if (!sample){ // only one sample can exist
    sample = std::make_unique<Sample>(newSample);
  }
}
*/
