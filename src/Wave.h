//
//  Wave.h
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 23..
//
//

#ifndef Wave_h
#define Wave_h

#include "Enum.h"
#include "ofMain.h"
#include "ofxTuioClient.h"

enum WaveState{
    WS_NORMAL,
    WS_ANIMATE,
    WS_HIDE,
};

class Wave{
    
public:
    Wave();
    ~Wave();
    
    void Init(ofPoint pos, int sessionId);
    void Remove();
    
    void Draw();
    void Update();
    
    void SetRadius(float radius){ mRadius = radius; }
    void SetSpeed(int speed){ mSpeed = speed; }
    void SetColor(ofColor color){ mColor = color; }
    void SetPos(ofPoint pos){ mPos = pos; }
    void SetState(WaveState state){ mState = state; }
    
    WaveState GetState(){ return mState; }
    float GetTime(){return mTime;}
    float GetId(){return mId;}
    
protected:
    float mRadius;
    float mTime;
    int mId;
    int mSpeed;
    ofColor mColor;
    ofPoint mPos;
    WaveState mState;
};

#endif /* Wave_h */
