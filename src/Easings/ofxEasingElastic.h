#ifndef _PENNER_ELASTIC
#define _PENNER_ELASTIC

#include <math.h>
#include "ofxEasing.h"
#ifndef PI
#define PI  3.14159265
#endif

class ofxEasingElastic: public ofxEasing {

	public:

    ofxEasingElastic* clone () const { return new ofxEasingElastic(*this); }
		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
