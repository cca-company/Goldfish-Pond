//
//  Sprite.cpp
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 24..
//
//

#include "Sprite.h"

Sprite::Sprite(){
    
}

Sprite::~Sprite(){
}

void Sprite::Init(ofPoint pos, int angle, int size){
    SetPos(pos);
    SetAngle(angle);
    SetSize(size);
    mTime = 0;
    mCurAnimation = 0;
}

void Sprite::Draw(){
    
    int curFrame = mTime/5;
    std::vector<int> curAnimation = mAnimateFrame.at(mCurAnimation);
    ofImage* curImg;
    
    if(mTime / 5 >= curAnimation.size()-1){
        curFrame = curAnimation.size()-1;
    }
    ++mTime;
    
    curImg = mFrameList.at(curAnimation[curFrame]);
    
    curImg->resize(mSize, (mSize/(float)curImg->width) * (float)curImg->height);
    ofPushMatrix();
    ofSetColor(255,255,255);
    ofTranslate(mPos.x, mPos.y, 0.0f);
    ofRotate(mAngle+90, 0.0f, 0.0f, 1.0f);
    curImg->draw(0.0f, 0.0f);
    ofPopMatrix();
    
}

void Sprite::AddFrame(char* imgPath){
    ofImage* newImg = new ofImage();
    newImg->loadImage(imgPath);
    newImg->setAnchorPercent(0.5f, 0.5f);
    
    mFrameList.push_back(newImg);
}

void Sprite::Animate(int animateNum){
    mCurAnimation = animateNum;
    mTime = 0;
}

void Sprite::SetAnimateFrame(std::vector<int> animation){
    mAnimateFrame.push_back(animation);
}

void Sprite::SetPos(ofPoint pos){
    mPos = pos;
}

void Sprite::SetAngle(int angle){
    mAngle = angle;
}

void Sprite::SetSize(int size){
    mSize = size;
}

