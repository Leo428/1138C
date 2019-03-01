#ifndef COLLECTOR
#define COLLECTOR

#include "main.h"
#include "userincludes/robotstates.hpp"

class Collector {
    public:
        Collector();

        //methods 
        void collectBalls();
        void outBall();
        void stopCollector();

        static okapi::Motor * ballCollector;

    private:
        
};

#endif