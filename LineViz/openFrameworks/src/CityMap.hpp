//
//  CityMap.hpp
//  BusRouteVisualization_20190909
//
//  Created by Hiroyuki Kondo on 9/9/19.
//

#ifndef CityMap_hpp
#define CityMap_hpp

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include "ofMain.h"
#include "ofxCsv.h"

using namespace std;

class CityMap{
    
    public:
        CityMap();
        void setMapSize(float, float);
        void importNodeData(string);
        void setMapCornersFromCSV(string);
        void importAdjacentNodeData(string);
        ofVec2f getNodePosition(string);
        ofVec2f calcPositionOnMap(float, float);
        
        void drawLines();
        
    private:
        float mapWidth_;
        float mapHeight_;
        
        ofVec2f upperLeftLatLon_;
        ofVec2f lowerRightLatLon_;
        
        // The list of the nodes on the map
        set<string> nodesID_;
        
        // Hashmap to get the x and y coordinate data from the node ID.
        map<string, ofVec2f> nodeToPositionMap_;
        
        // Hashmap to get the adjacent nodes of a node from its ID.
        map<string, vector<string>> adjacentNodesMap_;
    
};


#endif /* CityMap_hpp */
