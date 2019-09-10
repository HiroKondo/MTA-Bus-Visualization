#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "CityMap.hpp"
#include "BusJourneys.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void importTimeData();
    
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
    
    void drawColorScale();
    
    
    CityMap cityMap;
    
    BusJourneys busJourneys;
    
    string nodeAreaCSV;
    
    string journeyDataCSV;
    
    string timeDataCSV;
    
    
    vector<string> timeLists;
    vector<int> timePosLists;
    
    int counter = 0;
    
    int screenWid = 4000;
    int screenHei = 4000;
    
    ofFbo fbo;
    
    
};
