//
//  GameLayer.h
//  kunonekonok
//
//  Created by damingdan on 14-3-28.
//
//

#pragma once
#include "cocos2d.h"
#include "CharacterSprite.h"

using namespace cocos2d;

class GameLayer:public Layer {
public:
    GameLayer();
    ~GameLayer();
    bool virtual init();
    CREATE_FUNC(GameLayer);
    void update(float dt);
    void onWalk(Direction direction);
    void onStop();
    
private:
    CharacterSprite* hero;
};