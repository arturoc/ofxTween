#include "ofxTween.h"

ofxTween::ofxTween(){
	duration = 0;
	completed = true;
	easingFunction = NULL;
	running = false;


	easing = NULL;
	id = -1;

}

ofxTween::ofxTween(int id,  ofxEasing & easing, ofxEasingType type,  float from, float to, unsigned duration, unsigned delay) {
	setParameters(id, easing, type, from,to,duration,delay);
}

ofxTween::~ofxTween() {
	if(easingFunction) delete easingFunction;
}

void ofxTween::setParameters( ofxEasing & easing, ofxEasingType type, float from, float to, unsigned duration, unsigned delay){
	setParameters(id, easing, type, from,to,duration,delay);
}

void ofxTween::setParameters(int _id,  ofxEasing & _easing, ofxEasingType _type,  float _from, float _to, unsigned _duration, unsigned _delay){
	from.clear();
	to.clear();
	change.clear();
	pTarget.clear();

	id 		= _id;
	type 	= _type;
	easing 	= &_easing;
	if(easingFunction) delete easingFunction;
	switch(type){
	case easeIn:
		easingFunction = new ofxTweenDelegate(easing, &ofxEasing::easeIn);
	break;
	case easeOut:
		easingFunction = new ofxTweenDelegate(easing, &ofxEasing::easeOut);
	break;
	case easeInOut:
		easingFunction = new ofxTweenDelegate(easing, &ofxEasing::easeInOut);
	break;
	}

	addValue(_from,_to);
	duration = _duration*1000;
	delay = _delay*1000;
	start();

	completed = false;
	running = true;

}

void ofxTween::addValue(float _from, float _to){
	from.push_back(_from);
	to.push_back(_to);
	change.push_back(_to-_from);
	pTarget.push_back(_from);
}

void ofxTween::start(){
	timestamp = Poco::Timestamp();
	timestamp += delay;
}

void ofxTween::setDuration(uint _duration) {
	duration = _duration*1000;
}

uint ofxTween::getDuration() {
	return duration;
}

float ofxTween::getTarget(unsigned pos) {
	if(pTarget.size()>pos)
		return pTarget[pos];
	else
		return 0;
}

bool ofxTween::isRunning() {
	return running;
}

bool ofxTween::isCompleted() {
	return completed;
}

float ofxTween::update() {
	if(!completed){

		if (timestamp.isElapsed(duration)){
			for(unsigned i=0; i<from.size(); i++){
				pTarget[i] = to[i];
			}
			running = false;
			completed = true;
			ofNotifyEvent(end_E,id);
		}

		else if(timestamp.elapsed()>0){
			ofxEasingArgs args;
			float elapsedTime = float(timestamp.elapsed());
			args.t= elapsedTime;
			args.d= float(duration);
			for(unsigned i=0; i<from.size(); i++){
				args.b=from[i];
				args.c=change[i];

				easingFunction->notify(this,args);
				pTarget[i] = args.res;
			}
			running = true;
		}
	}
	return getTarget(0);
}
