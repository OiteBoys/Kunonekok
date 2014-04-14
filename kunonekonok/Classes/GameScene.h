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
#include "GameLayer.h"
#include "OptionLayer.h"

using namespace cocos2d;

class GameScene : public Scene, public OptionDelegate{
public:
    GameScene();
    ~GameScene();
    bool virtual init();
    CREATE_FUNC(GameScene);
    
    void onWalk(Direction direction);
    void onStop();
    
private:
    MapLayer *mapLayer;
    GameLayer *gameLayer;
    OptionLayer *optionLayer;
};

