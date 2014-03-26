//
//  SampleScene.cpp
//  kunonekonok
//
//  Created by damingdan on 14-3-26.
//
//

#include "SampleScene.h"

SampleScene::SampleScene(){}

SampleScene::~SampleScene(){}

bool SampleScene::init() {
    if (Scene::init()) {
        background1 = Sprite::create("background.png");
        background1->getTexture()->setAntiAliasTexParameters();
        background1->setAnchorPoint(Point::ZERO);
        background1->setPosition(Point::ZERO);
        this->addChild(background1);
        
        background2 = Sprite::create("background.png");
        background2->getTexture()->setAntiAliasTexParameters();
        background2->setAnchorPoint(Point::ZERO);
        background2->setPosition(this->background1->getContentSize().width,0);
        this->addChild(background2);
        
        // scroll the background
        this->schedule(schedule_selector(SampleScene::scrollBackground), 0.01f);
        
        Size winSize = Director::getInstance()->getWinSize();
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("run.plist");
        auto hero = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("run001.png"));
        hero->setPosition(winSize.width*1/3, 150);
        this->addChild(hero);
        auto running = this->createAnimation("run%03d.png", 13, 15);
        hero->runAction(RepeatForever::create(Animate::create(running)));
        return true;
    }else {
        return false;
    }
}

void SampleScene::scrollBackground(float dt){
	this->background1->setPositionX(this->background1->getPositionX() - 4.0f);
	this->background2->setPositionX(this->background1->getPositionX() + this->background1->getContentSize().width - 4.0f);
	if(this->background2->getPositionX() == 0) {
		this->background1->setPositionX(0);
	}
}

Animation* SampleScene::createAnimation(const char *fmt, int count, float fps) {
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(1/fps);
	for (int i = 1; i <= count; i++){
		char name[50] = {0};
		sprintf(name, fmt, i);
		SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
		animation->addSpriteFrame(frame);
	}
	return animation;
}
