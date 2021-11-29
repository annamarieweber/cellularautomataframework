#include <iostream>
#include <utility>
#include "CellularAutomata.h"
#include "myutils.h"

CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<int> data)
{
    // Will need to ensure that the integers in the legend cover the data that is input, if not it should throw an error.
    _rows = rows;
    _columns = columns;
    _data = data;
    _size = rows*columns;
    _legend = legend;
}

CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, int> legend)
{
    _rows = rows;
    _columns = columns;
    _size = rows*columns;
    _legend = legend;
    // Calls the Initialize function to build a Cellular Automata randomly with the specifications above. May be useful to eventually add a density to each variable in the legend so that the user can specify how much of each to place. This could be done with another map function, which maps the variable to a density.
    CellularAutomata::Initialize();
}

void CellularAutomata::Initialize()
{   
    // Grabs the max element in the legend map.
    int max = 0;
    for(auto it = _legend.begin(); it != _legend.end(); ++it )
    {
        if (it->second > max) 
        {
            max = it->second;
        }
    }
    std::cout << "Max value is: " << max << std::endl;

    
    // Grabs the min element in the legend map.
    int min = 2000;
    for(auto it = _legend.begin(); it != _legend.end(); ++it )
    {
        if (it->second < min) 
        {
            min = it->second;
        }
    }
    std::cout << "Min value is: " << min << std::endl;
    
    // Randomly generates integers from min to max and places it into the vector containing the data for the Cellular Automata.
    for (int i = 0; i < _size; i++)
    {
        _data.push_back(generate_rand_int(min, max));
    }
    
}

void CellularAutomata::vn_neighborhood(int row, int column)
{
    int index = row*column;

    int west = (_size + ((index - 1) % _size)) % _size;
    int east = (_size + ((index + 1) % _size)) % _size;
    int north = (_size + ((index - _columns) % _size)) % _size;
    int south = (_size + ((index + _columns) % _size)) % _size;

    std::cout << "East neighbour is: " << _data[east] << std::endl;
    std::cout << "West neighbour is: " << _data[west] << std::endl;
    std::cout << "North neighbour is: " << _data[north] << std::endl;
    std::cout << "South neighbour is: " << _data[south] << std::endl;
}

void CellularAutomata::moore_neighborhood(int row, int column)
{
    // This is harder so I have not yet done it XD.
}

// Part 3: Output services, this is a tempory print that is being used to test if the Initialize function is working as intended.
// Print the formatted matrix out to the terminal using std::cout. Each row is printed with the first element of the matrix following an opening square bracket and all elements being seperated by commas. The last element of the matrix is also followed by a closing square bracket.
void CellularAutomata::print()
{
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _columns; j++)
        {
            if ((i == _rows-1) && (j == _columns-1))
            {
                std::cout << _data[i * _columns + j] << "]";
            }
            else if ((i == 0) && (j == 0))
            {
                std::cout << "[" << _data[i * _columns + j] << ", ";
            }
            else
            {
                std::cout << _data[i * _columns + j] << ", ";
            }
        }
        std::cout << std::endl;
    }
}