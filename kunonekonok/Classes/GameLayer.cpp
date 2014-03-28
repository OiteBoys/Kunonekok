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
    hero->release();
}

bool GameLayer::init() {
    if(Layer::init()) {
        Size winSize = Director::getInstance()->getWinSize();
        auto hero = CharacterSprite::create("p1.png");
        hero->setScale(0.5f);
        hero->idle(DIRECTION_LEFT);
        hero->retain();
        hero->setPosition(winSize.width/2, winSize.height/2);
        this->addChild(hero);
        return true;
    }else {
        return false;
    }
}
