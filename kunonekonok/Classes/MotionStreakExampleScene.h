//
//  MotionStreakExampleScene.h
//  kunonekonok
//
//  Created by damingdan on 14-3-21.
//
//

#pragma once
#include "cocos2d.h"
#include "Utils.h"
#include "Terrain.h"
using namespace cocos2d;

class MotionStreakExampleLayer;

class MotionStreakExampleScene:public Scene {
public:
    MotionStreakExampleScene();
    ~MotionStreakExampleScene();
    bool virtual init();
    CREATE_FUNC(MotionStreakExampleScene);
    
private:
    MotionStreakExampleLayer* motionStreakExampleLayer;
};


class MotionStreakExampleLayer:public Layer {
public:
    MotionStreakExampleLayer();
    ~MotionStreakExampleLayer();
    bool virtual init();
    CREATE_FUNC(MotionStreakExampleLayer);
    
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *event);
    
    Sprite* stripedSpriteWithColor(Color4F foregroundColor, Color4F backgroundColor, float width, float height, int stripCount);
    CC_SYNTHESIZE_RETAIN(Sprite*, background, Background);
    
private:
    Terrain *terrain;
};
