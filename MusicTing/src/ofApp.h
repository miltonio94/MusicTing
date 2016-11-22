#pragma once

#include "ofMain.h"
#include "ofxUi.h"
#include "ofxMaxim.h"
#include "ColourSchme.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void audioOut(float* output, int bufferSize, int nChannels);
    
    string url;
    string urlCont;
    unsigned int urlContIndx;
    unsigned int count;
    
    ofxUISuperCanvas *gui;
    ColourSchme colourScheme;
    ofTrueTypeFont font;
    ofTrueTypeFont siteFont;
    ofHttpResponse resp;
    
    
    bool isContNotEmpty();
    bool isUrlNotEmpty();
    
    
    // sound stuff
//    maxiOsc osc;
    map<char, vector<float>> sounds;
    double phase,
           currenttSample;
    float freq;
    unsigned bufferSize,
             sampleRate;
    ofMutex waveFormMutex;
    ofPolyline waveLine,
               outline;
    float waveformStep;
    
//    float makeSound(int i);
    void setSounds();
    void updateWaveForm(int WaveResolution, vector<float> &vec);
    
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    void setGui();
    void setColourScheme();
    
    
    
   
    
		
};
