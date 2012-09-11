#include "ofxEasingExpo.h"

float ofxEasingExpo::easeIn (float t,float b , float c, float d)  const{
	return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}
float ofxEasingExpo::easeOut(float t,float b , float c, float d)  const{
	return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
}

float ofxEasingExpo::easeInOut(float t,float b , float c, float d)  const{
	if (t==0) return b;
	if (t==d) return b+c;
	if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
	return c/2 * (-pow(2, -10 * --t) + 2) + b;
}
