#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofSetColor(0, 0, 0, 20);
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetBackgroundAuto(false);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    ofSetLineWidth(2);
    ofSetCurveResolution(64);
    angle = TWO_PI/shapeRes;
    //ノイズの引数セット
    for (int i=0; i<shapeRes; i++) {
        noiseArgument[i] = ofRandom(10000);
    }
    //頂点セット
    for (int i=0; i<shapeRes; i++) {
        vertexes[i].set(cos(angle*i) * startRadius, sin(angle*i)*startRadius);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofNoFill();
    ofBeginShape();
    ofSetColor(0, 0, 0, 20);
    for (int i=0; i<shapeRes; i++) {
        ofCurveVertex(vertexes[i].x, vertexes[i].y);
    }
    ofCurveVertex(vertexes[0].x, vertexes[0].y);
    ofCurveVertex(vertexes[1].x, vertexes[1].y);
    ofCurveVertex(vertexes[2].x, vertexes[2].y);
    ofEndShape();
    
    for (int i = 0; i < shapeRes; i++) {
        float length = ofNoise(noiseArgument[i])* deltaLength*2 -deltaLength*1.01;
        vertexes[i].x -= cos(angle*i) * length;
        vertexes[i].y -= sin(angle*i) * length;
        noiseArgument[i] += increase;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        ofImage img;
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        string str = ofToString(ofGetFrameNum());
        str = "star_"+str+".jpg";
        img.save(str);
    }
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
