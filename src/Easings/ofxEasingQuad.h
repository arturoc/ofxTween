#ifndef _PENNER_QUAD
#define _PENNER_QUAD
#include "ofxEasing.h"
class ofxEasingQuad: public ofxEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
