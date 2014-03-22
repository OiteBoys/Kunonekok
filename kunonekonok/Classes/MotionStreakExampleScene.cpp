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
        Size winSize = Director::getInstance()->getWinSize();
        this->terrain = Terrain::create();
        this->terrain->setContentSize(winSize);
        this->terrain->setPosition(winSize.width/2, winSize.height/2);
        this->terrain->genBackground();
        this->addChild(this->terrain);
        
        auto dispathcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(MotionStreakExampleLayer::onTouchesBegan, this);
        dispathcher->addEventListenerWithSceneGraphPriority(listener, this);
        return true;
    }else {
        return false;
    }
}

void MotionStreakExampleLayer::onTouchesBegan(const std::vector<Touch *> &touches, cocos2d::Event *event) {
    this->terrain->genBackground();
}