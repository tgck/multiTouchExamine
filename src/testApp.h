#pragma once

#include "ofMain.h"
#include "ofVectorMath.h"
#include "ofxOsc.h"

#include "MyFinger.h"
#define WINDOW_W 540
#define WINDOW_H 340
#define TO_HOST "localhost"
#define TO_PORT 7770 // lo_example_server

class testApp : public ofBaseApp{
private:
		ofxOscSender sender;
		void sendMessage(string str);
	void drawBackGround();
	
public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};




