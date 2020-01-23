#include "main.hpp"

namespace dgt{

    //Predefinitions of all the functions
    void Number_Zero(bool seperator_bol = false);
    void Number_One(bool seperator_bol = false);
    void Number_Two(bool seperator_bol = false);
    void Number_Three(bool seperator_bol = false);
    void Number_Four(bool seperator_bol = false);
    void Number_Five(bool seperator_bol = false);
    void Number_Six(bool seperator_bol = false);
    void Number_Seven(bool seperator_bol = false);
    void Number_Eight(bool seperator_bol = false);
    void Number_Nine(bool seperator_bol = false);
    void Display();
    void Number_On_Digit(char, bool = false);
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
                    if(hour < 10) Number_Zero(); //If the number is smaller then 10 the we want there a 06:XX on the clock, so the first digit is replaced with a zero
                    else Number_On_Digit(to_string(hour)[0]); //Else the first number 13:XX (at index 0 of the string) gets displayed
                    break;
                case 2: //The second Digit
                    //The true is set because of the seperator we want for example 16:30 on the display not 1630
                    if(hour < 10) Number_On_Digit(to_string(hour)[0], true); //If the number is smaller then 10 we need to take the first position of the string
                    else Number_On_Digit(to_string(hour)[1], true); //Else the second number at the String (at index 1)
                    break;
                case 3://Same as above
                    if(mins < 10) Number_Zero();
                    else Number_On_Digit(to_string(mins)[0]);
                    break;
                case 4:
                    if(mins < 10) Number_On_Digit(to_string(mins)[0]);
                    else Number_On_Digit(to_string(mins)[1]);
                    break;
                case 5:
                    if(gnl::alarm_hour_int < 10) Number_Zero();
                    else Number_On_Digit(to_string(gnl::alarm_hour_int)[0]);
                    break;
                case 6:
                    if(gnl::alarm_hour_int < 10) Number_On_Digit(to_string(gnl::alarm_hour_int)[0], true);
                    else Number_On_Digit(to_string(gnl::alarm_hour_int)[1], true);
                    break;
                case 7:
                    if(gnl::alarm_min_int < 10) Number_Zero();
                    else Number_On_Digit(to_string(gnl::alarm_min_int)[0]);
                    break;
                case 8:
                    if(gnl::alarm_min_int < 10) Number_On_Digit(to_string(gnl::alarm_min_int)[0]);
                    else Number_On_Digit(to_string(gnl::alarm_min_int)[1]);
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

    //This takes a char and calls the related function
    void Number_On_Digit(char c, bool point){
    	switch(c){
            case '0' : Number_Zero(point);
            	break;
            case '1' : Number_One(point);
            	break;
            case '2' : Number_Two(point);
            	break;
            case '3' : Number_Three(point);
            	break;
            case '4' : Number_Four(point);
            	break;
            case '5' : Number_Five(point);
            	break;
            case '6' : Number_Six(point);
            	break;
            case '7' : Number_Seven(point);
            	break;
            case '8' : Number_Eight(point);
            	break;
            case '9' : Number_Nine(point);
            	break;
    	}
    }

    //This is which segments pins must be high and low to display the number given in the function name
    void Number_Zero(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 1);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 0);
        digitalWrite(SEGMENT5, 1);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 1);
        digitalWrite(SEGMENT8, seperator_bol); // if the seperator bool is true the point after the number (segment 8) must be light up
    }


    //it is the functionallity is the same but the high and low values are fifferent
    void Number_One(bool seperator_bol){
        digitalWrite(SEGMENT1, 0);
        digitalWrite(SEGMENT2, 0);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 0);
        digitalWrite(SEGMENT5, 0);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 0);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Two(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 0);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 1);
        digitalWrite(SEGMENT5, 1);
        digitalWrite(SEGMENT6, 0);
        digitalWrite(SEGMENT7, 1);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Three(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 0);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 1);
        digitalWrite(SEGMENT5, 0);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 1);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Four(bool seperator_bol){
        digitalWrite(SEGMENT1, 0);
        digitalWrite(SEGMENT2, 1);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 1);
        digitalWrite(SEGMENT5, 0);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 0);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Five(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 1);
        digitalWrite(SEGMENT3, 0);
        digitalWrite(SEGMENT4, 1);
        digitalWrite(SEGMENT5, 0);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 1);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Six(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 1);
        digitalWrite(SEGMENT3, 0);
        digitalWrite(SEGMENT4, 1);
        digitalWrite(SEGMENT5, 1);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 1);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Seven(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 0);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 0);
        digitalWrite(SEGMENT5, 0);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 0);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Eight(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 1);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 1);
        digitalWrite(SEGMENT5, 1);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 1);
        digitalWrite(SEGMENT8, seperator_bol);
    }

    void Number_Nine(bool seperator_bol){
        digitalWrite(SEGMENT1, 1);
        digitalWrite(SEGMENT2, 1);
        digitalWrite(SEGMENT3, 1);
        digitalWrite(SEGMENT4, 1);
        digitalWrite(SEGMENT5, 0);
        digitalWrite(SEGMENT6, 1);
        digitalWrite(SEGMENT7, 1);
        digitalWrite(SEGMENT8, seperator_bol);
    }

}
