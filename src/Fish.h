//
//  Fish.hpp
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 23..
//
//

#ifndef Fish_h
#define Fish_h

#include "ofMain.h"
#include "ofxTuioClient.h"
#include "Sprite.h"
#include "enum.h"

enum FishState
{
    FS_NORMAL,
    FS_MOVE,
    FS_HIDE,
};


class Fish{
    
public:
    Fish();
    ~Fish();
    
    void Init();
    void Draw();
    void Move(float angle, int range);
    void MoveToCenter();
    
    void SetPos(ofPoint pos){ mPos = pos; }
    void SetState(FishState state){ mState = state; }
    void SetAngle(float angle){ mAngle = angle;}
    
    ofPoint GetPos(){return mPos;}
    FishState GetState(){return mState;}
    
protected:
    Sprite* mSprite;
    FishState mState;
    ofPoint mPos;
    ofPoint mTarPos;
    float mAngle;
    float mTarAngle;
    float mTime;
    int mMoverange;
};

#endif /* Fish_hpp */
