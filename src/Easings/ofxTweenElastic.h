#ifndef _PENNER_ELASTIC
#define _PENNER_ELASTIC

#include <math.h>
#include "ofxTweenEasing.h"
#ifndef PI
#define PI  3.14159265
#endif

class ofxTweenElastic: public ofxTweenEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);
};

#endif
