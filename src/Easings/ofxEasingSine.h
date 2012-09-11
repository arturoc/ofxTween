#ifndef _PENNER_SINE
#define _PENNER_SINE
#include "ofxEasing.h"
#include <math.h>

#ifndef PI
#define PI  3.14159265
#endif

class ofxEasingSine: public ofxEasing {

	public:

		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;

};

#endif
