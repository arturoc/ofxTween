#ifndef _PENNER_QUINT
#define _PENNER_QUINT
#include "ofxEasing.h"
class ofxEasingQuint: public ofxEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
