#include "AsideLayer.h"

AsideLayer::AsideLayer() {
}

AsideLayer::~AsideLayer(){
}

bool AsideLayer::init() {
	if(Layer::init()) {
		return true;
	} else {
		return false;
	}
}