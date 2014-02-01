#ifndef _PENNER_BOUNCE
#define _PENNER_BOUNCE

#include "ofxEasing.h"
class ofxEasingBounce: public ofxEasing {

	public:

    ofxEasingBounce* clone () const { return new ofxEasingBounce(*this); }
		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;
};

#endif
