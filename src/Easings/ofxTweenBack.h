#ifndef _PENNER_BACK
#define _PENNER_BACK

#include "ofxTweenEasing.h"
class ofxTweenBack: public ofxTweenEasing {

	public:

		float easeIn(float t,float b , float c, float d);
		float easeOut(float t,float b , float c, float d);
		float easeInOut(float t,float b , float c, float d);

};

#endif
