//
//  MapLayer.cpp
//  kunonekonok
//
//  Created by damingdan on 14-3-26.
//
//

#include "MapLayer.h"


MapLayer::MapLayer() {
}

MapLayer::~MapLayer() {
}

bool MapLayer::init() {
    if(Layer::init()) {
        map = TMXTiledMap::create("map02.tmx");
        this->addChild(map);
        return true;
    }else {
        return false;
    }
}