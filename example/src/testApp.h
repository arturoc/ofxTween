#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#include "ofxTween.h"

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

       float length_float;

       ofxTween tweenback;
       ofxTween tweenbounce;
       ofxTween tweencirc;
       ofxTween tweencubic;
       ofxTween tweenelastic;
       ofxTween tweenexpo;
       ofxTween tweenlinear;
       ofxTween tweenquad;
       ofxTween tweenquart;
       ofxTween tweenquint;
       ofxTween tweensine;

       ofxTween multitween;

       ofxEasingBack 	easingback;
       ofxEasingBounce 	easingbounce;
       ofxEasingCirc 	easingcirc;
       ofxEasingCubic 	easingcubic;
       ofxEasingElastic easingelastic;
       ofxEasingExpo 	easingexpo;
       ofxEasingLinear 	easinglinear;
       ofxEasingQuad 	easingquad;
       ofxEasingQuart 	easingquart;
       ofxEasingQuint 	easingquint;
       ofxEasingSine	easingsine;
};

#endif
