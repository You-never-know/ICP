/** @file controller.cpp
*   @brief source code for class Controller
*
*   @author Vladimir Drengubiak (xdreng01)
*   @author Daniel Marek (xmarek72)
*/
#include "electronbeam.h"


ElectronBeam::ElectronBeam(int pos, double newScale, double verg, double deflectionX, double deflectionZ,double ratioX,double ratioZ) {
    
    position = pos;
    scale = newScale;
    vergency = verg;
    deflectionXAxis = deflectionX;
    deflectionZAxis = deflectionZ;
    deflectionXRatio = ratioX;
    deflectionZRatio = ratioZ;
}

void ElectronBeam::deleteBeam(){
	
	for (QObject* obj : beamObj){
		if(obj != nullptr){
			delete obj;
			beamObj.pop_back();
		}
	}

}
	
