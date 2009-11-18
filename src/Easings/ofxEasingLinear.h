#ifndef _PENNER_LINEAR
#define _PENNER_LINEAR

#include "ofxEasing.h"
class ofxEasingLinear: public ofxEasing {

	public:

		float easeNone(float t,float b , float c, float d); // ??
		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);

};

#endif
