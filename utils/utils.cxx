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

/**
 * @brief Function to determine the currently wall clock time.
 * 
 * @return std::chrono::high_resolution_clock::time_point. A timepoint.
 */
std::chrono::high_resolution_clock::time_point get_wallclock()
{
  return std::chrono::high_resolution_clock::now();
}

/**
 * @brief Function to calculate the time elapsed between 2 time points.
 * 
 * @param t1 The starting time for the code block as a std::chrono::time_point.
 * @param t2 The ending time for the code block as a std::chrono::time_point.
 */
void get_elapsedtime(std::chrono::high_resolution_clock::time_point t1, std::chrono::high_resolution_clock::time_point t2)
{
  std::chrono::duration<double> elapsed = (t2-t1);
  long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  std::cout << "The code block took " << elapsed.count() << " s or " << microseconds << " μs to run." << std::endl;
}

/**
 * @brief Function to generate a random integer.
 * 
 * @param min The smallest number you want to generate.
 * @param max The largest number you want to generate.
 * @return int, an integer between the min and max.
 */
int generate_rand_int(int min, int max)
{
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(min, max);
    int n = distr(generator);
    return n;
}
