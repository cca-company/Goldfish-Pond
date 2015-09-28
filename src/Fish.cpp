//
//  Fish.cpp
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 23..
//
//

#include "Fish.h"
#include "iterator"

Fish::Fish(){
    mSprite = new Sprite();
    mSprite->Init(mPos,mAngle,100);
    
    for(int i = 1; i <= 5; ++i){
        char filePath[25];
        sprintf(filePath, "fish_sprite%d.png", i);
        mSprite->AddFrame(filePath);
    }
    
    std::vector<int> animateFrame;
    animateFrame.push_back(0);
    mSprite->SetAnimateFrame(animateFrame);
    
    int frame[17] = {0,1,2,1,0,3,4,3,0,1,2,1,0,3,4,3,0};
    std::vector<int> animateFrame2(frame,frame+17);
    mSprite->SetAnimateFrame(animateFrame2);
    
    int frame2[17] = {0,1,0,3,0};
    std::vector<int> animateFrame3(frame2,frame2+5);
    mSprite->SetAnimateFrame(animateFrame3);
    
    mState = FS_HIDE;
}

Fish::~Fish(){
    free(mSprite);
}

void Fish::Init(){
    
    int x = rand() % ofGetWidth();
    int y = rand() % ofGetHeight();
    int randNum = rand()%4;
    switch(randNum){
        case 0:
            x = -100;
            break;
        case 1:
            x = ofGetWidth()+100;
            break;
        case 2:
            y = -100;
            break;
        case 3:
            y = ofGetHeight()+100;
            break;
    }
    
    mPos = ofPoint(x,y);
    mAngle = 0.0f;
    mTime = 0.0f;
    
    MoveToCenter();

}


void Fish::Draw(){
    mTime += 1.0f;
    float t = mTime / (FISH_ANIMATE_SPEED * 60.0f);
    float x,y;
    
    if(mTime <= FISH_ANIMATE_SPEED * 60.0f){
        
        x = -(mMoverange * cos(mAngle * PI/180)) * t * (t-2.0f) + mTarPos.x;
        y = -(mMoverange * sin(mAngle * PI/180)) * t * (t-2.0f) + mTarPos.y;
        mPos = ofPoint(x,y);

    }else{
        
        SetState(FS_NORMAL);
        float x = (0.5 * cos(mAngle * PI/180))+ mPos.x;
        float y = (0.5 * sin(mAngle * PI/180))+ mPos.y;
        mPos = ofPoint(x,y);
        
        if(rand()%100 == 1){
            mAngle += rand()%90 - 45;
            mSprite->Animate(2);
        }
        
    }
    
    mSprite->SetAngle(mAngle);
    mSprite->SetPos(mPos);
    mSprite->Draw();
}

void Fish::Move(float angle, int range){
    mSprite->Animate(1);
    mAngle = angle;
    mMoverange = range;
    mTarPos = mPos;
    mTime = 0.0f;
    SetState(FS_MOVE);
}

void Fish::MoveToCenter(){
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    
    float dx = mPos.x - centerX;
    float dy = mPos.y - centerY;
    
    float rad = atan2f(dy,dx);
    float range = 200;
    Move(rad*180/PI - 180, range);
}