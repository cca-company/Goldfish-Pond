//
//  AppManager.cpp
//  goldfish
//
//  Created by CHANT-MAC on 2015. 9. 23..
//
//

#include "AppManager.h"

AppManager::AppManager(){
    
}

AppManager::~AppManager(){
    
}

void AppManager::Init(){
    for(int i = 0; i < 20; ++i){
        Fish* newFish = new Fish();
        mFishPool.push_back(newFish);
    }
}

void AppManager::Draw(){
    for(auto& wave : mWavePool){
        if(wave->GetState() != WS_HIDE){
            wave->Draw();
        }
    }
    
    for(auto& fish : mFishPool){
        if(fish->GetState() != FS_HIDE){
            fish->Draw();
        }
    }
}

void AppManager::Update(){
    for(auto& wave : mWavePool){
        if(wave->GetState() != WS_HIDE){
            wave->Update();
        }
    }
}

void AppManager::AddFish(){
    for(auto& fish : mFishPool){
        if(fish->GetState() == FS_HIDE){
            fish->Init();
            printf("add new fish\n");
            return;
        }
    }
}

void AppManager::TouchScreen(ofPoint pos, int sessionId, int touchNum){
    Wave* newWave = NULL;
    
    auto iter = mIdMap.find(sessionId);
    
    if(iter == mIdMap.end()){
        mIdMap.insert(std::pair<int,ofPoint>(sessionId,pos));
    }else{
        ofPoint prevPos = iter->second;
        if(prevPos.x > pos.x - WAVE_INTERVAL && prevPos.x < pos.x + WAVE_INTERVAL &&
           prevPos.y > pos.y - WAVE_INTERVAL && prevPos.y < pos.y + WAVE_INTERVAL){
            return;
        }
        iter->second = pos;
    }
        
    for(auto& wave : mWavePool){
        if(wave->GetState() == WS_HIDE){
            newWave = wave;
        }
    }
    
    if(newWave == NULL){
        newWave = new Wave();
        mWavePool.push_back(newWave);
    }
    
    newWave->Init(pos,sessionId);
    
    
    for(auto& fish : mFishPool){
        if(fish->GetState() == FS_NORMAL){
            ofPoint fishPos = fish->GetPos();
            float dx = fishPos.x - pos.x;
            float dy = fishPos.y - pos.y;
            float rad = atan2(dy,dx);
            float range =200+(300/(dy/sin(rad)));
            float deg = rad*180/PI;
            
            if(touchNum == 2){
                fish->Move(deg,range);
            }else if(touchNum == 1){
                fish->Move(deg - 180,range);
            }
        }
    }
}

