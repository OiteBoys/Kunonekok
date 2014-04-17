//
//  GameLayer.cpp
//  kunonekonok
//
//  Created by damingdan on 14-3-28.
//
//

#include "GameLayer.h"

GameLayer::GameLayer() {
}

GameLayer::~GameLayer() {
}

bool GameLayer::init() {
    if(Layer::init()) {
        Size winSize = Director::getInstance()->getWinSize();
        hero = CharacterSprite::getInstance();
        hero->setFile("p1.png");
        hero->setScale(0.5f);
        hero->idle(DIRECTION_LEFT);
        hero->setPosition(winSize.width/2, winSize.height/2);
        this->addChild(hero);
        
        this->scheduleUpdate();
        return true;
    }else {
        return false;
    }
}

void GameLayer::onWalk(Direction direction) {
    hero->walk(direction);
}

void GameLayer::onStop() {
    hero->idle();
}

void GameLayer::update(float dt) {
    if(hero->getCurrentStatus() == ACTION_STATE_WALK) {
        const float speed = 1;
        auto shiftVect = Point(0, 0);
        if(hero->getCurrentDirection() == Direction::DIRECTION_UP) {
            shiftVect = Point(0, speed);
        }else if(hero->getCurrentDirection() == Direction::DIRECTION_DOWN) {
            shiftVect = Point(0, -speed);
        }else if(hero->getCurrentDirection() == Direction::DIRECTION_LEFT) {
            shiftVect = Point(-speed, 0);
        }else if(hero->getCurrentDirection()== Direction::DIRECTION_RIGHT) {
            shiftVect = Point(speed, 0);
        }
        auto currentPosition = hero->getPosition();
        
        // check this position can access
        auto nextPosition = currentPosition + shiftVect;
        auto map = this->getTileMapLayer()->getTileMap();
        if(!map->getBoundingBox().containsPoint(nextPosition)) {
            return;
        }
        
        Point tiledCoord = this->getTileMapLayer()->tileCoordForPosition(nextPosition);
        auto metaLayer = this->getTileMapLayer()->getMetaLayer();
        int tileGID = metaLayer->getTileGIDAt(tiledCoord);
        if(tileGID) {
            auto properties = this->getTileMapLayer()->getTileMap()->getPropertiesForGID(tileGID).asValueMap();
            if(!properties.empty()) {
                auto collision = properties["collidable"].asString();
                if ("true" == collision) {
                    return;
                }
            }
        }
        hero->setPosition(nextPosition);
    }
}

CharacterSprite* GameLayer::getHero(){
    return this->hero;
}



