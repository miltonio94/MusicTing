#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    urlContIndx = 0;
    count = 0;
    
    //UI Stuff
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    setColourScheme();
    ofBackground(colourScheme.colour4['r'],
                 colourScheme.colour4['g'],
                 colourScheme.colour4['b']);
    setGui();
    
    //lettering
    font.load("Raleway-Medium.ttf", 30);
    siteFont.load("Raleway-Medium.ttf", 8);
    
    //Sound stuff
    sampleRate = 44100;
    bufferSize = 1024;
    phase = 0;
    

    ofSoundStreamSetup(2,0,this,sampleRate, bufferSize,4);

    ofSoundStreamSetup(1,0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(isUrlNotEmpty()){
        resp = ofLoadURL( "http://" + url);
        urlCont = resp.data;
    }
    
    
    
//    if((ofGetElapsedTimeMillis() % 1000) == 0){
////        freq = freq * 2;
//        phase += 0.05;
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui->draw();
    if(isContNotEmpty()){
        ofSetColor(colourScheme.colour3['r'],
                   colourScheme.colour3['g'],
                   colourScheme.colour3['b']);

        siteFont.drawString(urlCont, 10, 5);
    }
    if(url.length() > 0){
        ofSetColor(colourScheme.colour1['r'],
                   colourScheme.colour1['g'],
                   colourScheme.colour1['b']);
//
        font.drawString(url, 10, 500);
    }
    font.drawString(to_string(phase), 100, 500);
//    ofDrawBitmapString(urlCont, 10, 100);
//    font.drawString(urlCont, 10, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

//--------------------------------------------------------------
void ofApp::exit(){
    gui->saveSettings("settings.xml");
    delete gui;
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e){
    if(e.getName() == "URL"){
        ofxUITextInput *urlIn = (ofxUITextInput *) e.widget;
        if(urlIn->getInputTriggerType() == OFX_UI_TEXTINPUT_ON_ENTER){
            url = urlIn->getTextString();
        }
    }
}

//--------------------------------------------------------------
void ofApp::setGui(){
    gui = new ofxUISuperCanvas("");
//    gui->setRetinaResolution();
    gui->setFont("Raleway-Medium.ttf");
    
    
    //setting UI's background colour
    gui->setColorBack(ofColor(colourScheme.colour1['r'],
                              colourScheme.colour1['g'],
                              colourScheme.colour1['b']));
    
//    adding ui elements
    gui->addSpacer();
    gui->addLabel("Enter URL");
    gui->addTextInput("URL", "");
    
    // styling ui
    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_BACK, ofColor(colourScheme.colour2['r'],
                                                          colourScheme.colour2['g'],
                                                          colourScheme.colour2['b']));
//    gui->setWidgetColor(OFX_UI_WIDGET_COLOR_OUTLINE, ofColor(colourScheme.colour3['r'],
//                                                             colourScheme.colour3['g'],
//                                                             colourScheme.colour3['b']));
    gui->autoSizeToFitWidgets();
    
    // event listener
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");
}


//--------------------------------------------------------------
void ofApp::setColourScheme(){
    colourScheme = {
        {{'r', 252},{'g', 238},{'b', 224}},
        {{'r', 254},{'g', 217},{'b', 180}},
        {{'r', 217},{'g', 168},{'b', 132}},
        {{'r', 159},{'g', 192},{'b', 203}},
        {{'r', 86},{'g', 138},{'b', 154}}
    };
}

//--------------------------------------------------------------
void ofApp::audioOut(float* output, int bufferSize, int nChannels){
    for(int i = 0; i< bufferSize; i++){
        
        float sample = sin(phase);
        output[i] = sample;
        output[i+1] = sample;
        
        if((count % 10000) == 0){
            //        freq = freq * 2;
            phase += phase;
        }
//        phase += 0.05;
        count++;
        
    }
}

//--------------------------------------------------------------
//float ofApp::makeSound(int i){
//    return i * 1.1;
//}

//--------------------------------------------------------------
void ofApp::setSounds(){
    for (int i = 33; i < 127; i++) {
        updateWaveForm(120, sounds[(char) i]);
    }

}

//--------------------------------------------------------------
void ofApp::updateWaveForm(int WaveResolution, vector<float> &waveform){
    waveform.resize(WaveResolution); // resizing the vector to whatever the reselotion is (how many element in the lookup table
    waveLine.clear(); // clearing the wave lines
    
    // "waveformStep" maps a full oscillation of sin() to the size
    // of the waveform lookup table
    waveformStep = (M_PI * 2.0) / (float) waveform.size();
    
    for(int i = 0; i < waveform.size(); i++) {
        waveform[i] = sin(i * waveformStep); // stepping through the look up table and adding elements
    }
}

bool ofApp::isContNotEmpty(){
    if(urlCont.length() > 0){
        return true;
    }
    return false;
}

bool ofApp::isUrlNotEmpty(){
    if(url.length() > 0){
        return true;
    }
    return false;
}
