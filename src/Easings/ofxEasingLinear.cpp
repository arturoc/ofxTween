#include "ofxEasingLinear.h"

float ofxEasingLinear::easeNone (float t,float b , float c, float d)  const{
	return c*t/d + b;
}
float ofxEasingLinear::easeIn (float t,float b , float c, float d)  const{
	return c*t/d + b;
}
float ofxEasingLinear::easeOut(float t,float b , float c, float d) const {
	return c*t/d + b;
}

float ofxEasingLinear::easeInOut(float t,float b , float c, float d) const {
	return c*t/d + b;
}
