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


class AsideLayer:public Layer {
public:
    AsideLayer();
    
    ~AsideLayer();

	bool virtual init();
    
	CREATE_FUNC(AsideLayer);
};
