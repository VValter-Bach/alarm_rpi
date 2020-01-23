#ifndef GENERAL_HPP
#define GENERAL_HPP

namespace gnl{
    extern int alarm_hour_int;
    extern int alarm_min_int;
    extern bool alarm_bol;

    void Toggle_Music();
    void Toggle_Alarm();
    void Increase_Minute();
    void Decrease_Minute();
}

#endif //GENERAL_HPP