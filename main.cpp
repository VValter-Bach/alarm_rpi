#include "main.hpp"

void InitGpio();


int main(){
    InitGpio();

    thread first(Digit::DISPLAY);   // only controls 7-segment displays and status LEDs
    wiringPiISR(Input_Loop, INT_EDGE_FALLING, &(gnl::Toggle_Music));
    wiringPiISR(Input_Minus, INT_EDGE_FALLING, &(gnl::Decrease_Minute));
    wiringPiISR(Input_Alarm, INT_EDGE_FALLING, &(gnl::Toggle_Alarm));
    wiringPiISR(Input_Add, INT_EDGE_FALLING, &(gnl::Increase_Minute));

}


//this initializes all GPIOs according to their role
void InitGpio(){
    wiringPiSetup();

    if (wiringPiSPISetup(0,1000000) == -1)
        exit (1);


    pinMode(Item1, OUTPUT);
    pinMode(Item2, OUTPUT);
    pinMode(Item3, OUTPUT);
    pinMode(Item4, OUTPUT);
    pinMode(Item5, OUTPUT);
    pinMode(Item6, OUTPUT);
    pinMode(Item7, OUTPUT);
    pinMode(Item8, OUTPUT);

    pinMode(Digit1, OUTPUT);
    pinMode(Digit2, OUTPUT);
    pinMode(Digit3, OUTPUT);
    pinMode(Digit4, OUTPUT);
    pinMode(Digit5, OUTPUT);
    pinMode(Digit6, OUTPUT);
    pinMode(Digit7, OUTPUT);
    pinMode(Digit8, OUTPUT);

    pinMode(Led_Red, OUTPUT);
    pinMode(Led_Yellow, OUTPUT);
    pinMode(Led_Green, OUTPUT);
    pinMode(Led_Music, OUTPUT);
}