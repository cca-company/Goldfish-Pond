//
//  Sprite.hpp
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 24..
//
//

#ifndef Sprite_h
#define Sprite_h

#include "ofMain.h"
#include "ofxTuioClient.h"

class Sprite{
    
public:
    Sprite();
    ~Sprite();
    
    void Init(ofPoint pos, int angle, int size);
    void AddFrame(char* imgPath);
    void Animate(int animateNum);
    void Draw();
    
    void SetAnimateFrame(std::vector<int> animation);
    void SetPos(ofPoint pos);
    void SetAngle(int angle);
    void SetSize(int size);
    
protected:
    std::vector<ofImage*> mFrameList;
    std::vector<std::vector<int> > mAnimateFrame;
    ofPoint mPos;
    float mAngle;
    int mCurAnimation;
    int mTime;
    int mSize;
};


#endif /* Sprite_h */
