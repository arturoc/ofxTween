#ifndef _PENNER_EXPO
#define _PENNER_EXPO

#include <math.h>
#include "ofxEasing.h"
class ofxEasingExpo: public ofxEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
