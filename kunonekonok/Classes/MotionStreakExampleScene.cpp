//
//  MotionStreakExampleScene.cpp
//  kunonekonok
//
//  Created by damingdan on 14-3-21.
//
//

#include "MotionStreakExampleScene.h"


MotionStreakExampleScene::MotionStreakExampleScene(){}

MotionStreakExampleScene::~MotionStreakExampleScene(){}

bool MotionStreakExampleScene::init() {
    if(Scene::init()) {
        motionStreakExampleLayer = MotionStreakExampleLayer::create();
        this->addChild(motionStreakExampleLayer);
        
        
        return true;
    }else {
        return false;
    }
}

MotionStreakExampleLayer::MotionStreakExampleLayer(){}

MotionStreakExampleLayer::~MotionStreakExampleLayer(){}

bool MotionStreakExampleLayer::init() {
    if(Layer::init()) {
        return true;
    }else {
        return false;
    }
}