#include "ofxEasingSine.h"

float ofxEasingSine::easeIn (float t,float b , float c, float d)  const{
	return -c * cos(t/d * (PI/2)) + c + b;
}
float ofxEasingSine::easeOut(float t,float b , float c, float d)  const{
	return c * sin(t/d * (PI/2)) + b;
}

float ofxEasingSine::easeInOut(float t,float b , float c, float d)  const{
	return -c/2 * (cos(PI*t/d) - 1) + b;
}
