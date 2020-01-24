#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <experimental/filesystem>
#include <iostream>
#include <wiringPiSPI.h>
#include <cmath>

using namespace std;
using namespace std::experimental::filesystem;

#include "digit.hpp"
#include "light_sound.hpp"
#include "general.hpp"

#define PI 3.14f

#define SEGMENT1 8
#define SEGMENT2 9
#define SEGMENT3 7
#define SEGMENT4 15
#define SEGMENT5 16
#define SEGMENT6 1
#define SEGMENT7 0
#define SEGMENT8 2

#define Sleep 2222

#define DIGIT1 29
#define DIGIT2 28
#define DIGIT3 27
#define DIGIT4 26
#define DIGIT5 25
#define DIGIT6 24
#define DIGIT7 23
#define DIGIT8 22

#define INPUT_MUSIC 21
#define INOUT_MINUS 6
#define INPUT_ALARM 11
#define INPUT_PLUS 31

#define Led_Red 3
#define Led_Yellow 4
#define Led_Green 5
#define Led_Music 30



#endif // MAIN_HPP
