#ifndef NUC_LAUNCHER
#define NUC_LAUNCHER

#include "main.h"
#include "userincludes/robotstates.hpp"

class NucLauncher {
    public:
        NucLauncher();

        //methods 
        void punchIT();
        void stopPunchers();
        //vars 
        static okapi::Motor * puncher_1_Motor;
        static okapi::Motor * puncher_2_Motor;


    private:
        //vars 

        //methods
        void initMotors();
};

#endif