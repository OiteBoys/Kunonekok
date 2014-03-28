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
        mapLayer = MapLayer::create();
        if(mapLayer) {
            this->addChild(mapLayer);
        }
        
        gameLayer = GameLayer::create();
        if(gameLayer) {
            this->addChild(gameLayer);
        }
        return true;
    } else {
        return false;
    }
}

void GameScene::onWalk(Direction direction) {
}

void GameScene::onStop() {
}