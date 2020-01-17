#include "main.hpp"

namespace Led{

    int RANDOM(unsigned int max){
        srand (time(NULL) * rand());
        return rand() % max;
    }


    void RGB(unsigned char * dat, int R, int G, int B, int u, int len){ //MODE 0
        for(int i = 0; i < len; i++){
            if((i%3) == 0) dat[i] = R * std::sin((u/33.0f) * PI);
            if((i%3) == 1) dat[i] = G * std::sin((u/33.0f) * PI);
            if((i%3) == 2) dat[i] = B * std::sin((u/33.0f) * PI);
        }
    }

    void RGB_MOVE(unsigned char * dat, int u, int len){//MODE 1
        for(int i = 0; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + u / 10.0f);
        for(int i = 1; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + ((2/3.0f)*PI) + u / 10.0f);
        for(int i = 2; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + (2*(2/3.0f)*PI) + u / 10.0f);
    }


    void LEDSHOW(bool mode, int R, int G, int B){
        int len = 77 * 3;
        unsigned char dat[300] = {};

        for(int u = 0;; u++){
            if(Music::music_play){
                if(mode) RGB(dat, R, G, B, u, len);
                else RGB_MOVE(dat, u, len);
                wiringPiSPIDataRW(0, dat, len);
                usleep(30000);
            }else {
                for(int i = 0; i < len; i++) dat[i] = 0;
                wiringPiSPIDataRW(0, dat, len);
		sleep(5);
            }
        }
    }
}
