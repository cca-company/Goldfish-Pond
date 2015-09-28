#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetVerticalSync(true);
    
    //Connect to Port
    myTuio.connect(3333);
    
    
    //Assign Global TUIO Callback Functions
    ofAddListener(ofEvents().touchDown,this,&ofApp::touchDown);
    ofAddListener(ofEvents().touchUp,this,&ofApp::touchUp);
    ofAddListener(ofEvents().touchMoved,this,&ofApp::touchMoved);
    
    //App manager load
    mAppManager = new AppManager();
    mAppManager->Init();
}

//--------------------------------------------------------------
void ofApp::update(){
    mAppManager->Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //render TUIO Cursors and Objects
    //myTuio.drawCursors();
    //myTuio.drawObjects();
    
    mAppManager->Draw();
    
    /*
    std::list<TuioCursor*> cursorList = myTuio.client->getTuioCursors();
    std::list<TuioCursor*>::iterator tit;
    myTuio.client->lockCursorList();
    for (tit=cursorList.begin(); tit != cursorList.end(); tit++) {
        TuioCursor * cur = (*tit);
        //if(tcur!=0){
        //TuioCursor cur = *tcur;
        glColor3f(1.0,0.0,0.0);
        ofEllipse(cur->getX()*ofGetWidth(), cur->getY()*ofGetHeight(), 20.0, 20.0);
        glColor3f(0.0,0.0,0.0);
        string str = "SessionId: "+ofToString((int)(cur->getSessionID()));
        ofDrawBitmapString(str, cur->getX()*ofGetWidth()-10.0, cur->getY()*ofGetHeight()+25.0);
        str = "CursorId: "+ofToString((int)(cur->getCursorID()));
        ofDrawBitmapString(str, cur->getX()*ofGetWidth()-10.0, cur->getY()*ofGetHeight()+40.0);
        //}
    }
    myTuio.client->unlockCursorList();
    */
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}


void ofApp::touchDown(ofTouchEventArgs & touch){
    
    int cursorID = myTuio.client->getTuioCursor(touch.id)->getCursorID();
    int x = touch.x * ofGetWidth();
    int y = touch.y * ofGetHeight();
    int touchNum = myTuio.client->getTuioCursors().size();
    
    if(touchNum == 3){mAppManager->AddFish();}
    mAppManager->TouchScreen(ofPoint(x,y), cursorID, touchNum);

}

void ofApp::touchUp(ofTouchEventArgs & touch){
    
}

void ofApp::touchMoved(ofTouchEventArgs & touch){
    int cursorID = myTuio.client->getTuioCursor(touch.id)->getCursorID();
    int x = touch.x * ofGetWidth();
    int y = touch.y * ofGetHeight();
    int touchNum = myTuio.client->getTuioCursors().size();
    
    mAppManager->TouchScreen(ofPoint(x,y), cursorID, touchNum);
}

