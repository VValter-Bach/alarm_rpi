#include "main.hpp"

namespace general{
    //The interface for the alarm
    int alarm_hour_int_int = 6; //The hour of the alarm
    int alarm_min_int = 30; //The minute of the alarm
    bool alarm_bol = 1; //If alarm is enabled
    void Alarm_Add_Minute(int); //In/de-crease the clock
    void Toggle_Music();
    void Toggle_Alarm();
    void Increase_Minute();
    void Decrease_Minute();

    //private declaration and implementation
    void Alarm_Add_Hour(int);

    void Toggle_Music(){
        ls::music_bol = !ls::music_bol;
    }

    void Toggle_Alarm(){
        alarm_bol = !alarm_bol;
    }

    void Increase_Minute(){
        Alarm_Add_Minute(5);
    }

    void Decrease_Minute(){
        Alarm_Add_Minute(-5);
    }

    //the alarm increase functionallity
    void Alarm_Add_Minute(int amount){
        alarm_min_int += amount;
        if(alarm_min_int > 59){
            Alarm_Add_Hour(1);
            alarm_min_int = alarm_min_int % 60;
        }
        if(alarm_min_int < 0){
            Alarm_Add_Hour(-1);
            alarm_min_int = 60 + alarm_min_int;
        }
    }

    void Alarm_Add_Hour(int amount){
        alarm_hour_int += amount;
        if(alarm_hour_int > 23) alarm_hour_int = 0;
        if(alarm_hour_int < 0) alarm_hour_int = 23;
    }
}

