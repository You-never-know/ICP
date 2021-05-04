#include "microscopy.h"
#include "lense.h"
#include "lightbeam.h"
#include "sample.h"

Microscopy::Microscopy()
{

}
void Microscopy::LenseInsert(enum LenseType type,Lense newLense)
{
  std::pair <enum LenseType,std::unique_ptr<Lense>> NewItem ; // creats new iteam in map
  lenses.insert(std::make_pair(type,std::move(std::make_unique<Lense>(newLense))));
}
