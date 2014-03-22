//
//  Terrain.h
//  kunonekonok
//
//  Created by damingdan on 14-3-21.
//
//

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#define MaxHillKeyPoints 1000

class Terrain : public Node {
public:
    Terrain();
    ~Terrain();
    virtual bool init();
    CREATE_FUNC(Terrain);
    Sprite* spriteWithColor(Color4F color, float width, float height);
    Sprite* stripedSpriteWithColor(Color4F foregroundColor, Color4F backgroundColor, float width, float height, int stripCount);
    Color4F randomBrightColor();
    void genBackground();
    CC_SYNTHESIZE_RETAIN(Sprite*, background, Background);
};