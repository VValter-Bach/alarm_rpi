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

#include "Digit.hpp"
#include "light_sound.hpp"
#include "general.hpp"

#define PI 3.14f

#define Item1 8
#define Item2 9
#define Item3 7
#define Item4 15
#define Item5 16
#define Item6 1
#define Item7 0
#define Item8 2

#define Sleep 2222

#define Digit1 29
#define Digit2 28
#define Digit3 27
#define Digit4 26
#define Digit5 25
#define Digit6 24
#define Digit7 23
#define Digit8 22

#define Input_Loop 21
#define Input_Minus 6
#define Input_Alarm 11
#define Input_Add 31

#define Led_Red 3
#define Led_Yellow 4
#define Led_Green 5
#define Led_Music 30



#endif // MAIN_HPP
