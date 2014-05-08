#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxHeadPoseEstimator.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 12345


/*
 HeadClient
 ----------
 
 Using Kyle McDonald's and Gabriele Fanelli's code we estimate the head position.
 See http://github.com/kylemcdonald/ofxHeadPoseEstimator for their code.
 
 We then transmit that information over OSC to the motors controlling the doll.
 
 */



class HeadClient : public ofBaseApp {
    
public:
    void setup();
    void update();
    void updateCloud();
    void draw();
    
    void setupEstimator();
    
    void drawPointCloud();
    void drawPoses();
    void drawHead();
    
    void calcAvgFPS();
    void drawReport();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxKinect kinect;
    ofEasyCam easyCam;
    
    ofxOscSender sender;
    
    void transmitPoses();
    
};
