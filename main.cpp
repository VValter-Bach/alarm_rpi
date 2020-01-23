#include "main.hpp"

void InitGpio();


int main(){
    InitGpio();

    thread first(dgt::DISPLAY);   // only controls 7-segment displays and status LEDs
    thread first(dgt::DISPLAY);   // only controls 7-segment displays and status LEDs
    wiringPiISR(INPUT_MUSIC, INT_EDGE_FALLING, &(gnl::Toggle_Music));
    wiringPiISR(INOUT_MINUS, INT_EDGE_FALLING, &(gnl::Decrease_Minute));
    wiringPiISR(INPUT_ALARM, INT_EDGE_FALLING, &(gnl::Toggle_Alarm));
    wiringPiISR(INPUT_PLUS, INT_EDGE_FALLING, &(gnl::Increase_Minute));

}


//this initializes all GPIOs according to their role
void InitGpio(){
    wiringPiSetup();

    if (wiringPiSPISetup(0,1000000) == -1)
        exit (1);


    pinMode(SEGMENT1, OUTPUT);
    pinMode(SEGMENT2, OUTPUT);
    pinMode(SEGMENT3, OUTPUT);
    pinMode(SEGMENT4, OUTPUT);
    pinMode(SEGMENT5, OUTPUT);
    pinMode(SEGMENT6, OUTPUT);
    pinMode(SEGMENT7, OUTPUT);
    pinMode(SEGMENT8, OUTPUT);

    pinMode(DIGIT1, OUTPUT);
    pinMode(DIGIT2, OUTPUT);
    pinMode(DIGIT3, OUTPUT);
    pinMode(DIGIT4, OUTPUT);
    pinMode(DIGIT5, OUTPUT);
    pinMode(DIGIT6, OUTPUT);
    pinMode(DIGIT7, OUTPUT);
    pinMode(DIGIT8, OUTPUT);

    pinMode(Led_Red, OUTPUT);
    pinMode(Led_Yellow, OUTPUT);
    pinMode(Led_Green, OUTPUT);
    pinMode(Led_Music, OUTPUT);
}
