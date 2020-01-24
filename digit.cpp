#include "main.hpp"

namespace dgt{
    //numbers in arrays -0-         -1-             -2-         -3-             -4-             -5-             -6-             -7-          -8-            -9-
    bool pinvalues[70] = {1,1,1,0,1,1,1, 0,0,1,0,0,1,0, 1,0,1,1,1,0,1, 1,0,1,1,0,1,1, 0,1,1,1,0,1,0, 1,1,0,1,0,1,1, 1,1,0,1,1,1,1, 1,0,1,0,0,1,0, 1,1,1,1,1,1,1, 1,1,1,1,0,1,1};
    int pins[8] = {SEGMENT1, SEGMENT2, SEGMENT3, SEGMENT4, SEGMENT5, SEGMENT6, SEGMENT7, SEGMENT8};
    void Display();
    void Number_On_Digit(int, bool = false);
    void Select_Digit(int);
    void Time_Display(int, int);
    void Status_Display(int);

    //The Display function, it is the main Coordinator
    void Display(){
    	time_t rawtime; //The place for the raw timedata to be stored
    	struct tm * timeinfo; //The conversion structure from raw to usable data
    	while(1){
            time(&rawtime); //Update the raw data
            timeinfo = localtime(&rawtime); //Update the converted data
            Time_Display(timeinfo->tm_min, timeinfo->tm_hour); //Call of Time_Display
            if(gnl::alarm_bol && timeinfo->tm_hour == gnl::alarm_hour_int && timeinfo->tm_min == gnl::alarm_min_int) ls::music_bol = true;
            Status_Display(timeinfo->tm_wday); //Call of Status_Display
    	}
    }

    //It controlls the three status LEDS
    void Status_Display(int day){
        digitalWrite(Led_Red, gnl::alarm_bol);
        digitalWrite(Led_Green, (day > 4));
        digitalWrite(Led_Music, ls::music_bol);
     }

    //This iterates through the single Digits
    void Time_Display(int mins, int hour){
        //for 1...8 (the 8 Digits)
    	for(int i = 1; i < 9; i++){
            Select_Digit(i);
            switch (i){
                case 1: //The first Digit
                    if(hour < 10) Number_On_Digit(0); //If the number is smaller then 10 the we want there a 06:XX on the clock, so the first digit is replaced with a zero
                    else Number_On_Digit(hour / 10); //Else the first number 13:XX (at index 0 of the string) gets displayed
                    break;
                case 2: //The second Digit
                    //The true is set because of the seperator we want for example 16:30 on the display not 1630
                    if(hour < 10) Number_On_Digit(hour, true); //If the number is smaller then 10 we need to take the first position of the string
                    else Number_On_Digit(hour % 10, true); //Else the second number at the String (at index 1)
                    break;
                case 3://Same as above
                    if(mins < 10) Number_On_Digit(0);
                    else Number_On_Digit(mins / 10);
                    break;
                case 4:
                    if(mins < 10) Number_On_Digit(mins);
                    else Number_On_Digit(mins % 10);
                    break;
                case 5:
                    if(gnl::alarm_hour_int < 10) Number_On_Digit(0);
                    else Number_On_Digit(gnl::alarm_hour_int / 10);
                    break;
                case 6:
                    if(gnl::alarm_hour_int < 10) Number_On_Digit(gnl::alarm_hour_int, true);
                    else Number_On_Digit(gnl::alarm_hour_int % 10, true);
                    break;
                case 7:
                    if(gnl::alarm_min_int < 10) Number_On_Digit(0);
                    else Number_On_Digit(gnl::alarm_min_int / 10);
                    break;
                case 8:
                    if(gnl::alarm_min_int < 10) Number_On_Digit(gnl::alarm_min_int);
                    else Number_On_Digit(gnl::alarm_min_int % 10);
                    break;
           }
           usleep(Sleep); //The sleep command for the pins to change according to the selected Number
    	}
    }

    //The Idea behind this is if the out put is set to 0 it is usable as a Ground.
    //The pin of the digit-segment must be hight
    //Here it iterates throught the digit and set only the active one on low the rest is high
    void Select_Digit(int i){
        digitalWrite(DIGIT1, i != 1);
        digitalWrite(DIGIT2, i != 2);
        digitalWrite(DIGIT3, i != 3);
        digitalWrite(DIGIT4, i != 4);
        digitalWrite(DIGIT5, i != 5);
        digitalWrite(DIGIT6, i != 6);
        digitalWrite(DIGIT7, i != 7);
        digitalWrite(DIGIT8, i != 8);
    }

    //This takes a int and wirte the segments according to the array
    void Number_On_Digit(int number, bool point){
        for(int i = 0; i < 7; i++){
            digitalWrite(pins[i],pinvalues[number*7+i]);
        }
        digitalWrite(pins[7], point);
    }
}
