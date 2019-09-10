#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(300);
    ofSetCurveResolution(300);
    
    
    nodeAreaCSV = "Map_area_20190908.csv";
    
    journeyDataCSV = "Journey_s_07-30-00_e_09-30-00_normProg_for_vis_from_pandas.csv";
    
    timeDataCSV = "timeLists.csv";
    
    // Set the size of the map.
    // This funstion must be called at the beginning.
    cityMap.setMapSize(screenWid, screenHei);
    
    // Import the latitude and the longitude data of the corners of the map
    cityMap.setMapCornersFromCSV(nodeAreaCSV);
    
    // Import Bus data
    busJourneys.importBusJourneys(journeyDataCSV,cityMap);
    
    fbo.allocate(screenWid, screenHei, GL_RGB);
    
    ofBackground(230);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    fbo.begin();
    
    ofClear(255);
    
    ofBackground(255);
    
    busJourneys.drawAllLines();
    
    drawColorScale();
    
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    
}


void ofApp::importTimeData(){
    cout << "==============================================" << endl;
    cout << "Start Importing The Time Data" << endl;
    
    ofxCsv csv;
    // Load CSV
    if(csv.load(timeDataCSV)) {
        cout << "Succeed to load file" << endl;
    }
    
    // Column 0 - Time (yyyy-mm-dd h:m:s), Column 1: Seconds from 2019-02-12 07:00:00
    // Skip the first line (column names)
    for(int i = 1; i < csv.getNumRows(); i++) {
        ofxCsvRow row = csv[i];
        timeLists.push_back(row.getString(0));
        timePosLists.push_back(row.getInt(1));
    }
    
    cout << "Finish Importing The Time Data" << endl;
    cout << "==============================================" << endl;
    
}

void ofApp::drawColorScale(){
    int length = screenWid/4;
    
    for(int i = 0; i < length; i++){
        double H = ofMap(i, 0, length, 200, 0);
        ofColor c = ofColor::fromHsb(H, 200, 150, 150);
        ofSetColor(c);
        ofVec2f topLeft = ofVec2f(2750, 3700);
        int height = 50;
        ofDrawRectangle(topLeft.x + i, topLeft.y, 1, height);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    ofImage img;
    ofPixels pixels;
    if(key =='s'){
        fbo.readToPixels(pixels);
        img.setFromPixels(pixels);
        char fileNameStr[255];
        string date = ofGetTimestampString();
        sprintf(fileNameStr, "image/%s.png", date.c_str());
        img.save(fileNameStr,OF_IMAGE_QUALITY_BEST);
    }
    
    cout << "Finish Saving a png folder..." << endl;
    cout << "Exit the program" << endl;
    ofExit();
    
    
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
