#include "WelcomeLayer.h"

WelcomeLayer::WelcomeLayer(){};

WelcomeLayer::~WelcomeLayer(){};

bool WelcomeLayer::init(){
	if(!Layer::init()){
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point originPoint = Director::getInstance()->getVisibleOrigin();
	
	auto bgSprite = Sprite::create("K.jpg");
	bgSprite->setPosition(Point(originPoint.x + visibleSize.width /2,originPoint.y + visibleSize.height * 2 / 3));
	this->addChild(bgSprite);

	//create the start buttom on the welcome layer
	auto startItemNormal = TextFieldTTF::textFieldWithPlaceHolder("Game Start","Arial",30);
	auto startItemPress = TextFieldTTF::textFieldWithPlaceHolder("Game Start","Arial",30);
	startItemPress->setPositionY(5);
	auto startItem = MenuItemSprite::create(startItemNormal,startItemPress,CC_CALLBACK_1(WelcomeLayer::menuStartCallabck,this));
	startItem->setPosition(Point(originPoint.x + visibleSize.width / 2, originPoint.y + visibleSize.height / 2));
	
	//create the continue game menuitem on the welcome layer
	auto continueItemNormal = TextFieldTTF::textFieldWithPlaceHolder("Continue","Arial",30);
	auto continueItemPress = TextFieldTTF::textFieldWithPlaceHolder("Continue","Arial",30);
	continueItemPress->setPositionY(5);
	auto continueItem = MenuItemSprite::create(continueItemNormal,continueItemPress,CC_CALLBACK_1(WelcomeLayer::menuContinueCallback,this));
	continueItem->setPosition(Point(originPoint.x + visibleSize.width / 2, originPoint.y + visibleSize.height / 2 - 35.0f));

	//create the over game on menuitem ont the welcome layer
	auto overItemNormal = TextFieldTTF::textFieldWithPlaceHolder("Game Over","Arial",30);	
	auto overItemPress = TextFieldTTF::textFieldWithPlaceHolder("Game Over","Arial",30);
	overItemPress->setPositionY(5);
	auto overItem = MenuItemSprite::create(overItemNormal,overItemPress,CC_CALLBACK_1(WelcomeLayer::menuGameOverCallback,this));
	overItem->setPosition(Point(originPoint.x + visibleSize.width / 2, originPoint.y + visibleSize.height / 2 - 65.0f));

	auto menu = Menu::create(startItem,continueItem,overItem,NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu,1);
	

	return true;
}

void WelcomeLayer::menuStartCallabck(Object* pSender){

}

void WelcomeLayer::menuContinueCallback(Object* pSender){

}

void WelcomeLayer::menuGameOverCallback(Object* pSender){

}
