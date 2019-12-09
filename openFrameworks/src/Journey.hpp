//
//  Journey.hpp
//  BusRouteVisualization_20190909
//
//  Created by Hiroyuki Kondo on 9/9/19.
//

#ifndef Journey_hpp
#define Journey_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxCsv.h"


// A Journey Class contains a set of the data about the time and the position of an object.
class Journey{
    
    public:
        Journey();
    
        void sortTimeList();
    
        void draw(int);
        void draw();
        void drawLine(int, int);
        int drawAllLines();
    
        void addJourneyData(int, ofVec2f, ofVec2f);
        void setJourneyName(string);
    

    private:
        string journeyName_; // The name of the Journey
    
        map<int, ofVec2f> timeToPositionMap_;     // To search the position from the time
    
        map<int, ofVec2f> timeToLonLat_;
    
        vector<int> timePosList_;
    
        ofColor circleColor_;   //Color of the circle which is draw on the map
    
        float circleSize_;  //Size of the circle which is draw on the map
    
        int lineWid_;
    
        double areaLenKm_;
    
        int maxVel_;
    
    
};

#endif /* Journey_hpp */
