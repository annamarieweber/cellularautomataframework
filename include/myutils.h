/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021
  This file, myutils.h, contains an API to all utility functions
  being used in Chem 274-B labs.
  - walk clock time support to get the time stamp.
  - get elapsed time to calculate the elapsed time from 2 time stamps.
  - create a random integer from a range.
  
*/

/*   
     TIMING ROUTINES
     These functions and routines get the system's wall-clock time 
*/
#include <chrono>
#include <string>
using namespace std;

/**
 * @brief Function to determine the currently wall clock time.
 * 
 * @return std::chrono::high_resolution_clock::time_point. A timepoint.
 */
std::chrono::high_resolution_clock::time_point get_wallclock();

/**
 * @brief Function to calculate the time elapsed between 2 time points.
 * 
 * @param t1 The starting time for the code block as a std::chrono::time_point.
 * @param t2 The ending time for the code block as a std::chrono::time_point.
 */
void get_elapsedtime(std::chrono::high_resolution_clock::time_point t1, std::chrono::high_resolution_clock::time_point t2);

/**
 * @brief Function to generate a random integer.
 * 
 * @param min The smallest number you want to generate.
 * @param max The largest number you want to generate.
 * @return int, an integer between the min and max.
 */
int generate_rand_int(int min, int max);