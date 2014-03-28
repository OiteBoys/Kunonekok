//
//  OptionLayer.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-18.
//
//

#include "OptionLayer.h"



OptionLayer::OptionLayer()
{}

OptionLayer::~OptionLayer()
{}

bool OptionLayer::init()
{
	if(Layer::init()){
		this->initJoystick();
		auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(OptionLayer::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(OptionLayer::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(OptionLayer::onTouchesEnded, this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

		return true;
	}else {
		return false;
	}
}

void OptionLayer::initJoystick()
{
	this->joystick = Sprite::create("pad.png");
    Size winSize = Director::getInstance()->getWinSize();
    this->joystick->setPosition(winSize.width/4, winSize.height/5);
	this->addChild(this->joystick);
	this->inactiveJoystick();
}

void OptionLayer::activeJoystick(Point position)
{
}

void OptionLayer::inactiveJoystick()
{
	this->joystick->setVisible(false);
}

void OptionLayer::updateJoystick(Point direction, float distance)
{

}

void OptionLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
	Size winSize = Director::getInstance()->getWinSize();
	for (auto touch : touches){
		Point position = touch->getLocation();
        
        if (position.x <= winSize.width / 2) {
			// left
			this->activeJoystick(position);
        } else {
            // right
        }
	}
}

void OptionLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
	Size winSize = Director::getInstance()->getWinSize();
    Touch *t = touches[0];
    Point start = t->getStartLocation();
    if (start.x > winSize.width / 2) {
        return;
    }

    Point p = t->getLocation();
    float distance = start.getDistance(p);
    Point direction = (p - start).normalize();
	this->updateJoystick(direction, distance);

}

void OptionLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
	this->inactiveJoystick();
	this->delegator->onStop();
}

