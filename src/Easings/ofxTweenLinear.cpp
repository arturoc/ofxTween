#include "ofxTweenLinear.h"

float ofxTweenLinear::easeNone (float t,float b , float c, float d) {
	return c*t/d + b;
}
float ofxTweenLinear::easeIn (float t,float b , float c, float d) {
	return c*t/d + b;
}
float ofxTweenLinear::easeOut(float t,float b , float c, float d) {
	return c*t/d + b;
}

float ofxTweenLinear::easeInOut(float t,float b , float c, float d) {
	return c*t/d + b;
}
