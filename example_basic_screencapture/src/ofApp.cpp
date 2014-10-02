#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetWindowShape(WIDTH*2, HEIGHT+40);

    fbo.allocate(WIDTH,HEIGHT,GL_RGBA);
    
    fbo.begin();
    ofClear(0, 0, 0);
    fbo.end();
    
    record = false;
    playback = false;
}
//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle("ofxVideoBuffer Basic Example FPS: " +ofToString((int)(ofGetFrameRate())));
    
    // Frame buffer to grab images could use ofTexture to grab screen data will implement later
    fbo.begin();
    ofClear(0);
    ofSetColor(255, 255, 255);
    ofCircle(mouseX, mouseY, 10);
    fbo.end();
    fbo.readToPixels(pixs);
    
    if (record)
    {
        buffer.getNewImage(pixs);
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
    
    ofSetColor(255);
    fbo.draw(0,0);
    
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
void ofApp::mouseMoved(int x, int y )
{

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
