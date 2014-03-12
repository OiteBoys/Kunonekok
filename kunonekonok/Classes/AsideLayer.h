//
//  AsideLayer.h
//  Kunonekok
//
//  Created by damingdan on 14-3-9.
//
//

#pragma once
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

const float DEFAULT_ANIMATE_DURATION = 0.1f;

const float DEFAULT_DISPLAY_SPEED = 0.1f;

const float DEFAULT_DELAY_DURATION = 0.5F;

class AsideLayer:public Layer {
public:
    AsideLayer();
    
    ~AsideLayer();

	bool virtual init();
    
	CREATE_FUNC(AsideLayer);

	/**
	* Add the words that you want to display
	*/
	void addAsides(vector<string> asides);

	/**
	* Add the words that you want to display by the cocos 2d Vector
	*/
	void addAsides(ValueVector asides);

	/**
	* Add the single word that you want to display
	*/
	void addAside(string aside);

	/**
	* Start to show the aside
	*/
	void startTell(int index = 0, float delay = 0.0f);

	void setStartPosition(Point point);

	Point getStartPosition();

	CC_SYNTHESIZE(float, animateDuration, AnimateDuration);

	CC_SYNTHESIZE(float, displaySpeed, DisplaySpeed);

	CC_SYNTHESIZE(float, delayDuration, DelayDuration);

	CC_SYNTHESIZE(float, lineHeight, LineHeiht);

private:
	vector<string> asides;

	Point startPosition;
	

	unsigned currentSentence;
	unsigned currentWord;

	SEL_SCHEDULE sentcenceSchedule;

	void tellSentence(float dt);

	Node *container;
};
