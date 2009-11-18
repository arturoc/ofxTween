/*
 * Easing.cpp
 *
 *  Created on: 17-sep-2008
 *      Author: arturo castro
 */

#include "ofxTweenEasing.h"


void ofxTweenEasing::easeIn(ofxTweenEasingArgs & args){
	args.res=easeIn(args.t,args.b,args.c,args.d);
}

void ofxTweenEasing::easeOut(ofxTweenEasingArgs & args){
	args.res=easeOut(args.t,args.b,args.c,args.d);
}

void ofxTweenEasing::easeInOut(ofxTweenEasingArgs & args){
	args.res=easeInOut(args.t,args.b,args.c,args.d);
}
