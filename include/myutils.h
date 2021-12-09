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

/* get_wallclock (): returns the current time based on chronos high_resolution_clock*/
std::chrono::high_resolution_clock::time_point get_wallclock();

/* get_elapsedtime (t1, t2): prints the taken between the start and end of get_wallclock
in seconds and microseconds to the terminal */
void get_elapsedtime(std::chrono::high_resolution_clock::time_point t1, std::chrono::high_resolution_clock::time_point t2);

/* generate_rand_int (max): generates a random integer from 1 to max and returns it. */
int generate_rand_int(int min, int max);