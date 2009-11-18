#ifndef _PENNER_SINE
#define _PENNER_SINE
#include "ofxTweenEasing.h"
#include <math.h>

#ifndef PI
#define PI  3.14159265
#endif

class ofxTweenSine: public ofxTweenEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);

};

#endif
