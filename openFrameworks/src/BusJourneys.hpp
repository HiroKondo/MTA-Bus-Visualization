//
//  BusJourneys.hpp
//  BusRouteVisualization_20190909
//
//  Created by Hiroyuki Kondo on 9/9/19.
//

#ifndef BusJourneys_hpp
#define BusJourneys_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxCsv.h"
#include "Journey.hpp"
#include "CityMap.hpp"


// A Journey Class contains a set of the data about the time and the position of an object.
class BusJourneys{
    
    public:
        BusJourneys();
        void importBusJourneys(string, CityMap);
        void draw();
        void draw(int);
        void drawLine(int, int);
        void drawAllLines();
    
    private:
        map<string, Journey> journeyData_;
        set<string> journeyRefs_;
    
};


#endif /* BusJourneys_hpp */
