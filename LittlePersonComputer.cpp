/** @author Koll Klienstuber
  */

#ifndef LITTLEPERSONCOMPUTER_CPP
#define LITTLEPERSONCOMPUTER_CPP
#include <iostream>
#include <cmath>
#include <iomanip>
#include "LittlePersonComputer.h"

using namespace std;

LittlePersonComputer::LittlePersonComputer(){
    accumulator = 0;
    programCounter = 0;
    for(int i = 0; i < 20; i++){
        memory[i] = 0;
    }
}


LittlePersonComputer::LittlePersonComputer(int instructions[], int numberOfInstructions){
    accumulator = 0;
    programCounter = 0;
    // copy memory from array
    for (int i = 0; i < numberOfInstructions; i++){
        memory[i] = instructions[i];
    }
    // set rest of memory to 0
    for (int i = numberOfInstructions; i < 20; i++){
        memory[i] = 0;
    }
}


void LittlePersonComputer::restart(){
    accumulator = 0;
    programCounter = 0;
}


void LittlePersonComputer::reset(){
    accumulator = 0;
    programCounter = 0;
    for (int i = 0; i < 20; i++){
        memory[i] = 0;
    }
}


void LittlePersonComputer::loadProgram(int instructions[], int numberOfInstructions){
    for (int i = 0; i < numberOfInstructions; i++){
        memory[i] = instructions[i];
    }

    // set rest of memory to 0
    for (int i = numberOfInstructions; i < 20; i++){
        memory[i] = 0;
    }
    programCounter = 0;
    accumulator = memory[0];
}


void LittlePersonComputer::printState(){

    cout << "Accumulator : " << accumulator << "  "

         << "Program Counter : " << " " << programCounter << endl;

    cout << "Memory : \n";
    for (int i = 0; i < 20; i++){
        cout << i << setw(4);
    }
    cout<<"\n";
    for(int i = 0; i < 20; i++){
        cout << memory[i] << setw(4);
    }

    cout<< '\n';
}


int LittlePersonComputer::getCurrentInstruction(){

    //return memory[programCounter] ;
    cout << memory[programCounter];
}


bool LittlePersonComputer::isHalted(){
    int i = programCounter;
    if (memory[i] == 0){
        return true;
    }
    else{
        return false;
    }
}


void LittlePersonComputer::step(){

    while(!memory[programCounter] == 000 && memory[programCounter] > 100){

        int currentInstruction = memory[programCounter];


        if (currentInstruction - 100 < 100){
            //addition
            accumulator = accumulator + memory[(currentInstruction - 100)];
        }


        else if (currentInstruction >= 200 && currentInstruction < 220){
            //subtraction
            accumulator = accumulator - memory[(currentInstruction - 200)];

        }
        else if (currentInstruction >= 300 && currentInstruction < 320){
            //store value
            memory[currentInstruction - 300] = accumulator;

        }

        else if (currentInstruction >= 500 && currentInstruction < 520){
            //load value
            accumulator = memory[currentInstruction - 500];

        }

        else if (currentInstruction >= 600 && currentInstruction < 620){
            //brach always
            programCounter = currentInstruction - 601;
            currentInstruction = memory[currentInstruction - 600];

        }

        else if (currentInstruction >= 700 && currentInstruction < 720){
            //branch if 0
            if(accumulator == 0){
                programCounter = currentInstruction - 701;
                currentInstruction = memory[currentInstruction - 700];

            }

            else {
                currentInstruction = currentInstruction;
            }

        }
        else if (currentInstruction >= 800 && currentInstruction < 820){
            //branch if >=0
            if(accumulator >= 0){
                programCounter = currentInstruction - 801;
                currentInstruction = memory[currentInstruction - 800];
            }
            else{
                currentInstruction = currentInstruction;
            }
        }
        else if (currentInstruction == 901){
           //input
            cout<<"enter input: " << endl;
            int input;
            cin >> input;
            accumulator = input;

        }
        else if (currentInstruction == 902) {
            //output
            cout <<"Output: "<< accumulator << endl;

        }

        programCounter++;

    }

}
#endif // LITTLEPERSONCOMPUTER_CPP
