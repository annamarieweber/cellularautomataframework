/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021
  This file, utils.cxx, contains the functions and routines
  to get time points, calculate elapsed time and generate random integers.
  
*/

#include "myutils.h"
#include <iostream>
#include <chrono>
#include <random>
/*
get_wallclock()
  returns the current wall clock time as a std::chrono::time_point using chronos high_resolution_clock function.
  input: nothing
  output: nothing
*/
std::chrono::high_resolution_clock::time_point get_wallclock()
{
  return std::chrono::high_resolution_clock::now();
}

/*
get_elapsedtime()
  returns nothing.
  input: t1 - the starting time for the code block as a std::chrono::time_point
  t2 - the ending time for the code block as a std::chrono::time_point
  output: prints a sentence which contains the time taken in seconds and microseconds
  to the terminal.
*/
void get_elapsedtime(std::chrono::high_resolution_clock::time_point t1, std::chrono::high_resolution_clock::time_point t2)
{
  std::chrono::duration<double> elapsed = (t2-t1);
  long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  std::cout << "The code block took " << elapsed.count() << " s or " << microseconds << " μs to run." << std::endl;
}
/*
generate_rand_int()
  returns a random integer.
  input: max - the largest number you want to accept. The random number will be between 1 and the maximum you set.
  output: nothing.
*/
int generate_rand_int(int min, int max)
{
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(min, max);
    int n = distr(generator);
    return n;
}
