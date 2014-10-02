//--------------------------------------------------------------
//* Name: ofxVideoBuffers.h
//* Author: David Haylock
//* Creation Date: 02-10-2014
//--------------------------------------------------------------

#include <iostream>
#include "ofMain.h"

class ofxVideoBuffers {
    
    public:
        ofxVideoBuffers();
        ~ofxVideoBuffers();
        void update();
        void drawFullscreen();
        void draw(int x,int y,int width,int height);
        void drawMini(int x, int y);
    
        void getNewImage(ofImage img);
        void getNewImage(ofTexture tex);
        void getNewImage(ofPixels pix);
    
        vector<ofImage> buffer;
//        vector<ofTexture> buffer;
//        vector<ofPixels> buffer;
    
        bool isFinished();
        bool isPlaying();
        bool isNearlyFinished();
        bool isEmpty();
        void reset();
        void start();
        void stop();
        void clear();
        int getNumberOfFrames();
        int getCurrentFrameNumber();
    
    private:
        int progress;
        int drawPathCounter;
        bool stillPlaying;
        bool canStartLoop;
        bool hasFinishedPlaying;
};