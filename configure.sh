#!/bin/bash

R='\033[0;31m'
Y='\033[1;33m'
G='\033[0;32m'
NC='\033[0m'

requirements () {

echo -e "${Y}Checking Requirements${NC}"
if test -d obj; then
    echo -e "${G}Directrory obj/ found${NC}"
else
    echo -e "${R}Directory bin/ gets created${NC}"
    mkdir obj
fi

if test -d bin; then
    echo -e "${G}Directrory bin/ found${NC}"
else
    echo -e "${R}Directory bin/ gets created${NC}"
    mkdir bin
fi

}

makefile () {

    out="alarm.out"
    src=($(ls *.cpp))
    obj=()
    cc=c++
    flags="-Wall -lwiringPi -pthread -lstdc++fs"
    for item in ${src[*]}
    do
        obj+=($(echo "obj/$item" | tr -s 'cpp' 'o'))
    done
    echo "CC=$cc" > makefile
    echo "FLAGS=$flags" >> makefile
    echo "OBJ=${obj[*]}" >> makefile

    echo "${out}: \$(OBJ)" >> makefile
    echo -e "\t\$(CC) -o ${out} \$(OBJ) \$(FLAGS)\n" >> makefile

    for((i=0; i<4; i++))
    do
        echo "${obj[$i]}: ${src[$i]}" >> makefile
        echo -e "\t\$(CC) -c ${src[$i]} -o ${obj[$i]} \$(FLAGS)" >> makefile
    done
}

echo -e "${Y}Sart Makefile generation${NC}"
requirements
makefile

