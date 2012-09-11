#include "ofxEasingQuint.h"

float ofxEasingQuint::easeIn (float t,float b , float c, float d)  const{
	return c*(t/=d)*t*t*t*t + b;
}
float ofxEasingQuint::easeOut(float t,float b , float c, float d)  const{
	return c*((t=t/d-1)*t*t*t*t + 1) + b;
}

float ofxEasingQuint::easeInOut(float t,float b , float c, float d)  const{
	if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
	return c/2*((t-=2)*t*t*t*t + 2) + b;
}
