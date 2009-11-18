/*
 * Copyright 2007 (c) Erik Sjodin, eriksjodin.net
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * Inspired by http://code.google.com/p/tweener/
 * Uses http://www.jesusgollonet.com/blog/2007/09/24/penner-easing-cpp/
 */

#include "ofxTween.h"

ofxTween::ofxTween(){
	duration = 0;
	completed = true;
	easingFunction = NULL;
	running = false;


	easing = NULL;
	id = -1;

}

ofxTween::ofxTween(int id,  ofxTweenEasing & easing, ofxEasingType type,  float from, float to, unsigned duration, unsigned delay) {
	setParameters(id, easing, type, from,to,duration,delay);
}

ofxTween::~ofxTween() {
	if(easingFunction) delete easingFunction;
}

void ofxTween::setParameters( ofxTweenEasing & easing, ofxEasingType type, float from, float to, unsigned duration, unsigned delay){
	setParameters(id, easing, type, from,to,duration,delay);
}

void ofxTween::setParameters(int _id,  ofxTweenEasing & _easing, ofxEasingType _type,  float _from, float _to, unsigned _duration, unsigned _delay){
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
		easingFunction = new ofxTweenDelegate(easing, &ofxTweenEasing::easeIn);
	break;
	case easeOut:
		easingFunction = new ofxTweenDelegate(easing, &ofxTweenEasing::easeOut);
	break;
	case easeInOut:
		easingFunction = new ofxTweenDelegate(easing, &ofxTweenEasing::easeInOut);
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

float ofxTween::getTarget(int pos) {
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
			ofxTweenEasingArgs args;
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
