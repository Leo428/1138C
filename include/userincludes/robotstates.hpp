#ifndef ROBOT_STATES
#define ROBOT_STATES

class RobotStates {
    public: 
        RobotStates();

        static RobotStates* getInstance();
        //ports config
        const static double ROBOT_WIDTH_in;
        const static double ROBOT_LENGTH_in;
        const static double ROBOT_MAX_VELOCITY_in;
        const static double ROBOT_MAX_ACCEL_in;
        const static double ROBOT_MAX_JERK_in;

        const static int CAMERA_PORT = 0;
        
        const static int PUNCHER_1_PORT = 7;
        const static int PUNCHER_2_PORT = 9;
        const static int INTAKE_PORT = 5;
        const static int BASE_RIGHT_BACK = 4;
        const static int BASE_RIGHT_FRONT = 2;
        const static int BASE_LEFT_BACK = 3;
        const static int BASE_LEFT_FRONT = 1;
        const static int MAX_AUTO_CHOICE = 2; //all the options including no auto
        const static int BLUE_FLAG_SIG = 1;
        const static int RED_FLAG_SIG = 2;
        const static int GREEN_SIG = 3;

        static double targetY;
        static double targetFlag_X;
        static double targetFlag_Y;
        static double hortizontal_correction;
        static double vertical_correction;
        
        //in game states
        enum FieldColor {
            UNKNOWN,
			RED,
			BLUE
		}; 

        enum AutoChoice {
            NO_AUTO,
            BACK_TILE_ONE_FLAG
        };

        static FieldColor fieldColor;
        static AutoChoice autoChoice;
        
    private: 
        static RobotStates* instance;
};

#endif