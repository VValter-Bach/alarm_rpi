#include "main.hpp"

namespace IT{
    void MUSIC();
    bool music = false;

    void CHECK(){
        while(1){
            if(!digitalRead(Input_Loop)){ Music::music = !Music::music; sleep(1);}
            if(digitalRead(Input_Minus)){ Alarm::ADD_MINUTE(-5); sleep(1);}
            if(!digitalRead(Input_Alarm)){ Alarm::ALARM = !Alarm::ALARM; sleep(1);}
            if(!digitalRead(Input_Add)){ Alarm::ADD_MINUTE(5); sleep(1);}
            usleep(20000);
        }
    }

    void Play(){
	while(1){
            while(Music::music){
            	if(!Music::music_play) Music::music_play = true;
            	Music::PLAY();
            }
            if(Music::music_play) Music::music_play = false;
	    sleep(2);
	}
    }
}

