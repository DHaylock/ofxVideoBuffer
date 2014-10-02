#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(WIDTH*2, HEIGHT+20);
    fbo.allocate(WIDTH,HEIGHT,GL_RGBA);
    pixels = new unsigned char [WIDTH*HEIGHT*4];
    
    fbo.begin();
        ofClear(0, 0, 0);
    fbo.end();
    record = false;
    playback = false;
}
//--------------------------------------------------------------
void ofApp::update()
{

    fbo.begin();
    ofClear(0);
    ofSetColor(255, 255, 255);
    ofCircle(mouseX, mouseY, 10);
    glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    fbo.end();
    
    if (record)
    {
        pixs.setFromPixels(pixels, WIDTH, HEIGHT, OF_IMAGE_COLOR_ALPHA);
        buffer.getNewImage(pixs);
    }
    else  {   }

    
    // Update the buffer progressors
    if (!buffer.isEmpty())
    {
        buffer.update();
    }
}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(ofColor::gray);
    ofSetColor(255);
    fbo.draw(0,0);
    // Update the buffer progressors
    if (!buffer.isEmpty())
    {
        buffer.draw(WIDTH, 0, WIDTH, HEIGHT);
    }
    if(record)
    {
        ofSetColor(255, 0, 0);
        ofCircle(10, 10, 3);
        ofDrawBitmapStringHighlight("Recorded Frames: " +ofToString(buffer.getNumberOfFrames()), 10,245);
    }
    if (playback)
    {
        ofSetColor(0, 255, 0);
        ofCircle(WIDTH+10, 10, 3);
        ofDrawBitmapStringHighlight("Current Frame Number: "+ofToString(buffer.getCurrentFrameNumber()), WIDTH+10,245);
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'r':
            record = !record;
            break;
        case 'p':
            playback = !playback;
            buffer.reset();
            buffer.start();
            break;
        case 'c':
            buffer.clear();
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
