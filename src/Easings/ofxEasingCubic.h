#ifndef _PENNER_CUBIC
#define _PENNER_CUBIC
#include "ofxEasing.h"
class ofxEasingCubic: public ofxEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
