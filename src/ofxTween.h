#ifndef TWEEN_INCLUDED
#define TWEEN_INCLUDED


#include "Poco/Timestamp.h"
#include "ofxEasing.h"
#include "ofMain.h"

class ofxTween{

	public:
		enum ofxEasingType{
			easeIn,
			easeOut,
			easeInOut
		};

		ofxTween();
		ofxTween(int id, ofxEasing & easing, ofxEasingType type, float from, float to, unsigned duration, unsigned delay);

		void setParameters(int id, ofxEasing & easing, ofxEasingType type, float from, float to,  unsigned duration, unsigned delay);
		void setParameters( ofxEasing & easing, ofxEasingType type, float from, float to,  unsigned duration, unsigned delay);

		void addValue(float from, float to);
		void start();

		~ofxTween();

		float update();
		// calculates and applies a new value to the target

		float getTarget(unsigned pos);

		uint getDuration();
		void setDuration(uint duration);

		bool isRunning();
		bool isCompleted();

		int id;

		ofEvent<int> end_E;

	private:
		typedef Poco::Delegate<ofxEasing,ofxEasingArgs,false> ofxTweenDelegate;
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
		ofxEasing * easing;
		ofxEasingType type;

};

#include "ofxEasingBounce.h"
#include "ofxEasingCubic.h"
#include "ofxEasingElastic.h"
#include "ofxEasingLinear.h"
#include "ofxEasingQuart.h"
#include "ofxEasingBack.h"
#include "ofxEasingCirc.h"
#include "ofxEasingExpo.h"
#include "ofxEasingQuad.h"
#include "ofxEasingQuint.h"
#include "ofxEasingSine.h"
#endif
