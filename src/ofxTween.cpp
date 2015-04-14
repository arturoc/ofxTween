#include "ofxTween.h"

ofxTween::ofxTween(){
	duration = 0;
	completed = true;
	easingFunction = NULL;
	running = false;

	easing = NULL;
	id = -1;
	frameBased = false;
}

ofxTween::ofxTween(const ofxTween &other)
: id(other.id),
end_E(other.end_E),
timestamp(other.timestamp),
from(other.from),
to(other.to),
change(other.change),
pTarget(other.pTarget),
elapsed(other.elapsed),
startTime(other.startTime),
delay(other.delay),
duration(other.duration),
running(other.running),
completed(other.completed),
type(other.type),
frameBased(other.frameBased) {
    if (other.easingFunction) {
        easingFunction = new ofxTweenDelegate(*other.easingFunction);
    }
    else {
        easingFunction = NULL;
    }
    if (other.easing) {
        easing = other.easing;
    }
    else {
        easing = NULL;
    }
}

ofxTween ofxTween::operator=(const ofxTween &other)
{
    id = other.id;
    end_E = other.end_E;
    timestamp = other.timestamp;
    from = other.from;
    to = other.to;
    change = other.change;
    pTarget = other.pTarget;
    elapsed = other.elapsed;
    startTime = other.startTime;
    delay = other.delay;
    duration = other.duration;
    running = other.running;
    completed = other.completed;
    type = other.type;
    frameBased = other.frameBased;
    if (other.easingFunction) {
        easingFunction = new ofxTweenDelegate(*other.easingFunction);
    }
    else {
        easingFunction = NULL;
    }
    if (other.easing) {
        easing = other.easing;
    }
    else {
        easing = NULL;
    }
    return *this;
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
	if(frameBased){
		duration = _duration;
		delay = _delay;
	}else{
		duration = _duration*1000;
		delay = _delay*1000;
	}
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
	if(!frameBased){
		timestamp = Poco::Timestamp();
		timestamp += delay;
	}else{
		elapsed=0;
	}
}

void ofxTween::setDuration(int _duration) {
	if(frameBased){
		duration = _duration;
	}else{
		duration = _duration*1000;
	}
}

int ofxTween::getDuration() {
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
	if (!completed) {

		if (frameBased) {
			if (elapsed >= delay + duration) {
				for(unsigned i=0; i<from.size(); i++) {
					pTarget[i] = to[i];
				}
				running = false;
				completed = true;
				ofNotifyEvent(end_E,id);
			} else if (elapsed >= 0) {
				elapsed++;
				if (elapsed > delay) {
					ofxEasingArgs args;
					args.t= elapsed - delay;
					args.d= float(duration);
					for (unsigned i=0; i<from.size(); i++) {
						args.b=from[i];
						args.c=change[i];

						easingFunction->notify(this,args);
						pTarget[i] = args.res;
					}
					running = true;
				}
			}
		} else {
			if (timestamp.isElapsed(duration)) {
				for (unsigned i=0; i<from.size(); i++) {
					pTarget[i] = to[i];
				}
				running = false;
				completed = true;
				ofNotifyEvent(end_E,id);
			} else if (timestamp.elapsed()>0) {
				ofxEasingArgs args;
				float elapsedTime = float(timestamp.elapsed());
				args.t= elapsedTime;
				args.d= float(duration);
				for (unsigned i=0; i<from.size(); i++) {
					args.b=from[i];
					args.c=change[i];

					easingFunction->notify(this,args);
					pTarget[i] = args.res;
				}
				running = true;
			}
		}
	}
	return getTarget(0);
}


void ofxTween::setFrameBasedAnimation(bool frameBased){
	this->frameBased = frameBased;
}

float ofxTween::map(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp, const ofxEasing & easing)
{
	return ofxTween::map(value, inputMin, inputMax, outputMin, outputMax, clamp, easing, ofxTween::easeInOut);
}

float ofxTween::map(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp, const ofxEasing & easing, ofxEasingType type)
{
	if(clamp){
		value = ofClamp(value, inputMin, inputMax);
	}
	float t = value - inputMin;
	float c = outputMax - outputMin;
	float d = inputMax - inputMin;
	float b = outputMin;
	float res;
	switch (type) {
		case ofxTween::easeIn:
		{
			res = easing.easeIn(t,b,c,d);
			break;
		}
		case ofxTween::easeOut:
		{
			res = easing.easeOut(t,b,c,d);
			break;
		}
		default:
			res = easing.easeInOut(t,b,c,d);
	}
	
	return res;
}

