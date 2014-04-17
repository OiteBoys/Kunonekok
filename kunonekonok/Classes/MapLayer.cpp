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
        
        meta = map->getLayer("meta");
        meta->setVisible(false);
        return true;
    }else {
        return false;
    }
}

TMXTiledMap* MapLayer::getTileMap() {
    return this->map;
}

TMXLayer* MapLayer::getMetaLayer() {
    return this->meta;
}

Point MapLayer::tileCoordForPosition(cocos2d::Point position) {
    auto mapStartPosition = this->map->getPosition() - Point(this->map->getContentSize().width/2, this->map->getContentSize().height/2);
    position = position - mapStartPosition;
    int x = position.x / this->map->getTileSize().width;
    int y = (this->map->getTileSize().height * this->map->getMapSize().height - position.y)/this->map->getTileSize().height;
    return Point(x, y);
}