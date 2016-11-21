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
    
    ofxUISuperCanvas *gui;
    string url;
    ColourSchme colourScheme;
    
    
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    void setGui();
    void setColourScheme();
    
    
   
    
		
};
