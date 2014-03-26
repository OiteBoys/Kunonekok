//
//  MapLayer.h
//  kunonekonok
//
//  Created by damingdan on 14-3-26.
//
//

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class MapLayer : public Layer{
public:
    MapLayer();
    ~MapLayer();
    bool virtual init();
    CREATE_FUNC(MapLayer);
    
private:
    TMXTiledMap* map;
    TMXLayer* background;
};