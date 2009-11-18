#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	unsigned delay = 2000;
	unsigned duration = 1000;
	tweenback.setParameters(1,easingback,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenbounce.setParameters(2,easingbounce,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweencirc.setParameters(3,easingcirc,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweencubic.setParameters(4,easingcubic,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenelastic.setParameters(5,easingelastic,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenexpo.setParameters(6,easingexpo,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenlinear.setParameters(7,easinglinear,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenquad.setParameters(8,easingquad,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenquart.setParameters(9,easingquart,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
    tweenquint.setParameters(10,easingquint,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);

}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofRect(20,20,tweenback.update(),20);
	ofRect(20,50,tweenback.update(),20);
	ofRect(20,80,tweenbounce.update(),20);
	ofRect(20,110,tweencirc.update(),20);
	ofRect(20,140,tweencubic.update(),20);
	ofRect(20,170,tweenelastic.update(),20);
	ofRect(20,200,tweenexpo.update(),20);
	ofRect(20,230,tweenlinear.update(),20);
	ofRect(20,260,tweenquad.update(),20);
	ofRect(20,290,tweenquart.update(),20);
	ofRect(20,320,tweenquint.update(),20);
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	unsigned delay = 0;
	unsigned duration = 1000;
	tweenback.setParameters(1,easingback,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenbounce.setParameters(2,easingbounce,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweencirc.setParameters(3,easingcirc,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweencubic.setParameters(4,easingcubic,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenelastic.setParameters(5,easingelastic,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenexpo.setParameters(6,easingexpo,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenlinear.setParameters(7,easinglinear,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenquad.setParameters(8,easingquad,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenquart.setParameters(9,easingquart,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);
	tweenquint.setParameters(10,easingquint,ofxTween::easeOut,0,ofGetWidth()-100,duration,delay);


}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

