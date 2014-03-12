//
//  PreviousScene.h
//  Kunonekok
//
//  Created by damingdan on 14-3-9.
//
//

#pragma once
#include "cocos2d.h"
#include "AsideLayer.h"

using namespace cocos2d;

class PreviousScene : public Scene{
public:
    PreviousScene();
    
    ~PreviousScene();
    
    bool virtual init();
    
    CREATE_FUNC(PreviousScene);
    
private:
    AsideLayer *asideLayer;
};