#include "main.hpp"

namespace Alarm{

    int ALARM_HOUR = 6;
    int ALARM_MINUTES = 30;
    bool ALARM = 1;

    void ADD_HOUR(int);
    void ADD_MINUTE(int);
    void CHECK();
    void PLAY();



    void ADD_MINUTE(int amount){
        ALARM_MINUTES += amount;
        if(ALARM_MINUTES > 59){
            ADD_HOUR(1);
            ALARM_MINUTES = ALARM_MINUTES % 60;
        }
        if(ALARM_MINUTES < 0){
            ADD_HOUR(-1);
            ALARM_MINUTES = 60 + ALARM_MINUTES;
        }
    }

    void ADD_HOUR(int amount){
        ALARM_HOUR += amount;
        if(ALARM_HOUR > 23) ALARM_HOUR = 0;
        if(ALARM_HOUR < 0) ALARM_HOUR = 23;
    }
}

