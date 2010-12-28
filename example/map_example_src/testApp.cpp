#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	
	clamp = false;
	easingType = ofxTween::easeInOut;
	easestring = "ease in/out";
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(250, 250, 250);
	
	int numtweens = 11;
	
	float ystep = ofGetHeight() / numtweens;
	
	float y = 20;
	float x = 0;
	float radius = 7;
	
	ofSetColor(120, 120, 120);
	
	// we the mouse x position from the left hand side to the right hand side of the screen
	// into an inner amount with 100 pixel margin.
	// we can turn on and off clamping. Clamping off doesn't make sense for a lot of values

	
	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeLinear, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Linear", 120, y+15);
	y+=ystep;
	
	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeBounce, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Bounce", 120, y+15);
	y+=ystep;
	
	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeCubic, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Cubic", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeElastic, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Elastic", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeQuart, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Quart", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeBack, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Back", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeCirc, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Circular", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeExpo, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Exponential", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeQuad, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Quadratic", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeQuint, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Quintic", 120, y+15);
	y+=ystep;

	x = ofxTween::map(mouseX, 0, ofGetWidth(), 100, ofGetWidth()-100, clamp, easeSine, easingType);
	ofCircle(x, y, radius);
	ofLine(0, y, ofGetWidth(), y);
	ofDrawBitmapString("Sine", 120, y+15);
	y+=ystep;

	ofSetColor(220, 100, 100);
	ofLine(100, 0, 100, ofGetHeight());
	ofLine(ofGetWidth()-100, 0, ofGetWidth()-100, ofGetHeight());
	
	ofSetColor(100, 100, 220, 150);
	ofLine(mouseX, 0, mouseX, ofGetHeight());

	if(clamp){
		ofSetColor(100, 100, 100, 25);
		ofRect(0, 0, 100, ofGetHeight());
		ofRect(ofGetWidth()-100, 0, 100, ofGetHeight());
	}
	
	ofSetColor(0, 0, 0);
	string draw = string("press c to toggle clamp. clamp is ") + string(clamp ? "on" : "off");
	draw += "press e to change ease. ease is " + easestring;
	ofDrawBitmapString(draw, 120, 15);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if(key == 'c'){
		clamp = !clamp;
	}
	
	if(key == 'e'){
		if(easingType == ofxTween::easeIn){
			easingType = ofxTween::easeOut;
			easestring = "ease out";											
		}
		else if(easingType == ofxTween::easeOut){
			easingType = ofxTween::easeInOut;
			easestring = "ease in/out";											
		}
		else {
			easingType = ofxTween::easeIn;
			easestring = "ease in";											
		}
	}	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

