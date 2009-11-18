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

#ifndef TWEEN_INCLUDED
#define TWEEN_INCLUDED


#include "Poco/Timestamp.h"
#include "ofxTweenEasing.h"
#include "ofMain.h"






class ofxTween{

	public:
		enum ofxEasingType{
			easeIn,
			easeOut,
			easeInOut
		};

		ofxTween();
		ofxTween(int id, ofxTweenEasing & easing, ofxEasingType type, float from, float to, unsigned duration, unsigned delay);

		void setParameters(int id, ofxTweenEasing & easing, ofxEasingType type, float from, float to,  unsigned duration, unsigned delay);
		void setParameters( ofxTweenEasing & easing, ofxEasingType type, float from, float to,  unsigned duration, unsigned delay);

		void addValue(float from, float to);
		void start();

		~ofxTween();

		float update();
		// calculates and applies a new value to the target

		float getTarget(int pos);

		uint getDuration();
		void setDuration(uint duration);

		bool isRunning();
		bool isCompleted();

		int id;

		ofEvent<int> end_E;

	private:
		typedef Poco::Delegate<ofxTweenEasing,ofxTweenEasingArgs,false> ofxTweenDelegate;
		Poco::Timestamp	timestamp;

		vector<float> from;
		vector<float> to;
		vector<float> change;
		vector<float> pTarget;

		float startTime;

		unsigned delay;
		unsigned duration;

		bool running;
		bool completed;



		ofxTweenDelegate * easingFunction;
		ofxTweenEasing * easing;
		ofxEasingType type;

};


#include "ofxTweenBounce.h"
#include "ofxTweenCubic.h"
#include "ofxTweenElastic.h"
#include "ofxTweenLinear.h"
#include "ofxTweenQuart.h"
#include "ofxTweenSine.h"
#include "ofxTweenBack.h"
#include "ofxTweenCirc.h"
#include "ofxTweenEasing.h"
#include "ofxTweenExpo.h"
#include "ofxTweenQuad.h"
#include "ofxTweenQuint.h"
#endif
