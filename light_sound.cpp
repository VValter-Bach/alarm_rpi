#include "light_sound.hpp"
#include "main.hpp"

namespace ls{ //ls = light and sound
    //The global interface for the music
    bool music_bol = false;
    void Light_Sound();

    //the intern declariontins and varaibles
    bool music_play_bol = false;
    void RGB_Color_Pulse(char*, int, int, int, int, int);
    void Play_Music();
    void RGB_Move(char*, int, int);
    int Random(unsigned int);
    void Led_Show(bool, int, int, int);
    void RGB_Generate();
    int r_int;
    int b_int;
    int g_int;

    void Light_Sound(){
        while(1){
            std::thread * led_ted = nullptr;
            if(music_bol){ //If music_bol is true set music is playing true adn play music
                music_play_bol = true;
		RGB_Generate();
                led_ted = new std::thread(Led_Show, Random(100) > 50 ? false:true, r_int, g_int, b_int);
                while(music_bol) Play_Music();
            }
            else{ //Else reset music_play_bol
                music_play_bol = false;
                if(led_ted != nullptr)led_ted->join();
		led_ted = nullptr;
            }
            sleep(2);
        }
    }

    //returns truly a random number for song selection maxium return value is max-1
    int Random(unsigned int max){
        srand (time(NULL) * rand());
        return rand() % max;
    }

    //The u is the time varaible which let it pulsate
    void RGB_Color_Pulse(unsigned char * dat, int R, int G, int B, int u, int len){
        for(int i = 0; i < len; i++){
            if((i%3) == 0) dat[i] = R * std::abs(std::sin((u/53.0f) * PI));
            if((i%3) == 1) dat[i] = G * std::abs(std::sin((u/53.0f) * PI));
            if((i%3) == 2) dat[i] = B * std::abs(std::sin((u/53.0f) * PI));
        }
    }

    void RGB_Generate(){
	int rand = Random(1000);
	if(rand < 333){
	    r_int = Random(256);
	    g_int = Random(255 - r_int);
	    b_int = (255 - r_int) - g_int;
	}
        else if(rand > 666){
            b_int = Random(256);
            r_int = Random(255 - b_int);
            g_int = (255 - b_int) - r_int;
        }
	else{
            g_int = Random(256);
            b_int = Random(255 - g_int);
            r_int = (255 - g_int) - b_int;
        }
    }

    //just run it and see dunno how to describe
    void RGB_Move(unsigned char * dat, int u, int len){
        for(int i = 0; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + u / 10.0f);
        for(int i = 1; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + ((2/3.0f)*PI) + u / 10.0f);
        for(int i = 2; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + (2*(2/3.0f)*PI) + u / 10.0f);
    }

    //this runs meanwhile playing music
    void Led_Show(bool mode, int R, int G, int B){
        int len = 77 * 3; //the length of the led stripe 77 leds for each 3 values (rgb)
        unsigned char dat[len] = {}; //the array for the data

        for(int u = 0; music_play_bol; u++){ //while music is playing
            if(mode) RGB_Color_Pulse(dat, R, G, B, u, len); //animation 1
            else RGB_Move(dat, u, len); //animation 0
            wiringPiSPIDataRW(0, dat, len);//writes the daata on spi
            usleep(30000);//sleeps for 300000 mikroseconds
        }
        for(int i = 0; i < len; i++) dat[i] = 0; //if music isnt playing anymore write the data all 0 to makes the leds out
        wiringPiSPIDataRW(0, dat, len);
    }

    //this plays a song
    void Play_Music(){
        std::vector<string> songs = {};
        std::string path = "/home/pi/Music/";
        for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) songs.push_back(entry.path());
        system(("omxplayer --no-osd \"" + songs[Random(songs.size())] + "\"").c_str());
    }
}
