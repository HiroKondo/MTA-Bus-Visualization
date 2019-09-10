//
//  BusJourneys.cpp
//  BusRouteVisualization_20190909
//
//  Created by Hiroyuki Kondo on 9/9/19.
//

#include "BusJourneys.hpp"


BusJourneys::BusJourneys(){
    
}


// Import Bus Journey data from the CSV file which is generated with python
// Therefore, the python program should be run before using this program.
void BusJourneys::importBusJourneys(string _busJourneyDataCSV, CityMap _cityMap) {
    
    cout << "==============================================" << endl;
    cout << "Start Importing The Bus Journey Data..." << endl;
    
    ofxCsv csv;
    // Load CSV
    if(csv.load(_busJourneyDataCSV)) {
        cout << "Succeed to load file" << endl;
    }
    
    // Skip the first line(column name)
    for(int i = 1; i < csv.getNumRows(); i++) {
        ofxCsvRow row = csv[i];
        
        //Column 0 - LineName, Column 1 - DirectionName, Column 2- JourneyRef, Column 3- Time, Column 4 - Latitude, Column 5 - Longitude, Column 6 - TimePos
        string journeyRef = row.getString(2);
        string time = row.getString(3);
        float lat = row.getFloat(4);
        float lon = row.getFloat(5);
        int timePos = row.getInt(6);
        journeyData_[journeyRef].addJourneyData(timePos, _cityMap.calcPositionOnMap(lat, lon), ofVec2f(lon, lat));
        journeyData_[journeyRef].setJourneyName(journeyRef);
        
        journeyRefs_.insert(journeyRef);
    }
    
    for(auto str : journeyRefs_){
        journeyData_[str].sortTimeList();
    }
    
    
    cout << "Finish Importing The Bus Journey Data" << endl;
    cout << "==============================================" << endl;
    
}

void BusJourneys::draw(){
    for(auto str : journeyRefs_){
        journeyData_[str].draw();
    }
}

void BusJourneys::draw(int _time){
    for(auto str : journeyRefs_){
        journeyData_[str].draw(_time);
    }
}

void BusJourneys::drawLine(int _from, int _to){
    for(auto str : journeyRefs_){
        journeyData_[str].drawLine(_from, _to);
    }
}

void BusJourneys::drawAllLines(){
    int errCnt = 0;
    for(auto str : journeyRefs_){
        errCnt += journeyData_[str].drawAllLines();
    }
    cout << "The number of Lines which are not drawn is " << errCnt << endl;
}
