//
//  Wave.cpp
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 23..
//
//

#include "Wave.h"

Wave::Wave(){
}

Wave::~Wave(){
    
}

void Wave::Init(ofPoint pos, int sessionId){
    mPos = pos;
    mId = sessionId;
    mState = WS_NORMAL;
    mColor = ofColor(WAVE_COLOR_RED,WAVE_COLOR_BLUE,WAVE_COLOR_GREEN);
    mRadius = 0;
    mSpeed = 1;
    mTime = 0;
}

void Wave::Remove(){
    mRadius = 0;
    mColor = ofColor(255,255,255);
    mPos = ofPoint(-1000,-1000);
    mState = WS_HIDE;
}

void Wave::Draw(){
    ofSetColor(mColor);
    ofNoFill();
    ofCircle(mPos.x,mPos.y,mRadius);
}

void Wave::Update(){
    if(mState != WS_HIDE && mTime <= (WAVE_ANIMATE_SPEED * 60.0f)){
        mTime += 1.0f;
        float t = mTime / (WAVE_ANIMATE_SPEED * 60.0f);
        float radius = (-MAX_WAVE_RADIUS) * t * (t-2.0f);
        
        int colorR = WAVE_COLOR_RED + t * (254-WAVE_COLOR_RED);
        int colorG = WAVE_COLOR_BLUE + t * (254-WAVE_COLOR_BLUE);
        int colorB = WAVE_COLOR_GREEN + t * (254-WAVE_COLOR_GREEN);
        
        SetColor(ofColor(colorR,colorG,colorB));
        SetRadius(radius);
    }else{
        Remove();
    }
}