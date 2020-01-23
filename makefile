CC=g++
FLAGS=-O3 -pthread
OBJ=obj/Digit.o obj/general.o obj/light_sound.o obj/main.o
alarm: $(OBJ)
	$(CC) $(FLAGS) -o alarm $(OBJ)

obj/Digit.o: Digit.cpp
	$(CC) $(FLAGS) -c Digit.cpp -o obj/Digit.o
obj/general.o: general.cpp
	$(CC) $(FLAGS) -c general.cpp -o obj/general.o
obj/light_sound.o: light_sound.cpp
	$(CC) $(FLAGS) -c light_sound.cpp -o obj/light_sound.o
obj/main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp -o obj/main.o
