//
//  CharacterSprite.h
//  kunonekonok
//
//  Created by damingdan on 14-3-27.
//
//

#pragma once
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

typedef enum{
    ACTION_STATE_IDLE = 0,
    ACTION_STATE_WALK
} ActionState;

typedef enum _direction {
    DIRECTION_UP = 0,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
} Direction;

class CharacterSprite : public Sprite {
public:
    CharacterSprite();
    ~CharacterSprite();
    
    virtual bool initWithFile(const string& filename);
    static CharacterSprite* create(const string& filename);
    
    void setFile(const string& filename);
    void update(float dt);
    
    static CharacterSprite* getInstance();
    
    CC_SYNTHESIZE_RETAIN(Action*, idleAction, IdleAction);
    CC_SYNTHESIZE_RETAIN(Action*, walkUpAction, WalkUpAction);
    CC_SYNTHESIZE_RETAIN(Action*, walkDownAction, WalkDownAction);
    CC_SYNTHESIZE_RETAIN(Action*, walkLeftAction, WalkLeftAction);
    CC_SYNTHESIZE_RETAIN(Action*, walkRightAction, WalkRightAction);
    
    void idle(Direction direction);
    void idle();
    void walk(Direction direction);
    
    Direction getCurrentDirection();
    ActionState getCurrentStatus();
    
private:
    static CharacterSprite* shareCharacterSprite;
    void initActions();
    Animation* getActionAniamation(const int row);
    Size frameSize;
    Direction currentDirection;
    
    bool changeState(ActionState state);
    ActionState currentStatus;
};