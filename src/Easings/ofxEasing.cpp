/*
 * Easing.cpp
 *
 *  Created on: 17-sep-2008
 *      Author: arturo castro
 */

#include "ofxEasing.h"

void ofxEasing::easeIn(ofxEasingArgs & args){
	args.res=easeIn(args.t,args.b,args.c,args.d);
}

void ofxEasing::easeOut(ofxEasingArgs & args){
	args.res=easeOut(args.t,args.b,args.c,args.d);
}

void ofxEasing::easeInOut(ofxEasingArgs & args){
	args.res=easeInOut(args.t,args.b,args.c,args.d);
}
