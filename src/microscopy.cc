#include "microscopy.h"
#include "lense.h"
#include "lightbeam.h"
#include "sample.h"
#include <tuple>
#include <QDebug>

Microscopy::Microscopy()
{
  Sample newSample;
  sample = std::make_unique<Sample>(newSample);
}

void Microscopy::LenseInsert(enum LenseType type,Lense newLense)
{
  if (!lenses.count(type)){ // insert only if lense doesn't exist

    //std::pair <enum LenseType,std::unique_ptr<Lense>> NewItem ; // creats new pair
    lenses.insert(std::make_pair(type,std::move(std::make_unique<Lense>(newLense))));
  }
}
void Microscopy::SampleInsert(Sample newSample)
{
  if (!sample){ // only one sample can exist
    sample = std::make_unique<Sample>(newSample);
  }
}
Lense Microscopy::GetLense(enum LenseType key)
{
  auto newPair = lenses.find(key);

  if(newPair != lenses.end()){
    return *newPair->second;
  }
  else{
    Lense err;
    return err;
  }

}
bool Microscopy::checkPosition(int pos){

  for(auto it = lenses.begin() ; it != lenses.end() ; it++ ){
    //  qDebug() << "hell";
      Lense tmp = this->GetLense(it->first);
      if (tmp.getPosition() == pos){
      //  qDebug() << "false";
        return false;
      }


  }
  return true ;

}
