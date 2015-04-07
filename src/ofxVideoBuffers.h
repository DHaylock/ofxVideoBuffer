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
        void getNewImage(ofPixels pix);
        void getNewImage(ofPixels pix, ofImageType type);

        vector<ofImage> buffer;

        void setFade(bool fade);
        void setFadeAmount(int howManyFramesToFade);

        bool isFinished();
        bool isPlaying();
        bool isNearlyFinished();
        bool isEmpty();

        int getNumberOfFrames();
        int getCurrentFrameNumber();

        void reset();
        void start();
        void stop();
        void clear();

    private:
        bool canFade;
        int fadeAmount;
        int progress;
        bool stillPlaying;
        bool canStartLoop;
        bool hasFinishedPlaying;
};
