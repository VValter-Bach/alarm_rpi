#include "main.hpp"

namespace Digit{

    void ZIFFER_NULL(bool Mitte_bol = false);
    void ZIFFER_EINS(bool Mitte_bol = false);
    void ZIFFER_ZWEI(bool Mitte_bol = false);
    void ZIFFER_DREI(bool Mitte_bol = false);
    void ZIFFER_VIER(bool Mitte_bol = false);
    void ZIFFER_FUNF(bool Mitte_bol = false);
    void ZIFFER_SECHS(bool Mitte_bol = false);
    void ZIFFER_SIEBEN(bool Mitte_bol = false);
    void ZIFFER_ACHT(bool Mitte_bol = false);
    void ZIFFER_NEUN(bool Mitte_bol = false);
    void DISPLAY();
    void CHOOSER(char, bool = false);
    void SELECTOR(int);
    void TIME(int, int);
    void LAMP(int);

    void DISPLAY(){
    	time_t rawtime;
    	struct tm * timeinfo;
    	while(1){
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            TIME(timeinfo->tm_min, timeinfo->tm_hour);
            if(timeinfo->tm_hour == Alarm::ALARM_HOUR && timeinfo->tm_min == Alarm::ALARM_MINUTES && Alarm::ALARM) Music::music = true;
            LAMP(timeinfo->tm_wday);
    	}
    }

    void LAMP(int day){
        digitalWrite(Led_Red, Alarm::ALARM);
        digitalWrite(Led_Yellow, !Alarm::ALARM);
        digitalWrite(Led_Green, (day > 4));
        digitalWrite(Led_Music, Music::music);
     }

    void TIME(int mins, int hour){
    	for(int i = 1; i < 9; i++){
            SELECTOR(i);
            switch (i){
    	       case 1:
                    if(hour < 10) ZIFFER_NULL();
                    else CHOOSER(to_string(hour)[0]);
                    break;
       	    	case 2:
                    if(hour < 10) CHOOSER(to_string(hour)[0]);
                    else CHOOSER(to_string(hour)[1], true);
                    break;
        	case 3:
                    if(mins < 10) ZIFFER_NULL();
                    else CHOOSER(to_string(mins)[0]);
                    break;
           	case 4:
                    if(mins < 10) CHOOSER(to_string(mins)[0]);
                    else CHOOSER(to_string(mins)[1]);
                    break;
           	case 5:
                    if(Alarm::ALARM_HOUR < 10) ZIFFER_NULL();
                    else CHOOSER(to_string(Alarm::ALARM_HOUR)[0]);
                    break;
           	case 6:
                    if(Alarm::ALARM_HOUR < 10) CHOOSER(to_string(Alarm::ALARM_HOUR)[0]);
                    else CHOOSER(to_string(Alarm::ALARM_HOUR)[1], true);
                    break;
           	case 7:
                    if(Alarm::ALARM_MINUTES < 10) ZIFFER_NULL();
                    else CHOOSER(to_string(Alarm::ALARM_MINUTES)[0]);
                    break;
           	case 8:
                    if(Alarm::ALARM_MINUTES < 10) CHOOSER(to_string(Alarm::ALARM_MINUTES)[0]);
                    else CHOOSER(to_string(Alarm::ALARM_MINUTES)[1]);
                    break;
           }
           usleep(Sleep);
    	}
    }

    void SELECTOR(int i){
        digitalWrite(Digit1, !(i == 1));
        digitalWrite(Digit2, !(i == 2));
        digitalWrite(Digit3, !(i == 3));
        digitalWrite(Digit4, !(i == 4));
        digitalWrite(Digit5, !(i == 5));
        digitalWrite(Digit6, !(i == 6));
        digitalWrite(Digit7, !(i == 7));
        digitalWrite(Digit8, !(i == 8));
    }

    void CHOOSER(char c, bool point){
    	switch(c){
            case '0' : ZIFFER_NULL(point);
            	break;
            case '1' : ZIFFER_EINS(point);
            	break;
            case '2' : ZIFFER_ZWEI(point);
            	break;
            case '3' : ZIFFER_DREI(point);
            	break;
            case '4' : ZIFFER_VIER(point);
            	break;
            case '5' : ZIFFER_FUNF(point);
            	break;
            case '6' : ZIFFER_SECHS(point);
            	break;
            case '7' : ZIFFER_SIEBEN(point);
            	break;
            case '8' : ZIFFER_ACHT(point);
            	break;
            case '9' : ZIFFER_NEUN(point);
            	break;
    	}
    }

    void ZIFFER_NULL(bool Mitte_bol){
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
    void ZIFFER_EINS(bool Mitte_bol){
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
    void ZIFFER_ZWEI(bool Mitte_bol){
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
    void ZIFFER_DREI(bool Mitte_bol){
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
    void ZIFFER_VIER(bool Mitte_bol){
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
    void ZIFFER_FUNF(bool Mitte_bol){
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
    void ZIFFER_SECHS(bool Mitte_bol){
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
    void ZIFFER_SIEBEN(bool Mitte_bol){
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
    void ZIFFER_ACHT(bool Mitte_bol){
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
    void ZIFFER_NEUN(bool Mitte_bol){
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
