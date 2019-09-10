//
//  Journey.cpp
//  BusRouteVisualization_20190909
//
//  Created by Hiroyuki Kondo on 9/9/19.
//

#include "Journey.hpp"


Journey::Journey(){
    journeyName_ = "";
    
    circleColor_ = ofColor(0, 0, 0, 50);
    
    circleSize_ = 4;
    
    lineWid_ = 5;
    
    areaLenKm_ = 47.8;
    
    maxVel_ = 120;
    
}


void Journey::sortTimeList(){
    sort(timePosList_.begin(), timePosList_.end());
}

void Journey::draw(int _time){
    ofVec2f curPos = timeToPositionMap_[_time];
    ofSetColor(circleColor_);
    ofDrawEllipse(curPos.x, curPos.y, circleSize_, circleSize_);
}


void Journey::draw(){
    for(auto t : timeToPositionMap_){
        ofVec2f curPos = t.second;
        ofSetColor(circleColor_);
        ofDrawEllipse(curPos.x, curPos.y, circleSize_, circleSize_);
    }
}


void Journey::drawLine(int _from, int _to){
    bool flag = true;
    for(int i = 0; i < timePosList_.size()-1; i++){
        if(timePosList_[i] < _to && _to < timePosList_[i+1]){
            ofVec2f prevPos = timeToPositionMap_[timePosList_[i]];
            ofVec2f curPos = timeToPositionMap_[timePosList_[i+1]];
            float dist = curPos.distance(prevPos);
            
            int timeDif = timePosList_[i+1] - timePosList_[i];
            if(timeDif > 240) continue;
            
            float distKm = dist*areaLenKm_/4000;
            float vel = distKm * 3600 / (float)timeDif;
            
            
            if(vel > maxVel_) {
                if(flag) cout << journeyName_ << endl;
                cout << "ti=" << timePosList_[i] << ", ti+1=" << timePosList_[i+1] << ", tdif=" << timeDif << ", min velocity=" << vel << endl;
                continue;
            }
            
            float alpha = ofMap(timeDif, 120, 240, 100, 5);
            if(alpha < 5) alpha = 5;
            
            int hue = (int)ofMap(distKm, 0, 2.5, 200, 10);
            if(hue < 0) hue = 0;
            
            int sat = 200;
            int val = 150;
            
            ofColor c = ofColor::fromHsb(hue, sat, val, alpha);
            ofSetColor(c);
            ofSetLineWidth(lineWid_);
            ofDrawLine(prevPos, curPos);
        }
    }
    
}


int Journey::drawAllLines(){
    int errorCnt = 0;
    bool flag = true;
    for(int i = 0; i < timePosList_.size()-1; i++){
        ofVec2f prevPos = timeToPositionMap_[timePosList_[i]];
        ofVec2f curPos = timeToPositionMap_[timePosList_[i+1]];
        float dist = curPos.distance(prevPos);
        
        int timeDif = timePosList_[i+1] - timePosList_[i];
        if(timeDif > 240) continue;
        
        float distKm = dist*areaLenKm_/4000;
        float vel = distKm * 3600 / (float)timeDif;
        
        
        if(vel > maxVel_) {
            if(flag) cout << journeyName_ << endl;
            cout << "ti=" << timePosList_[i] << ", ti+1=" << timePosList_[i+1] << ", tdif=" << timeDif << ", min velocity=" << vel << endl;
            errorCnt++;
            continue;
        }
        
        float alpha = ofMap(timeDif, 120, 240, 100, 5);
        if(alpha < 5) alpha = 5;
        
        int hue = (int)ofMap(distKm, 0, 2.5, 200, 10);
        if(hue < 0) hue = 0;
        
        int sat = 200;
        int val = 150;
        
        ofColor c = ofColor::fromHsb(hue, sat, val, alpha);
        ofSetColor(c);
        ofSetLineWidth(lineWid_);
        ofDrawLine(prevPos, curPos);
    }
    
    return errorCnt;
}


void Journey::addJourneyData(int _timePos, ofVec2f _position){
    timeToPositionMap_[_timePos] = _position;
    timePosList_.push_back(_timePos);
}

void Journey::setJourneyName(string _name){
    journeyName_ = _name;
}
