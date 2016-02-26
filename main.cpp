using namespace std;
#include <iostream>
#include "LittlePersonComputer.h"
int main() {

    int program1 [] = {508, 605, 901, 901,901, 108, 902, 0, 10}; // break always
   // int program1 [] = {901, 310, 510, 206, 902, 0, 5}; // load and store
   //int program1[]= {505, 204, 902, 0, 5, 11}; //subtraction
    //int program1[] = {504, 104, 902, 0 , 12 }; //addition
    //int program1[] = {504, 104, 902, 0 , 10};
    LittlePersonComputer computer1(program1, 9);
    while( !computer1.isHalted() ) {
        computer1.step();
    }
    computer1.printState();

}
