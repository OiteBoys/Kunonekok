//
//  CharacterSprite.cpp
//  kunonekonok
//
//  Created by damingdan on 14-3-27.
//
//

#include "CharacterSprite.h"

CharacterSprite::CharacterSprite(){}

CharacterSprite::~CharacterSprite(){}

bool CharacterSprite::initWithFile(const string& file) {
    if(Sprite::initWithFile(file)) {
        Size textureSize = this->getContentSize();
        frameSize = Size(textureSize.width/3, textureSize.height/4);
        initActions();
        return true;
    }else {
        return false;
    }
}

void CharacterSprite::initActions() {
    this->walkDownAction = RepeatForever::create(Animate::create(this->getActionAniamation(0)));
    this->walkLeftAction = RepeatForever::create(Animate::create(this->getActionAniamation(1)));
    this->walkRightAction = RepeatForever::create(Animate::create(this->getActionAniamation(2)));
    this->walkUpAction = RepeatForever::create(Animate::create(this->getActionAniamation(3)));
}

Animation* CharacterSprite::getActionAniamation(const int row) {
    auto animation = Animation::create();
    animation->setDelayPerUnit(1.0f/4);
    for (int i=0; i< 3; i++) {
        if(i == 1) {
            continue;
        }
        auto frame = SpriteFrame::createWithTexture(this->getTexture(), Rect(frameSize.width*i, row*frameSize.height, frameSize.width, frameSize.height));
        animation->addSpriteFrame(frame);
    }
    return animation;
}

void CharacterSprite::idle(Direction direction) {
    if(changeState(ACTION_STATE_IDLE)) {
        if(direction == DIRECTION_DOWN) {
            this->setTextureRect(Rect(frameSize.width , 0, frameSize.width, frameSize.height));
        }else if(direction == DIRECTION_LEFT) {
            this->setTextureRect(Rect(frameSize.width , frameSize.height, frameSize.width, frameSize.height));
        }else if(direction == DIRECTION_RIGHT) {
            this->setTextureRect(Rect(frameSize.width , frameSize.height*2, frameSize.width, frameSize.height));
        }else if(direction == DIRECTION_UP) {
            this->setTextureRect(Rect(frameSize.width , frameSize.height*3, frameSize.width, frameSize.height));
        }
    }
}

void CharacterSprite::walk(Direction direction) {
    if (changeState(ACTION_STATE_WALK)) {
        if(direction == DIRECTION_DOWN) {
            this->runAction(this->walkDownAction);
        }else if(direction == DIRECTION_LEFT) {
            this->runAction(this->walkLeftAction);
        }else if(direction == DIRECTION_RIGHT) {
            this->runAction(this->walkRightAction);
        }else if(direction == DIRECTION_UP) {
            this->runAction(this->walkUpAction);
        }
    }
}

bool CharacterSprite::changeState(ActionState state) {
    this->stopAllActions();
    currentStatus = state;
    return true;
}

CharacterSprite* CharacterSprite::create(const std::string& filename)
{
    auto *sprite = new CharacterSprite();
    if (sprite && sprite->initWithFile(filename))
    {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}
