#include "testApp.h"
#include "ofxVectorMath.h"
#include "mt.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	MTDeviceRef dev = MTDeviceCreateDefault();
	MTRegisterContactFrameCallback(dev, mtCallback);
	MTDeviceStart(dev, 0);

	ofSetWindowPosition(0, 43);
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofHideCursor();
	
	ofBackground(0, 0, 0);
	
	ofSetColor(255, 255, 255);
	ofNoFill();
	
	sender.setup(TO_HOST, TO_PORT);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	
	drawBackGround();
	
	for (int i = 0; i< FINGER_ARR_SIZE ; i++){
			fingers[i].draw();
			sendMessage(fingers[i].report()); // ここじゃなくて、トラックした後に送りたい
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
}

//--------------------------------------------------------------
void testApp::sendMessage(string str){
	ofxOscMessage m;
	m.setAddress("/test");
	m.addStringArg(str);
	sender.sendMessage(m);
}

void testApp::drawBackGround(){
//	ofFill();
//	ofSetColor(0, 0, 0, 34);
//	ofRect(0, 0, WINDOW_W, WINDOW_H);
}