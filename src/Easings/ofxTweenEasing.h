#ifndef EASING_H_
#define EASING_H_

class ofxTweenEasingArgs{
public:
	float t;
	float b;
	float c;
	float d;

	float res;
};


class ofxTweenEasing{
public:
		void easeIn(ofxTweenEasingArgs & args);
		void easeOut(ofxTweenEasingArgs & args);
		void easeInOut(ofxTweenEasingArgs & args);

		virtual float easeIn(float t,float b , float c, float d)=0;
		virtual float easeOut(float t,float b , float c, float d)=0;
		virtual float easeInOut(float t,float b , float c, float d)=0;
};

#endif /* EASING_H_ */
