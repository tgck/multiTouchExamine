/*
 *  MyFinger.cpp
 *  emptyExample
 *
 */
#include "MyFinger.h"
#include "ofMain.h"
#include "testApp.h"

void MyFinger::draw(){
	if (isValid) {
		ofSetColor(255, 255, 0);
		ofFill();
		ofRect( WINDOW_W * pos.x, WINDOW_H * pos.y, 10* size, 10*size); // normalizedされているので変換かけること
	}
}

// ------------------
// オブジェクト内部状態のレポート
// ------------------
string MyFinger::report(){
	if (isValid) {
			string str = ofToString(timestamp, 4)	+ ":" 
				+ ofToString(id2aid(identifier)) + ":"
				+	ofToString(vel.x) + ":" + ofToString(vel.y) + ":" 
				+ ofToString(pos.x) + ":" + ofToString(pos.y) + ":" 
				+ ofToString(size, 2);
		return str;
	} else {
		return "isNotAvailable";
	}
}

void MyFinger::clear(){
	isValid = false;
	vel.x = vel.y = 0.0;
	pos.x = pos.y = 0.0;
	size = 0.0;	
}

// util - id を識別しやすくする
char MyFinger::id2aid(int nid){
	switch (nid) {
		case 0: return 'A'; break;
		case 1: return 'B'; break;			
		case 2: return 'C'; break;
		case 3: return 'D'; break;
		case 4: return 'E'; break;
		case 5: return 'F'; break;
		case 6: return 'G'; break;
		case 7: return 'H'; break;
		case 8: return 'I'; break;
		case 9: return 'J'; break;
		case 10: return 'K'; break;
		case 11: return 'L'; break;
	}
	
}