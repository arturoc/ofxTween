#include "ofxEasingQuad.h"

float ofxEasingQuad::easeIn (float t,float b , float c, float d)  const{
	return c*(t/=d)*t + b;
}
float ofxEasingQuad::easeOut(float t,float b , float c, float d)  const{
	return -c *(t/=d)*(t-2) + b;
}

float ofxEasingQuad::easeInOut(float t,float b , float c, float d)  const{
	if ((t/=d/2) < 1) return c/2*t*t + b;
	return -c/2 * ((--t)*(t-2) - 1) + b;
	
	/*
	
	originally return -c/2 * (((t-2)*(--t)) - 1) + b;

	I've had to swap (--t)*(t-2) due to diffence in behaviour in
	pre-increment operators between java and c++, after hours
	of joy
	 
	 James George:: The fix refered to above actually broke the equation, 
	 it would land at 50% all the time at the end
	 copying back the original equation from online fixed it...
	 
	 potentially compiler dependent.
	*/

}
