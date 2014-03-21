//
//  MotionStreakExampleScene.h
//  kunonekonok
//
//  Created by damingdan on 14-3-21.
//
//

#pragma once
#include "cocos2d.h"
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
};
