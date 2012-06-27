#include "testApp.h"

testApp::testApp() :
    poorsignal("Poor Signal", 100, 100, 200, 20, 0, 0, 255),
    power("Poor Signal", 100, 150, 200, 20, 0, 0, 255),
    attention("Poor Signal", 100, 200, 200, 20, 0, 0, 100),
    meditation("Poor Signal", 100, 250, 200, 20, 0, 0, 100),
    blink("Blink", 100, 300, 200, 20, 0, 0, 255)
{
}

//--------------------------------------------------------------
void testApp::setup(){
    tg.addEventListener(this);

}

//--------------------------------------------------------------
void testApp::update(){
    tg.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    poorsignal.draw();
    power.draw();
    attention.draw();
    meditation.draw();
    blink.draw();
    if (tg.isReady)
        ofSetColor(50, 250, 50);
    else
        ofSetColor(250, 50, 50);
    ofRect(10, 10, 30, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

void testApp::onThinkgearReady(ofxThinkgearEventArgs& args){
    cout << "onReady" << endl;
}

void testApp::onThinkgearError(ofMessage& err){
    cout << "onError " << err.message << endl;
}

void testApp::onThinkgearRaw(ofxThinkgearEventArgs& args){
}

void testApp::onThinkgearPower(ofxThinkgearEventArgs& args){
    power.value = args.power;
}

void testApp::onThinkgearPoorSignal(ofxThinkgearEventArgs& args){
    poorsignal.value = args.poorSignal;
}

void testApp::onThinkgearBlinkStrength(ofxThinkgearEventArgs& args){
    blink.value = args.blinkStrength;
}

void testApp::onThinkgearAttention(ofxThinkgearEventArgs& args){
    attention.value = args.attention;
}

void testApp::onThinkgearMeditation(ofxThinkgearEventArgs& args){
    meditation.value = args.meditation;
}

void testApp::onThinkgearEeg(ofxThinkgearEventArgs& args){
}

void testApp::onThinkgearConnecting(ofxThinkgearEventArgs& args){
}
