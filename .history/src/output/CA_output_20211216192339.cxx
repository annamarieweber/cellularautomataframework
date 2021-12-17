/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021

 mergesort2.cxx  contains a function that divides the input array into two halves, 
 calls itself for the two halves, and then merges the two sorted halves. 
 merge() function is merges two halves of the array. 
 
 Merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted.
 

MergeSort(arr[], l,  r)
If r > l
     1. middle point to divide the array into two halves:  
             middle m = l+ (r-l)/2
     2. mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge sorted subarrays:
              merge(arr, l, m, r)

C++ program for Merge Sort

*/


#include <iostream>
#include <utility>
#include "CellularAutomata.h"
#include "myutils.h"

// Getter function to retreive the vector  with Cellular Automata Data.
std::vector<std::vector<int>> CellularAutomata::get_data()
{
    std::vector<std::vector<int>> return_data;
    return_data.resize(_rows);
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _columns; j++)
        {
            return_data[i].push_back(_data[i][j]);
        }
    }
    return return_data;
}

// Gives information on the stats of the states in the Cellular Automata.
void CellularAutomata::get_stats()
{
    if (_legend.empty() == false)
    {
        for(const auto &it : _legend)
        {   
            int counter = 0;
            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _columns; j++)
                {
                    if (_data[i][j] == it.second)
                    {
                        counter++;
                    }
                }
            }
            std::cout << "The state: " << it.first << " occupied " << counter << " cells" << std::endl;
        }
    }
    else
    {
        for(const auto &it2 : _legend_density)
        {   
            int counter2 = 0;
            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _columns; j++)
                {
                    if (_data[i][j] == it2.second.first)
                    {
                        counter2++;
                    }
                }
            }
            std::cout << "The state: " << it2.first << " occupied " << counter2 << " cells" << std::endl;
        }
    }
}

// Print the formatted matrix out to the terminal using std::cout. Each row is printed with the first element of the Cellular Automata following an opening square bracket and all elements being seperated by commas. The last element of the Cellular Automata is also followed by a closing square bracket.
void CellularAutomata::print()
{
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _columns; j++)
        {
            if ((i == _rows-1) && (j == _columns-1))
            {
                std::cout << _data[i][j] << "]";
            }
            else if ((i == 0) && (j == 0))
            {
                std::cout << "[" << _data[i][j] << ", ";
            }
            else
            {
                std::cout << _data[i][j] << ", ";
            }
        }
        std::cout << std::endl;
    }
}