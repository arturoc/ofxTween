#ifndef _PENNER_BOUNCE
#define _PENNER_BOUNCE

#include "ofxEasing.h"
class ofxEasingBounce: public ofxEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
