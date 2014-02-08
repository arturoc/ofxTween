#ifndef EASING_H_
#define EASING_H_

class ofxEasingArgs{
public:
	float t;
	float b;
	float c;
	float d;

	float res;
};


class ofxEasing{
public:
    
		void easeIn(ofxEasingArgs & args);
		void easeOut(ofxEasingArgs & args);
		void easeInOut(ofxEasingArgs & args);

		virtual float easeIn(float t,float b , float c, float d) const=0;
		virtual float easeOut(float t,float b , float c, float d) const=0;
		virtual float easeInOut(float t,float b , float c, float d) const=0;
};

#endif /* EASING_H_ */
