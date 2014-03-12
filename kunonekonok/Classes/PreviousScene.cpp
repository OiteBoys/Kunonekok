//
//  PreviousScene.cpp
//  Kunonekok
//
//  Created by damingdan on 14-3-9.
//
//

#include "PreviousScene.h"

PreviousScene::PreviousScene(){}

PreviousScene::~PreviousScene(){}

bool PreviousScene::init() {
	if (Scene::init()) {
		asideLayer = AsideLayer::create();
		if(asideLayer) {
			ValueVector txtVec = FileUtils::getInstance()->getValueVectorFromFile("previous.xml");
			asideLayer->addAsides(txtVec);
			asideLayer->setLineHeiht(80);
			Size winSize = Director::getInstance()->getWinSize();
			asideLayer->setStartPosition(Point(winSize.width/2, winSize.height/5*4));
			this->addChild(asideLayer);
			asideLayer->startTell();
		}
		return true;
	}else {
		return false;
	}
}


