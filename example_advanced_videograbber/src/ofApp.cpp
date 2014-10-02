#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetWindowShape(WIDTH*2, HEIGHT+40);
    
    // Standard Video Grabber Stuff
	videoGrabber.setDesiredFrameRate(60);
	videoGrabber.initGrabber(WIDTH,HEIGHT);
    
    record = false;
    playback = false;
}
//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle("ofxVideoBuffer Basic Video Grabber FPS: " +ofToString((int)(ofGetFrameRate())));
    
    if (buffers.size() >= 5)
    {
        buffers.pop_back();
    }
    
    videoGrabber.update();
    
    // When recording starts grab new images
    if (record)
    {
        buffer.getNewImage(videoGrabber.getPixelsRef());
    }
    // When finished recording and Buffer size is greater the 30 frames
    else if (!record && buffer.getNumberOfFrames() > 30)
    {
        buffers.push_front(buffer);
        // Clear the single buffer object
        buffer.clear();
    }
    else  {   }
    // Keep the Buffers looping
    if (!buffers.empty())
    {
        for (int i = 0; i < buffers.size(); i++)
        {
            if (buffers[i].isFinished())
            {
                buffers[i].reset();
            }
        }
    }
    // Update all the Buffers
    if (!buffers.empty())
    {
        for(int i = 0; i < buffers.size(); i++)
        {
            buffers[i].update();
        }
    }
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(50);
    
    // Draw the Live View
    ofSetColor(255);
    videoGrabber.draw(0,0);
    
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    // Draw the Buffer
    if (!buffers.empty())
    {
        for(int i = 0; i < buffers.size(); i++)
        {
            buffers[i].draw(WIDTH, 0, WIDTH, HEIGHT);
        }
    }
    ofDisableBlendMode();
    
    if(record)
    {
        ofSetColor(255, 0, 0);
        ofCircle(10, 12, 5);
    }
    
    if (playback)
    {
        ofSetColor(0, 255, 0);
        ofCircle(WIDTH+10, 12, 5);
    }
    
    // Info
    ofDrawBitmapStringHighlight("Number of Buffers: " +ofToString(buffers.size()), 10,250);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'r':
            record = !record;
            break;
        case 'p':
            playback = true;

            if (!buffers.empty())
            {
                for(int i = 0; i < buffers.size(); i++)
                {
                    buffers[i].reset();
                    buffers[i].start();
                }
            }
            break;
        case 'c':
            if (!buffers.empty())
            {
                for(int i = 0; i < buffers.size(); i++)
                {
                    buffers[i].clear();
                }
            }
            break;
        case 'f':
            
            if (!buffers.empty())
            {
                for(int i = 0; i < buffers.size(); i++)
                {
                    buffers[i].setFade(false);
                }
            }
            break;
        case 'F':
            if (!buffers.empty())
            {
                for(int i = 0; i < buffers.size(); i++)
                {
                    buffers[i].setFade(true);
                }
            }
            break;
        case 's':
            if (!buffers.empty())
            {
                for(int i = 0; i < buffers.size(); i++)
                {
                    buffers[i].stop();
                }
            }
            break;
        default:
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
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

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
