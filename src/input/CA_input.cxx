#include <iostream>
#include <utility>
#include <math.h> 
#include "CellularAutomata.h"
#include "myutils.h"

/**
 * @brief Construct a new Cellular Automata:: Cellular Automata object. Default Constructor.
 * 
 */
CellularAutomata::CellularAutomata(){

}

/**
 * @brief Construct a new Cellular Automata:: Cellular Automata object. Constructor with data being passed in from the user.
 * 
 * @param rows Number of rows for the Cellular Automata matrix.
 * @param columns Number of columns for the Cellular Automata matrix.
 * @param legend A map including the name of the state as a string (key) and its corresponding integer value (value)
 * @param data A vector of vectors holding data for the Cellular Automata matrix.
 * @param product The name of the state which is a produced by rules acting on other states.
 * @param reactor The name of the state which acts on other states through rules.
 * @param starting_position The starting coordinates for the reactor state as a pair of integers.
 */
CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<std::vector<int> > data, std::string product, std::string reactor, std::pair<int, int> starting_position)
{
    _rows = rows;
    _columns = columns;
    _data = data;
    _size = rows*columns;
    _num_states = legend.size();
    _legend = legend;
    _product = product;
    _reactor = reactor;
    _starting_position = starting_position;

    // Generates the starting position for the reactor variable which will cause changes throughout the Cellular Automata.
    _data[_starting_position.first][_starting_position.second] = _legend[_reactor];
}

/**
 * @brief Construct a new Cellular Automata:: Cellular Automata object. Constructor with no data where data is generated randomly.
 * 
 * @param rows Number of rows for the Cellular Automata matrix.
 * @param columns Number of columns for the Cellular Automata matrix.
 * @param legend A map including the name of the state as a string (key) and its corresponding integer value (value)
 * @param product The name of the state which is a produced by rules acting on other states.
 * @param reactor The name of the state which acts on other states through rules.
 * @param starting_position The starting coordinates for the reactor state as a pair of integers. 
 */
CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::string product, std::string reactor, std::pair<int, int> starting_position)
{
    _rows = rows;
    _columns = columns;
    _size = rows*columns;
    _num_states = legend.size();
    _legend = legend;
    _product = product;
    _reactor = reactor;
    _starting_position = starting_position;
    // Builds the initial _data structure to have enough vectors inside the vector of vectors to hold the data. This is equal to the bumber of rows.
    _data.resize(_rows);
    // Calls the Initialize function to build a Cellular Automata randomly with the specifications above.
    CellularAutomata::Initialize_Rand();
}

/**
 * @brief Construct a new Cellular Automata:: Cellular Automata object. Constructor with no data, and data is generated using density values passed in via legend.
 * 
 * @param rows Number of rows for the Cellular Automata matrix.
 * @param columns Number of columns for the Cellular Automata matrix.
 * @param legend A map including the name of the state as a string (key) and its value being a pair of integer and float, corresponding to the states integer value and density.
 * @param product The name of the state which is a produced by rules acting on other states.
 * @param reactor The name of the state which acts on other states through rules.
 * @param starting_position The starting coordinates for the reactor state as a pair of integers. 
 */
CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, std::pair<int, float> > legend, std::string product, std::string reactor, std::pair<int, int> starting_position)
{
    _rows = rows;
    _columns = columns;
    _size = rows*columns;
    _num_states = legend.size();
    _legend_density = legend;
    _product = product;
    _reactor = reactor;
    _starting_position = starting_position;

    // Builds the intial _data structure so that the vector of vector has values in it which will be replaced based on the densities of the variables.
    _data.resize(_rows);
    for (int row = 0; row < _rows; row++)
    {
        for (int column = 0; column < _columns; column++)
        {
            _data[row].push_back(0);
        }
    }
    // Calls the Initialize function to build a Cellular Automata using densities given in the specifications above.
    CellularAutomata::Initialize_Density();
}

/**
 * @brief Copy Constructor to create a new Cellular Automata:: Cellular Automata object.
 * 
 * @param ca Cellular Automata object.
 */
CellularAutomata::CellularAutomata(const CellularAutomata& ca){
    _rows = ca._rows;
    _columns = ca._columns;
    _data = ca._data;
    _size = _rows*_columns;
    _num_states = ca._legend.size();
    _legend = ca._legend;
    _product = ca._product;
    _reactor = ca._reactor;
    _starting_position = ca._starting_position;
}

/**
 * @brief Function to initialize cellular automata data randomly.
 * 
 */
void CellularAutomata::Initialize_Rand()
{   
    // Grabs the max element in the legend map, leaving out the reactor and product values (The reactor will be placed specifically by the user and the product will be placed after the compute/rules steps).
    int max = 0;
    for(const auto &it : _legend)
    {
        if (it.second > max && it.first != _product && it.first != _reactor) 
        {
            max = it.second;
        }
    }

    // Grabs the min element in the legend map, leaving out the reactor and product values (The reactor will be placed specifically by the user and the product will be placed after the compute/rules steps).
    int min = 2147483647;
    for(const auto &it2 : _legend)
    {
        if (it2.second < min && it2.first != _product && it2.first != _reactor) 
        {
            min = it2.second;
        }
    }

    // Builds the Cellular automata randomly using the min and max values gotten above.
    for (int row = 0; row < _rows; row++)
    {
        for (int column = 0; column < _columns; column++)
        {
            _data[row].push_back(generate_rand_int(min, max));
        }
    }

    // Generates the starting position for the reactor variable which will cause changes throughout the Cellular Automata.
    if (_legend.find(_reactor) != _legend.end())
    {
        _data[_starting_position.first][_starting_position.second] = _legend[_reactor]; 
    }
}

/**
 * @brief Function to initialize cellular automata data using density.
 * 
 */
void CellularAutomata::Initialize_Density()
{
    // Sets the seed for the random float generator below
    srand (static_cast <unsigned> (time(0)));
    // Iterates through the legend map creates the cellular automata based on the density value.
    for (int row = 0; row < _rows; row++)
    {
        for (int column = 0; column < _columns; column++)
        {
            for(const auto &it : _legend_density)
            {
                if (it.second.second != 0.0)
                {
                    // Generates a random floating number from 0.0 to 1.0
                    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
                    // If the number is less than the density value, then the value at that data index is equal to the value of the variable.
                    if (r < it.second.second)
                    {
                        _data[row][column] = (it.second.first);
                    }
                }
            }
        }
    }

    // Generates the starting position for the reactor variable which will cause changes throughout the Cellular Automata.
    if (_legend_density.find(_reactor) != _legend_density.end())
    {
    _data[_starting_position.first][_starting_position.second] = _legend_density[_reactor].first; 
    }
}

/**
 * @brief Code to evaluate Von Neumaan neighborhood where r = 1 with periodic bounds.
 * 
 * @param row Index of the row of the value you want to evaluate the Von Neumaan neighborhood for.
 * @param column Index of the column of the value you want to evaluate the Von Neumaan neighborhood for.
 * @return std::vector<int>, a vector containing all the neighbors in the order of North, West, East, and South.
 */
std::vector<int> CellularAutomata::vn_neighborhood(int row, int column)
{
    std::vector<int> neighborhood;
    int north = _data[(_rows + ((row-1) % _rows) ) % _rows][column];
    neighborhood.push_back(north);
    int west = _data[row][(_columns + ((column - 1) % _columns)) % _columns];
    neighborhood.push_back(west);
    int east = _data[row][(_columns + ((column + 1) % _columns)) % _columns];
    neighborhood.push_back(east);
    int south = _data[(_rows + ((row+1) % _rows) ) % _rows][column];
    neighborhood.push_back(south);

    // Trouble shooting help.
    // std::cout << "North neighbour is: " << north << std::endl;
    // std::cout << "East neighbour is: " << east << std::endl;
    // std::cout << "South neighbour is: " << south << std::endl;
    // std::cout << "West neighbour is: " << west << std::endl;

    return neighborhood;
}

/**
 * @brief Code to evaluate Moore neighborhood where r = 1 with periodic bounds.
 * 
 * @param row Index of the row of the value you want to evaluate the Von Neumaan neighborhood for.
 * @param column Index of the column of the value you want to evaluate the Von Neumaan neighborhood for.
 * @return std::vector<int>, a vector containing all the neighbors in the order of North West, North, North East, West, East, South West, South, South East.
 */
std::vector<int> CellularAutomata::moore_neighborhood(int row, int column)
{
    int north = _data[(_rows + ((row-1) % _rows) ) % _rows][column];
    int north_east = _data[(_rows + ((row-1) % _rows) ) % _rows][(_columns + ((column + 1) % _columns)) % _columns];
    int east = _data[row][(_columns + ((column + 1) % _columns)) % _columns];
    int south_east = _data[(_rows + ((row+1) % _rows) ) % _rows][(_columns + ((column + 1) % _columns)) % _columns];
    int south = _data[(_rows + ((row+1) % _rows) ) % _rows][column];
    int south_west = _data[(_rows + ((row+1) % _rows) ) % _rows][(_columns + ((column - 1) % _columns)) % _columns];
    int west = _data[row][(_columns + ((column - 1) % _columns)) % _columns];
    int north_west = _data[(_rows + ((row-1) % _rows) ) % _rows][(_columns + ((column - 1) % _columns)) % _columns];

    std::vector<int> neighborhood;
    neighborhood.push_back(north_west);
    neighborhood.push_back(north);
    neighborhood.push_back(north_east);
    neighborhood.push_back(west);
    neighborhood.push_back(east);
    neighborhood.push_back(south_west);
    neighborhood.push_back(south);
    neighborhood.push_back(south_east);

    // Trouble shooting help.
    // std::cout << "North neighbour is: " << north << std::endl;
    // std::cout << "North East neighbour is: " << north_east << std::endl;
    // std::cout << "East neighbour is: " << east << std::endl;
    // std::cout << "South East neighbour is: " << south_east << std::endl;    
    // std::cout << "South neighbour is: " << south << std::endl;
    // std::cout << "South West neighbour is: " << south_west << std::endl;
    // std::cout << "West neighbour is: " << west << std::endl;
    // std::cout << "North West neighbour is: " << north_west << std::endl;

    return neighborhood;
}

/**
 * @brief Update the value in the cell at x,y with the value n
 * 
 * @param x the x position of the cell
 * @param y the y position of the cell
 * @param n the value change the cell to
 */
void CellularAutomata::update_cell(int x, int y, int n){
  _data[x][y] = n;
}

/**
 * @brief gets the value of the cell at x, y
 * 
 * @param x the x position of the cell
 * @param y the y position of the cell
 * @return int the value of the cell
 */
int CellularAutomata::get_cell(int x, int y){
  return _data[x][y];
}

/**
 * @brief Get the number of rows in the CA
 * 
 * @return int number of rows
 */
int CellularAutomata::get_rows(){
  return _rows;
}

/**
 * @brief Get the number of columns in the CA
 * 
 * @return int number of columns
 */
int CellularAutomata::get_columns(){
  return _columns;
}

/**
 * @brief Get the total number of cells in the CA
 * 
 * @return int number of cells
 */
int CellularAutomata::get_size(){
  return _size;
}

/**
 * @brief Get the number of possible states for a cell in the CA
 * 
 * @return int number of possible states
 */
int CellularAutomata::get_num_states(){
  return _num_states;
}