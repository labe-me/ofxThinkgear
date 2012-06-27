#pragma once

#include "ofMain.h"
#include "ofxThinkgear.h"


class Line {
public:
    string label;
    float x;
    float y;
    float width;
    float height;
    float value;
    float minValue;
    float maxValue;

    Line(float x_, float y_, float w_, float h_, float v_, float mv_) :
        label("none"), x(x_), y(y_), width(w_), height(h_), value(v_), maxValue(mv_), minValue(0) {
    }

    Line(string l, float x_, float y_, float w_, float h_, float v_, float mv_) :
        label(l), x(x_), y(y_), width(w_), height(h_), value(v_), maxValue(mv_), minValue(0) {
    }

    Line(string l, float x_, float y_, float w_, float h_, float v_, float mmv, float mv_) :
        label(l), x(x_), y(y_), width(w_), height(h_), value(v_), minValue(0), maxValue(mv_) {
    }

    void draw(){
        ofPushStyle();
        ofSetColor(250, 250, 250, 100);
        ofRect(x, y, width, height);
        ofSetColor(100, 100, 200);
        ofRect(x, y, ((value-minValue)/(maxValue-minValue))*width, height);
        ofPopStyle();
    }
};

class testApp : public ofBaseApp {

	public:
        testApp();
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        void onThinkgearError(ofMessage& err);
		void onThinkgearReady(ofxThinkgearEventArgs& args);
        void onThinkgearRaw(ofxThinkgearEventArgs& args);
        void onThinkgearPower(ofxThinkgearEventArgs& args);
        void onThinkgearPoorSignal(ofxThinkgearEventArgs& args);
        void onThinkgearBlinkStrength(ofxThinkgearEventArgs& args);
        void onThinkgearAttention(ofxThinkgearEventArgs& args);
        void onThinkgearMeditation(ofxThinkgearEventArgs& args);
        void onThinkgearEeg(ofxThinkgearEventArgs& args);
        void onThinkgearConnecting(ofxThinkgearEventArgs& args);


    private:
        Line poorsignal;
        Line power;
        Line attention;
        Line meditation;
        Line blink;

        ofxThinkgear tg;
        ofxThinkgearEventArgs data;
};
