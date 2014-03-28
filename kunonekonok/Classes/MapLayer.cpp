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
        Size winSize = Director::getInstance()->getWinSize();
        map = TMXTiledMap::create("map02.tmx");
        map->setAnchorPoint(Point(0.5, 0.5));
        map->setPosition(winSize.width/2, winSize.height/2);
        this->addChild(map);
        return true;
    }else {
        return false;
    }
}