/**
  * @author Koll Klienstuber
  */

#ifndef LITTLEPERSONCOMPUTER_H
#define LITTLEPERSONCOMPUTER_H

/**
* @brief The LittlePersonComputer class represents a computer with one general purpose register, the accumulator,
* and a limited vocabulary of machine instructions represented as integers.
        */

class LittlePersonComputer {
public:
    //DECLARATION

    /**
     * @brief LittlePersonComputer sets all memory, the accumulator and the program counter to 0.
     */
    LittlePersonComputer();

    /**
     * @brief LittlePersonComputer initializes accumulator and program counter to 0.Instructions from the array
     * are copied into memory.Extra slots of memory are initialized to 0.
     * @param instructions array of LPC instructions.
     * @param numberOfInstructions the size of the array of instructions.
     */
    LittlePersonComputer(int instructions[], int numberOfInstructions);

    /**
     * @brief restart sets the accumulator and program counter to 0.
     */
    void restart();


    /**
     * @brief reset sets the accumulator, program counter, and memory to 0.
     */
    void reset();

    /**
     * @brief loadProgram the instruction array provided is copied into the memory array starting at index 0.
     * All memory past the end of the instructions is set to 0.
     * @param instructions the array provided.
     * @param numberOfInstructions the array's size.
     */
    void loadProgram(int instructions[], int numberOfInstructions);

    /**
     * @brief printState prints the current state of the computer.
     */
    void printState();

    /**
     * @brief getCurrentInstruction returns the next instruction to be run.
     * @return next instruction.
     */
    int getCurrentInstruction();

    /**
     * @brief isHalted returns true if the current instruction is 0, otherwise false.
     * @return true or false.
     */
    bool isHalted();

    /**
     * @brief step runs the next instruction according to the list of machine codes.
     */
    void step();

private:
    int memory[20];
    int accumulator = 0;
    int programCounter = 0;
};


#endif // LITTLEPERSONCOMPUTER_H
