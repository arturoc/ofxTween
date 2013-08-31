/*
 *  ofxTweenMapExample
 *
 * Created by James George http://www.jamesgeorge.org
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * ----------------------
 *
 * ofxTweenMapExample shows how to use the added static mapping function
 * in ofxTween.
 *
 */
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
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	ofxEasingBounce easeBounce;
	ofxEasingCubic easeCubic;
	ofxEasingElastic easeElastic;
	ofxEasingLinear easeLinear;
	ofxEasingQuart easeQuart;
	ofxEasingBack easeBack;
	ofxEasingCirc easeCirc;
	ofxEasingExpo easeExpo;
	ofxEasingQuad easeQuad;
	ofxEasingQuint easeQuint;
	ofxEasingSine easeSine;	
	
	float clamp;
	ofxTween::ofxEasingType easingType;
	string easestring;

};

#endif
