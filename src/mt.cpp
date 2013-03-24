#include "testApp.h"
#include "mt.h"

vector <MyFinger> fingers(FINGER_ARR_SIZE);

int mtCallback(int device, Finger *data, int nFingers, double timestamp, int frame) {

	printf("-----mtCallback!----- time:%7.3f, Frame:%6d -----\n", timestamp, frame);
	
	// オブジェクトのクリア
	for (int i=0; i< FINGER_ARR_SIZE; i++) {
		fingers[i].clear();
	}
	// カスタムクラスに詰め直し
	for (int i=0; i< nFingers; i++) {
		Finger *f = &data[i];
		debugPrint(f);

		pack2MyFinger(f, fingers[i]);
	}

	return 0;
}

void debugPrint(Finger* f){
	printf("vel:[%6.3f,%6.3f],"
				 "pos:[%6.3f,%6.3f],"
				 "Angle:%6.2f," 
				 "ellipse:[%6.3f x%6.3f],"
				 "size:%5.3f,"
				 "ID:%2d,"
				 "state:%1d," 
				 "foo:[%2d,%2d]," 
				 "unk:%5.3f" "\n",
				 f->normalized.vel.x, f->normalized.vel.y,
				 f->normalized.pos.x, f->normalized.pos.y,
				 f->angle * 90 / atan2(1,0), // 度数表示
				 f->majorAxis,	      f->minorAxis,
				 f->size, 
				 f->identifier,
				 f->state, 
				 f->foo3, f->foo4,
				 f->unk2);
	return;
}

// ------------------
// 詰め替え処理
// ------------------
void pack2MyFinger(const Finger *f, MyFinger &mf){
	mf = fingers[f->identifier];
	mf.identifier = f->identifier;
	mf.timestamp = f->timestamp;
	mf.vel.x = f->normalized.vel.x;
	mf.vel.y = f->normalized.vel.y;
	mf.pos.x = f->normalized.pos.x;
	mf.pos.y = 1 - f->normalized.pos.y;
	mf.size = f->size;
	mf.isValid = true;
}