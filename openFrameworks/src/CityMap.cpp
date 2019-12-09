//
//  CityMap.cpp
//  BusRouteVisualization_20190909
//
//  Created by Hiroyuki Kondo on 9/9/19.
//


#include "CityMap.hpp"


CityMap::CityMap(){
    
    mapWidth_ = 100;
    mapHeight_ = 100;
    
    upperLeftLatLon_ = ofVec2f(360, -90);
    lowerRightLatLon_ = ofVec2f(-360, 90);
    
}


void CityMap::setMapSize(float _width, float _height){
    mapWidth_ = _width;
    mapHeight_ = _height;
}

// Import the latitude and longitude data of the nodes from the CSV file.
// Then, calculate the x and y coordinate on the map
void CityMap::importNodeData(string _nodeDataCSV){
    cout << "==============================================" << endl;
    cout << "Start Importing The Nodes' Data on The Map" << endl;
    
    ofxCsv csv;
    // Load CSV
    if(csv.load(_nodeDataCSV)) {
        cout << "Succeed to load file" << endl;
    }
    
    // Column 0: id, Column 1: latitude, Column 2: Longitude
    // Skip the first line (Column names, i = 0)
    for(int i = 1; i < csv.getNumRows(); i++) {
        ofxCsvRow row = csv[i];
        float x = ofMap(row.getFloat(2), upperLeftLatLon_.x, lowerRightLatLon_.x, 0, mapWidth_);
        float y = ofMap(row.getFloat(1), upperLeftLatLon_.y, lowerRightLatLon_.y, 0, mapHeight_);
        nodeToPositionMap_[row.getString(0)] = ofVec2f(x, y);
        
        if (x < 1 || y < 1) {
            cout << "i = " << i << ", Place id = " << row.getString(0) << ", x = " << x << ", y = " << y << endl;
        }
        
    }
    
    cout << "Finish Importing The Nodes' Data on The Map" << endl;
    cout << "==============================================" << endl;
    
}

// Import the latitude and the longitude data of the corners of the map
// Then, calculate the x and y coordinate on the map
void CityMap::setMapCornersFromCSV(string _cornerDataCSV){
    
    cout << "==============================================" << endl;
    cout << "Start Importing The Corner Data Data" << endl;
    
    ofxCsv csv;
    // Load CSV
    if(csv.load(_cornerDataCSV)) {
        cout << "Succeed to load file" << endl;
    }
    
    // Column 0: max_lat, Column 1: min_lat, Column 2:max_lon, Column 3: min_lon
    // SKip the first line(i = 0)
    for(int i = 1; i < csv.getNumRows(); i++) {
        ofxCsvRow row = csv[i];
        upperLeftLatLon_.y = row.getFloat(0);   // Latitude -> y
        lowerRightLatLon_.y = row.getFloat(1);
        lowerRightLatLon_.x = row.getFloat(2);  // Longitude -> x
        upperLeftLatLon_.x = row.getFloat(3);
    }
    
    cout << "Finish Importing The Corner Data Data" << endl;
    cout << "UpperLeft = (" << upperLeftLatLon_.x << ", " << upperLeftLatLon_.y << "), LowerRight = (" << lowerRightLatLon_.x << ", " << lowerRightLatLon_.y << ")" << endl;
    cout << "==============================================" << endl;
    
}

// Import the Data about the adjacent nodes of each node
void CityMap::importAdjacentNodeData(string _adjacentNodeDataCSV){
    
    cout << "==============================================" << endl;
    cout << "Start Importing The Data of Adjacent Nodes." << endl;
    
    ofxCsv csv;
    //Load CSV
    if(csv.load(_adjacentNodeDataCSV)) {
        cout << "Succeed to load file" << endl;
    }
    
    // Skip the first line
    for(int i = 1; i < csv.getNumRows(); i++) {
        ofxCsvRow row = csv[i];
        int colNum = (int)row.getNumCols();
        string id = row.getString(0);
        for(int j = 1; j < colNum; j++){
            if(row.getString(j) != "") adjacentNodesMap_[id].emplace_back(row.getString(j));
        }
        nodesID_.insert(id);
    }
    
    cout << "Finish Importing The Data of Adjacent Nodes." << endl;
    cout << "==============================================" << endl;
    
}

// Get the x and y data of the node
ofVec2f CityMap::getNodePosition(string _currentNode){
    return nodeToPositionMap_[_currentNode];
}

ofVec2f CityMap::calcPositionOnMap(float _lat, float _lon){
    
    float x = ofMap(_lon, upperLeftLatLon_.x, lowerRightLatLon_.x, 0, mapWidth_);
    float y = ofMap(_lat, upperLeftLatLon_.y, lowerRightLatLon_.y, 0, mapHeight_);
    
    return ofVec2f(x, y);
    
}


void CityMap::drawLines(){
    ofSetColor(60);
    ofSetLineWidth(0.5);
    
    for(string id : nodesID_){
        for(string adID : adjacentNodesMap_[id]){
            ofVec2f st = getNodePosition(id);
            ofVec2f ed = getNodePosition(adID);
            ofDrawLine(st, ed);
        }
    }
}


