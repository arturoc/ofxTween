#include "ofxEasingCirc.h"

float ofxEasingCirc::easeIn (float t,float b , float c, float d) const {
	return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
}
float ofxEasingCirc::easeOut(float t,float b , float c, float d) const {
	return c * sqrt(1 - (t=t/d-1)*t) + b;
}

float ofxEasingCirc::easeInOut(float t,float b , float c, float d) const {
	if ((t/=d/2) < 1) return c/2 * (1 - sqrt(1 - t*t)) + b;
	return c/2 * (sqrt(1 - (t-=2)*t) + 1) + b;
}
