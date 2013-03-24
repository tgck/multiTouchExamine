/*
 *  mt.h
 *  -- via satoruhiga at openFrameworks.jp
 *         http://openframeworks.jp/forum/topic.php?id=4#post-13
 */
#ifndef _MT_H_
#define _MT_H_
#include "testApp.h"
#include "MyFinger.h"

extern vector<MyFinger> fingers;

extern "C"
{	
	typedef struct { float x,y; } mtPoint;
	typedef struct { mtPoint pos,vel; } mtReadout;
	
	typedef struct {
		int       frame;
		double    timestamp;
		int       identifier, state, foo3, foo4;
		mtReadout normalized;
		float     size;
		int       zero1;
		float     angle, majorAxis, minorAxis; // ellipsoid
		mtReadout mm;
		int       zero2[2];
		float     unk2;
	} Finger;
	
	typedef void *MTDeviceRef;
	typedef int (*MTContactCallbackFunction)(int,Finger*,int,double,int);
	
	MTDeviceRef MTDeviceCreateDefault();
	void MTRegisterContactFrameCallback(MTDeviceRef, MTContactCallbackFunction);
	void MTDeviceStart(MTDeviceRef, int); // thanks comex
}

// 独自定義
int  mtCallback(int device, Finger *data, int nFingers, double timestamp, int frame);
void debugPrint(Finger* f);
void pack2MyFinger(const Finger *f, MyFinger &mf);

enum statusType {
	statusTypeNoDifference = 0,
	statusTypeTrackIn      = 1,  // state .. -> 4
	statusTypeTrackOut     = 2   // state .. -> 7
};

#endif // _MT_H_