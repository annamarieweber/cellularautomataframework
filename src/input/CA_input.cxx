#include <iostream>
#include <utility>
#include "CellularAutomata.h"
#include "myutils.h"

CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<int> data, std::string product, std::string reactor, std::pair<int, int> starting_position)
{
    // Will need to ensure that the integers in the legend cover the data that is input, if not it should throw an error.
    _rows = rows;
    _columns = columns;
    // Data will be stored in row major format.
    _data = data;
    _size = rows*columns;
    _legend = legend;
    _product = product;
    _reactor = reactor;
    _starting_position = starting_position;
}

CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::string product, std::string reactor, std::pair<int, int> starting_position)
{
    _rows = rows;
    _columns = columns;
    _size = rows*columns;
    _legend = legend;
    _product = product;
    _reactor = reactor;
    _starting_position = starting_position;
    // Calls the Initialize function to build a Cellular Automata randomly with the specifications above. May be useful to eventually add a density to each variable in the legend so that the user can specify how much of each to place. This could be done with another map function, which maps the variable to a density.
    CellularAutomata::Initialize();
}

void CellularAutomata::Initialize()
{   
    // Grabs the max element in the legend map, leaving out the reactor and product values (The reactor will be placed specifically by the user and the product will be placed after the compute steps).
    int max = 0;
    for(const auto &it : _legend)
    {
        if (it.second > max && it.first != _product && it.first != _reactor) 
        {
            max = it.second;
        }
    }
    std::cout << "Max value is: " << max << std::endl;

    // Grabs the min element in the legend map, leaving out the reactor and product values (The reactor will be placed specifically by the user and the product will be placed after the compute steps).
    int min = 2000;
    for(const auto &it2 : _legend)
    {
        if (it2.second < min && it2.first != _product && it2.first != _reactor) 
        {
            min = it2.second;
        }
    }
    std::cout << "Min value is: " << min << std::endl;
    
    // Randomly generates integers from min to max and places it into the vector containing the data for the Cellular Automata.
    for (int i = 0; i < _size; i++)
    {
        _data.push_back(generate_rand_int(min, max));
    }

    // Generates the starting position for the reactor variable which will cause changes throughout the Cellular Automata. Acceses using row major
    int index = _starting_position.first * _columns + _starting_position.second;
    _data[index] = _legend[_reactor]; 
}

// Code to evaluate von neumman neighborhood.
void CellularAutomata::vn_neighborhood(int row, int column)
{
    int index = row * _columns + column;

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

// Temporary print that is being used to test if the Initialize function is working as intended.
// Print the formatted matrix out to the terminal using std::cout. Each row is printed with the first element of the Cellular Automata following an opening square bracket and all elements being seperated by commas. The last element of the Cellular Automata is also followed by a closing square bracket.
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