#include "main.hpp"

void ALARM_FKT();


int main(){
    Init::initGpio();

    thread first(Digit::DISPLAY);   // only controls 7-segment displays

    thread second(IT::Play);
    thread third(IT::CHECK);
    thread fourd(Led::LEDSHOW, 0, 0, 0, 0);
    first.join();
}
