//--------------------------------------------------------------
//* Name: ofxVideoBuffers.cpp
//* Author: David Haylock
//* Creation Date: 02-10-2014
//--------------------------------------------------------------

#include "ofxVideoBuffers.h"
//--------------------------------------------------------------
ofxVideoBuffers::ofxVideoBuffers()
{
    progress = 0;
    canStartLoop = false;
    hasFinishedPlaying = false;
}
//--------------------------------------------------------------
ofxVideoBuffers::~ofxVideoBuffers()
{
    
}
//--------------------------------------------------------------
void ofxVideoBuffers::getNewImage(ofImage img)
{
    buffer.push_back(img);
}
//--------------------------------------------------------------
void ofxVideoBuffers::getNewImage(ofTexture tex)
{
//    buffer.push_back(img);
}
//--------------------------------------------------------------
void ofxVideoBuffers::getNewImage(ofPixels pix)
{
//    buffer.push_back(img);
}
//--------------------------------------------------------------
void ofxVideoBuffers::update()
{
    if(canStartLoop == true)
    {
        if (!isFinished())
        {
            if(!buffer.empty() && progress <= buffer.size()-1)
            {
                if (ofGetFrameNum() % 1 == 0)
                {
                    progress++;
                }
            }
            if (progress >= buffer.size()-30)
            {
                
            }
        }
        else  {   }
    }
    else  {   }
    
}
//--------------------------------------------------------------
void ofxVideoBuffers::draw(int x,int y,int width,int height)
{
    ofPushStyle();
    if (canStartLoop == true)
    {
        if (!buffer.empty() && buffer.size() >= 30)
        {
            if (progress <= 60)
            {
                ofSetColor(255,ofMap(progress, 0, 60, 0, 255));
            }
            else if (progress >= 60 && progress <= buffer.size()-30)
            {
                ofSetColor(255,255);
            }
            else if (progress >= buffer.size()-30)
            {
                ofSetColor(255,ofMap(progress, buffer.size()-30, buffer.size()-1, 255, 0));
            }
            
            // Here is the main drawing bit
            buffer[progress].draw(x, y, width, height);
        }
    }
    else  {   }
    ofPopStyle();
}
//--------------------------------------------------------------
void ofxVideoBuffers::drawFullscreen()
{
    ofPushStyle();
    if (canStartLoop == true)
    {
        if (!buffer.empty() && buffer.size() >= 30)
        {
            if (progress <= 60)
            {
                ofSetColor(255,ofMap(progress, 0, 60, 0, 255));
            }
            else if (progress >= 60 && progress <= buffer.size()-30)
            {
                ofSetColor(255,255);
            }
            else if (progress >= buffer.size()-30)
            {
                ofSetColor(255,ofMap(progress, buffer.size()-30, buffer.size()-1, 255, 0));
            }
            // Here is the main drawing bit
            buffer[progress].draw(0,0, ofGetWidth(), ofGetHeight());
        }
    }
    else {   }
    ofPopStyle();
}
//--------------------------------------------------------------
void ofxVideoBuffers::drawMini(int x, int y)
{
    ofPushStyle();
    ofFill();
    if (!buffer.empty())
    {
        if (progress <= 60)
        {
            ofSetColor(255,ofMap(progress, 0, 60, 0, 255));
        }
        else if (progress >= 60 && progress <= buffer.size()-30)
        {
            ofSetColor(255,255);
        }
        else if (progress >= buffer.size()-30)
        {
            ofSetColor(255,ofMap(progress, buffer.size()-30, buffer.size()-1, 255, 0));
        }
        buffer[progress].draw(x, y,320/4,240/4);
    }
    
    ofDrawBitmapStringHighlight(ofToString(progress), x, y);
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofRect(x, y, 320/4,240/4);
    ofPopStyle();
    
}
//--------------------------------------------------------------
void ofxVideoBuffers::start()
{
    stillPlaying = true;
    canStartLoop = true;
}
//--------------------------------------------------------------
void ofxVideoBuffers::reset()
{
    progress = 0;
    stillPlaying = true;
    canStartLoop = true;
}
//--------------------------------------------------------------
void ofxVideoBuffers::stop()
{
    stillPlaying = false;
    canStartLoop = false;
}
//--------------------------------------------------------------
bool ofxVideoBuffers::isFinished()
{
    if (progress >= buffer.size()-1 && canStartLoop == true)
    {
        stop();
        return true;
    }
    else
    {
        return false;
    }
}
//--------------------------------------------------------------
bool ofxVideoBuffers::isNearlyFinished()
{
    if (progress >= buffer.size()-30)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//--------------------------------------------------------------
bool ofxVideoBuffers::isPlaying()
{
    return stillPlaying;
}
//--------------------------------------------------------------
int ofxVideoBuffers::getNumberOfFrames()
{
    if (!buffer.empty())
    {
        return buffer.size();
    }
    else
    {
        return 0;
    }
}
//--------------------------------------------------------------
void ofxVideoBuffers::clear()
{
    buffer.clear();
}