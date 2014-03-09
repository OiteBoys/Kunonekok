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
        return true;
    }else {
        return false;
    }
}


