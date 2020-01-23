namespace ls{ //ls = light and sound
    //The interface for the music
    bool music_bol = false;
    bool music_play_bol = false;
    void Play_Music();


    void Light_Sound(){
        while(1){
            std::thread * led_ted;
            if(music_bol){ //If music_bol is true set music is playing true adn play music
                music_play_bol = true;
                led_ted = new std::thred(Led_Show, Random(2), Random(255), Random(255), Random(255));
                while(music_bol) Play_Music();
            }
            else{ //Else reset music_play_bol
                music_play_bol = false;
                led_ted->join();
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
            if((i%3) == 0) dat[i] = R * std::sin((u/33.0f) * PI);
            if((i%3) == 1) dat[i] = G * std::sin((u/33.0f) * PI);
            if((i%3) == 2) dat[i] = B * std::sin((u/33.0f) * PI);
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
        for (const auto & entry : directory_iterator(path)) songs.push_back(entry.path());
        system(("omxplayer --no-osd \"" + songs[Random(songs.size())] + "\"").c_str());
    }
}