# CPPND: Capstone Snake Game Example

This project is based on the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg


## Enhancements to the game

Additional food objects spawn based on snake size achieved. The modificationt to the snake size and speed depends on the food consumed.
Parallel thread implemented to get controller input.


## Project Requirements (Rubrics) completed 

| Criteria                                                |  Status | File/Remark|
| ------------------------------------------------------- | --------|---------|
| A README with instructions is included with the project | Done|README.md
| The README indicates which project is chosen.| Done|README.md
|The README includes information about each rubric point addressed.|Done|README.md

## Compiling and Testing (All Rubric Points REQUIRED)
| Criteria                                                |  Status | File/Remark|
| ------------------------------------------------------- | --------|---------|
| The submission must compile and run. | Done|README.md

## Object Oriented Programming
| Criteria                                                |  Status | File/Remark|
| ------------------------------------------------------- | --------|---------|
| The project uses Object Oriented Programming techniques.| Done| eg. gameThread.h
| Classes use appropriate access specifiers for class members. | Done | All new classes implemented follow this.
| Class constructors utilize member initialization lists. | Done | eg. food() in food.h
| Classes abstract implementation details from their interfaces.| Done| Class methods have been named appropriately and comments added where needed. 
|Classes follow an appropriate inheritance hierarchy.| Done | Classes "banana" and "potion" are derived from base class "food". It contains one pure virtual function "Eaten(..)" at line 17 in food.h.
|Overloaded functions allow the same function to operate on different parameters.| Done | Render(...) function in Render.h has been overloaded
|Derived class functions override virtual base class functions.| Done | Eaten(..) method has been overridden in both banana.cpp and potion.cpp

## Memory Management
| Criteria                                                | Status | Address |
| ------------------------------------------------------- | --------|---------|
| The project makes use of references in function declarations.| Done| Function Eaten(..) in food class takes in a reference parameter. Function Run(..) in Controller class takes in reference parameters

## Concurrency
| Criteria                                                |  Status | Address |
| ------------------------------------------------------- | --------|---------|
|The project uses multithreading.|Done| HandleInput in Controller is run in a parallel thread (line 7 in controller.cpp)
|A mutex or lock is used in the project.|Done| Mutexes for variables "running" (_controlMutex) and "snake" (_snakeMutex) are defined in gameThread class. Locks are positioned appropriately - eg. std::lock_guard used in line 12 in controller.cpp, and std::unique_lock initialized in line 19 in controller.cpp. Locks are also placed in appropriate positions in game.cpp (currently run in main thread) for accessing the snake variable.



