//
//  SampleScene.h
//  kunonekonok
//
//  Created by damingdan on 14-3-26.
//
//

#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class SampleScene : public Scene {
public:
    SampleScene();
    ~SampleScene();
    bool virtual init();
    CREATE_FUNC(SampleScene);
    Animation* createAnimation(const char *fmt, int count, float fps);
    
private:
    Sprite* background1;
    Sprite* background2;
    void scrollBackground(float dt);
};

