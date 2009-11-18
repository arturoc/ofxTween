#ifndef _PENNER_EXPO
#define _PENNER_EXPO

#include <math.h>
#include "ofxTweenEasing.h"
class ofxTweenExpo: public ofxTweenEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
