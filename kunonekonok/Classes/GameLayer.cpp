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
    hero->update(dt);
}
