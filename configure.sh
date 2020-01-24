#!/bin/bash

variables () {

    R="\033[0;31m"
    Y="\033[1;33m"
    G="\033[0;32m"
    NC="\033[0m"

    echo -e "${G}Getting and Setting the varaibles${NC}"

    src=($(ls *.cpp))
    obj=()
    cc=c++
    flags="-Wall -Wextra -O3"
    linker="-lwiringPi -pthread -lstdc++fs"
    for item in ${src[*]}
    do
        obj+=($(echo "obj/$item" | tr -s 'cpp' 'o'))
    done

    echo -e "${Y}Please enter the name of the executable${NC}"
    read out

}



requirements () {

    echo -e "${Y}Checking Requirements${NC}"
    if test -d obj; then
    	echo -e "${G}Directrory obj/ found${NC}"
    else
    	mkdir obj
    fi

    if test -d bin; then
    	echo -e "${G}Directrory bin/ found${NC}"
    else
    	mkdir bin
    fi

    if test -e "$out"; then
	echo -e "${G}Link to executable found${NC}"
    else
	ln -s bin/$out $out
    fi
}

makefile () {

    echo -e "${G}Makefile creation${NC}"

    echo "CC=$cc" > makefile
    echo "LINKER=$linker" >> makefile
    echo "FLAGS=$flags" >> makefile
    echo "OBJ=${obj[*]}" >> makefile

    echo "${out}: \$(OBJ)" >> makefile
    echo -e "\t\$(CC) \$(FLAGS) -o bin/$out \$(OBJ) \$(LINKER)\n" >> makefile

    for((i=0; i<4; i++))
    do
        echo "${obj[$i]}: ${src[$i]}" >> makefile
        echo -e "\t\$(CC) \$(FLAGS) -c ${src[$i]} -o ${obj[$i]} \$(LINKER)\n" >> makefile
    done

    echo -e "clean:" >> makefile
    echo -e "\trm ${obj[*]}" >> makefile

}

echo -e "${Y}Sart Makefile generation${NC}"
variables
requirements
makefile

