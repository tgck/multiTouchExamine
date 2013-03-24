/*
 *  MyFinger.h
 *  emptyExample
 *
 */
#ifndef _MYFINGER_H_
#define _MYFINGER_H_

#include "ofxVectorMath.h"
#define FINGER_ARR_SIZE 11

// 必要なメンバだけ用意する
class MyFinger {
public:
	int     identifier;
	double  timestamp;
	
	bool    isValid;
	ofVec2f vel;
	ofVec2f pos;
	float   size;
	
	// 描画
	void draw();
	string report();
	void clear();
	
	// utils
	char id2aid(int);
};
#endif //_MYFINGER_H_