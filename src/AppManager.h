//
//  AppManager.hpp
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 23..
//
//

#ifndef AppManager_h
#define AppManager_h

#include "ofMain.h"
#include "ofxTuioClient.h"
#include "Wave.h"
#include "Fish.h"


class AppManager{
    
public:
    AppManager();
    ~AppManager();
    
    void Init();
    void Draw();
    void Update();
    
    void TouchScreen(ofPoint pos, int sessionId, int touchNum);
    void AddFish();
    
protected:
    std::vector<Wave*> mWavePool;
    std::vector<Fish*> mFishPool;
    std::map<int,ofPoint> mIdMap;
};

#endif /* Wave_h */
