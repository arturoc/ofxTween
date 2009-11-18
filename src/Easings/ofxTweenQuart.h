#ifndef _PENNER_QUART
#define _PENNER_QUART
#include "ofxTweenEasing.h"
class ofxTweenQuart: public ofxTweenEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
