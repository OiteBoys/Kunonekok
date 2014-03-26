//
//  GameScene.h
//  kunonekonok
//
//  Created by damingdan on 14-3-26.
//
//

#pragma once
#include "cocos2d.h"
#include "MapLayer.h"

using namespace cocos2d;

class GameScene : public Scene {
public:
    GameScene();
    ~GameScene();
    bool virtual init();
    CREATE_FUNC(GameScene);
    
private:
    MapLayer *mapLayer;
};

