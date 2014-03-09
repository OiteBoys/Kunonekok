#pragma once

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class WelcomeLayer : public Layer{
public :
	WelcomeLayer(void);
	~WelcomeLayer(void);
	virtual bool init();

	CREATE_FUNC(WelcomeLayer);

private:
	void menuStartCallabck(Object* pSender);

	void menuContinueCallback(Object* pSender);

	void menuGameOverCallback(Object* pSender);

};
