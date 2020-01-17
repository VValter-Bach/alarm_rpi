#include "main.hpp"

namespace Music {
    bool music = false;
    bool music_play = false;
    vector<string> songs = {};
    void PLAY();
    int RANDOM(int);



    void PLAY(){
        songs = {};
        string path = "/home/pi/Music/";
        for (const auto & entry : directory_iterator(path)) songs.push_back(entry.path());
        system(("omxplayer --no-osd \"" + songs[RANDOM(songs.size())] + "\"").c_str());
    }

    int RANDOM(int max){
        srand (time(NULL));
        return rand() % max;
    }

}

