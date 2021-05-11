#include "lightbeam.h"


ElectronBeam::ElectronBeam(int pos, double newScale, double verg, double deflectionX, double deflectionZ,double ratioX,double ratioZ) {
    
    position = std::make_unique<int>(pos);
    scale = std::make_unique<double>(newScale);
    vergency = std::make_unique<double>(verg);
    deflectionXAxis = std::make_unique<double>(deflectionX);
    deflectionZAxis = std::make_unique<double>(deflectionZ);
    deflectionXRatio = std::make_unique<double>(ratioX);
    deflectionZRatio = std::make_unique<double>(ratioZ);
}

void ElectronBeam::deleteBeam(){
	
	for (QObject* obj : beamObj){
		if(obj != nullptr){
			delete obj;
			beamObj.pop_back();
		}
	}

}
	