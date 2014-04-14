//
//  GameScene.cpp
//  kunonekonok
//
//  Created by damingdan on 14-3-26.
//
//

#include "GameScene.h"


GameScene::GameScene() {
}

GameScene::~GameScene() {
}

bool GameScene::init() {
    if (Scene::init()) {
        Size winSize = Director::getInstance()->getWinSize();
        mapLayer = MapLayer::create();
        if(mapLayer) {
            this->addChild(mapLayer);
        }
        
        gameLayer = GameLayer::create();
        if(gameLayer) {
            this->gameLayer->retain();
            this->addChild(gameLayer);
        }
        
        optionLayer = OptionLayer::create();
        if(optionLayer) {
            optionLayer->setDelegator(this);
            optionLayer->setRadius(40);
            optionLayer->setLocation(Point(winSize.width/5, winSize.height/5));
            this->addChild(optionLayer);
        }
        return true;
    } else {
        return false;
    }
}

void GameScene::onWalk(Direction direction) {
    this->gameLayer->onWalk(direction);
}

void GameScene::onStop() {
    this->gameLayer->onStop();
}