#include "AsideLayer.h"

AsideLayer::AsideLayer() {
}

AsideLayer::~AsideLayer(){
}

bool AsideLayer::init() {
	if(Layer::init()) {
		// init variety
		this->currentSentence = 0;
		this->currentWord = 0;
		this->lineHeight = 0;
		this->animateDuration = DEFAULT_ANIMATE_DURATION;
		this->displaySpeed = DEFAULT_DISPLAY_SPEED;
		this->delayDuration = DEFAULT_DELAY_DURATION;

		// Add the label to display the sentence
		this->container = Node::create();
		Size winSize = Director::getInstance()->getWinSize();
		this->startPosition = Point(winSize.width/2, winSize.height/2);
		container->setPosition(startPosition.x, startPosition.y);
		this->addChild(this->container);

		// Define the schedule
		sentcenceSchedule = schedule_selector( AsideLayer::tellSentence);
		return true;
	} else {
		return false;
	}
}

Point AsideLayer::getStartPosition() {
	return this->startPosition;
}

void AsideLayer::setStartPosition(Point point) {
	this->startPosition = point;
	container->setPosition(startPosition.x, startPosition.y);
}

void AsideLayer::addAsides(vector<string> asides) {
	for(auto aside : asides){
		this->asides.push_back(aside);
	}
}

void AsideLayer::addAsides(ValueVector asides) {
	for(auto aside : asides){
		this->asides.push_back(aside.asString());
	}
}

void AsideLayer::addAside(string aside) {
	this->asides.push_back(aside);
}

void AsideLayer::startTell(int index, float delay) {
	auto sentence = this->asides.at(index);
	auto label = LabelBMFont::create(sentence, "chinese.fnt");
	label->setTag(this->currentSentence);
	this->lineHeight = (lineHeight > label->getContentSize().height)?lineHeight:label->getContentSize().height;
	label->setPositionY(-lineHeight * this->currentSentence);
	this->container->addChild(label);

	int i = 0;
	this->currentWord = 0;
	for(auto word : label->getChildren()) {
		word->setTag(i ++);
		word->setOpacity(0.0f);
	}
	this->schedule(sentcenceSchedule, this->displaySpeed, label->getChildrenCount() + 1, delay);
}

void AsideLayer::tellSentence(float dt) {
	auto label = this->container->getChildByTag(currentSentence);
	if(this->currentWord >= label->getChildrenCount()) {
		this->unschedule(sentcenceSchedule);
		// If there are more sentence, say it.
		if(this->currentSentence < this->asides.size() - 1){
			this->currentSentence ++;
			this->startTell(this->currentSentence, this->delayDuration);
		}
	}else {
		auto word = label->getChildByTag(this->currentWord ++ );
		auto showAction = FadeIn::create(this->animateDuration);
		word->runAction(showAction);
	}
}

