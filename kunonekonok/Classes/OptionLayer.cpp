//
//  OptionLayer.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-18.
//
//

#include "OptionLayer.h"
#include <math.h>



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
    this->joystick->setScale(0.5);
    Size winSize = Director::getInstance()->getWinSize();
    this->joystick->setPosition(winSize.width/4, winSize.height/5);
	this->addChild(this->joystick);
	this->inactiveJoystick();
}

void OptionLayer::activeJoystick(Point position)
{
    //this->joystick->setVisible(true);
}

void OptionLayer::inactiveJoystick()
{
	//this->joystick->setVisible(false);
}

void OptionLayer::updateJoystick(Point direction, float distance)
{

}

void OptionLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
	Size winSize = Director::getInstance()->getWinSize();
	for (auto touch : touches){
		Point position = touch->getLocation();
        this->activeJoystick(this->getLocation());
        auto distance = position.getDistance(this->getLocation());
        auto deltaAngle = this->getLocation() - position;
        auto angle = CC_RADIANS_TO_DEGREES(deltaAngle.getAngle());
        if (distance <= this->getRadius()) {
			if ((angle > -180 && angle < -135) || (angle > 135 && angle <= 180)) {
                this->delegator->onWalk(Direction::DIRECTION_RIGHT);
            }else if(angle >= -135 && angle <= -45) {
                this->delegator->onWalk(Direction::DIRECTION_UP);
            }else if(angle > -45 && angle <= 45) {
                this->delegator->onWalk(Direction::DIRECTION_LEFT);
            }else if(angle > 45 && angle <= 135) {
                this->delegator->onWalk(Direction::DIRECTION_DOWN);
            }
			
        } else {
            // right
        }
	}
}

void OptionLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{

}

void OptionLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
	this->inactiveJoystick();
	this->delegator->onStop();
}

void OptionLayer::setLocation(const cocos2d::Point location) {
    this->location = location;
    this->joystick->setPosition(location);
}

Point OptionLayer::getLocation() {
    return this->location;
}


void OptionLayer::setRadius(const float radius) {
    if(radius != 0.0f) {
        this->radius = radius;
    }
}

float OptionLayer::getRadius() {
    return this->radius;
}
