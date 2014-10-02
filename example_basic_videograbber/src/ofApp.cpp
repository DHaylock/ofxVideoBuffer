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

    videoGrabber.update();
    
    if (record)
    {
        buffer.getNewImage(videoGrabber.getPixelsRef());
    }
    else  {   }
    
    if (buffer.isFinished())
    {
        playback = false;
    }
    
    // Update the buffer
    if (!buffer.isEmpty())
    {
        buffer.update();
    }
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(50);
    
    // Draw the Live View
    ofSetColor(255);
    videoGrabber.draw(0,0);
    
    // Draw the Buffer
    if (!buffer.isEmpty())
    {
        buffer.draw(WIDTH, 0, WIDTH, HEIGHT);
    }
    
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
    ofDrawBitmapStringHighlight("Recorded Frames: " +ofToString(buffer.getNumberOfFrames()), 10,250);
    ofDrawBitmapStringHighlight("Current Frame Number: "+ofToString(buffer.getCurrentFrameNumber()), WIDTH+10,250);
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
            buffer.reset();
            buffer.start();
            break;
        case 'c':
            buffer.clear();
            break;
        case 'f':
            buffer.setFade(false);
            break;
        case 'F':
            buffer.setFade(true);
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
