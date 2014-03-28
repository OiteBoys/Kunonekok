#include "AppDelegate.h"
#include "PreviousScene.h"
#include "MotionStreakExampleScene.h"
#include "SampleScene.h"
#include "GameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
	eglView->setDesignResolutionSize(480/2,800/2, ResolutionPolicy::SHOW_ALL);
	this->setResourceSearchResolution();

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	auto scene = GameScene::create();

    // run
    director->runWithScene(scene);
    Director::getInstance()->setProjection(Director::Projection::_2D);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AppDelegate::setResourceSearchResolution(){
	std::vector<std::string> paths;

	paths.push_back("images");
	paths.push_back("maps");
	paths.push_back("text");
	paths.push_back("fonts");

	FileUtils::getInstance()->setSearchPaths(paths);
}