#include "main.hpp"

namespace Digit{

    //Predefinitions of all the functions
    void Number_Zero(bool Mitte_bol = false);
    void Number_One(bool Mitte_bol = false);
    void Number_Two(bool Mitte_bol = false);
    void Number_Three(bool Mitte_bol = false);
    void Number_Four(bool Mitte_bol = false);
    void Number_Five(bool Mitte_bol = false);
    void Number_Six(bool Mitte_bol = false);
    void Number_Seven(bool Mitte_bol = false);
    void Number_Eight(bool Mitte_bol = false);
    void Number_Nine(bool Mitte_bol = false);
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
            if(timeinfo->tm_hour == Alarm::ALARM_HOUR && timeinfo->tm_min == Alarm::ALARM_MINUTES && Alarm::ALARM) Music::music = true; //TODO: rewrite the alarm check
            Status_Display(timeinfo->tm_wday); //Call of Status_Display
    	}
    }

    //It controlls the three status LEDS
    void Status_Display(int day){
        digitalWrite(Led_Red, Alarm::ALARM);
        digitalWrite(Led_Green, (day > 4));
        digitalWrite(Led_Music, Music::music);
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
                    if(hour < 10) Number_On_Digit(to_string(hour)[0]); //If the number is smaller then 10 we need to take the first position of the string
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
                    if(Alarm::ALARM_HOUR < 10) Number_Zero();
                    else Number_On_Digit(to_string(Alarm::ALARM_HOUR)[0]);
                    break;
                case 6:
                    if(Alarm::ALARM_HOUR < 10) Number_On_Digit(to_string(Alarm::ALARM_HOUR)[0]);
                    else Number_On_Digit(to_string(Alarm::ALARM_HOUR)[1], true);
                    break;
                case 7:
                    if(Alarm::ALARM_MINUTES < 10) Number_Zero();
                    else Number_On_Digit(to_string(Alarm::ALARM_MINUTES)[0]);
                    break;
                case 8:
                    if(Alarm::ALARM_MINUTES < 10) Number_On_Digit(to_string(Alarm::ALARM_MINUTES)[0]);
                    else Number_On_Digit(to_string(Alarm::ALARM_MINUTES)[1]);
                    break;
           }
           usleep(Sleep); //The sleep command for the pins to change according to the selected Number
    	}
    }

    //The Idea behind this is if the out put is set to 0 it is usable as a Ground.
    //The pin of the digit must be low
    void Select_Digit(int i){
        digitalWrite(Digit1, !(i == 1));
        digitalWrite(Digit2, !(i == 2));
        digitalWrite(Digit3, !(i == 3));
        digitalWrite(Digit4, !(i == 4));
        digitalWrite(Digit5, !(i == 5));
        digitalWrite(Digit6, !(i == 6));
        digitalWrite(Digit7, !(i == 7));
        digitalWrite(Digit8, !(i == 8));
    }

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

    void Number_Zero(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 1);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 0);
        digitalWrite(Item5, 1);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 1);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_One(bool Mitte_bol){
        digitalWrite(Item1, 0);
        digitalWrite(Item2, 0);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 0);
        digitalWrite(Item5, 0);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 0);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Two(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 0);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 1);
        digitalWrite(Item5, 1);
        digitalWrite(Item6, 0);
        digitalWrite(Item7, 1);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Three(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 0);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 1);
        digitalWrite(Item5, 0);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 1);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Four(bool Mitte_bol){
        digitalWrite(Item1, 0);
        digitalWrite(Item2, 1);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 1);
        digitalWrite(Item5, 0);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 0);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Five(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 1);
        digitalWrite(Item3, 0);
        digitalWrite(Item4, 1);
        digitalWrite(Item5, 0);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 1);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Six(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 1);
        digitalWrite(Item3, 0);
        digitalWrite(Item4, 1);
        digitalWrite(Item5, 1);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 1);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Seven(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 0);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 0);
        digitalWrite(Item5, 0);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 0);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Eight(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 1);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 1);
        digitalWrite(Item5, 1);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 1);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

    void Number_Nine(bool Mitte_bol){
        digitalWrite(Item1, 1);
        digitalWrite(Item2, 1);
        digitalWrite(Item3, 1);
        digitalWrite(Item4, 1);
        digitalWrite(Item5, 0);
        digitalWrite(Item6, 1);
        digitalWrite(Item7, 1);

        if(Mitte_bol) digitalWrite(Item8, 1);
        else digitalWrite(Item8, 0);
    }

}
