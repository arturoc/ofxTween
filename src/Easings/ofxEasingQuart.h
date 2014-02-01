#ifndef _PENNER_QUART
#define _PENNER_QUART
#include "ofxEasing.h"
class ofxEasingQuart: public ofxEasing {

	public:

    ofxEasingQuart* clone () const { return new ofxEasingQuart(*this); }
		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
