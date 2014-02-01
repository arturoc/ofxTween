#ifndef _PENNER_LINEAR
#define _PENNER_LINEAR

#include "ofxEasing.h"
class ofxEasingLinear: public ofxEasing {

	public:

		float easeNone(float t,float b , float c, float d) const; // ??
		float easeIn(float t,float b , float c, float d) const;
		float easeOut(float t,float b , float c, float d) const;
		float easeInOut(float t,float b , float c, float d) const;

};

#endif
