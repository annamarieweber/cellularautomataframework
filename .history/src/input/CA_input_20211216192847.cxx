
/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021

 CA_input.cxx: contains functions with a grid with some cells 
 which may be alive or dead. It generates the next generation of 
 cells based on these rules: live cell with less than two live neighbors dies, live cell with 
 two or three live neighbors lives on to the next generation, live cell with more than three live neighbors dies
 and any dead cell with exactly three live neighbors becomes a live cell(reproduction).

C++ program for Cellular Automata

*/



#include <iostream>
#include <utility>
#include <math.h> 
#include "CellularAutomata.h"
#include "myutils.h"

// Constructor with data being passed in from the user.
CellularAutomata::CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<std::vector<int> > data, std::string product, std::string reactor, std::pair<int, int> starting_position)
{
    // Will need to ensure that the integers in the legend cover the data that is input, if not it should throw an error.
    _rows = rows;
    _columns = columns;
    _data = data;
    _size = rows*columns;
    _num_states = legend.size();
    _legend = legend;
    _product = product;
    _reactor = reactor;
    _starting_position = starting_position;
}

// Constructor with no data, but data is built randomly.
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

// Constructor with no data, and data is built using density values passed in.
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

// Function to initialize cellular automata data randomly.
void CellularAutomata::Initialize_Rand()
{   
    // Grabs the max element in the legend map.
    // Grabs the max element in the legend map, leaving out the reactor and product values (The reactor will be placed specifically by the user and the product will be placed after the compute steps).
    std::cout << "In intialize" << std::endl;
    int max = 0;
    for(const auto &it : _legend)
    {
        if (it.second > max && it.first != _product && it.first != _reactor) 
        {
            max = it.second;
        }
    }

    // Grabs the min element in the legend map.
    // Grabs the min element in the legend map, leaving out the reactor and product values (The reactor will be placed specifically by the user and the product will be placed after the compute steps).
    int min = 2147483647;
    for(auto it = _legend.begin(); it != _legend.end(); ++it )
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

    // Generates the starting position for the reactor variable which will cause changes throughout the Cellular Automata. Acceses using row major
    _data[_starting_position.first][_starting_position.second] = _legend[_reactor]; 
}

// Function to initialize cellular automata data using density.
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

    // Generates the starting position for the reactor variable which will cause changes throughout the Cellular Automata. Acceses using row major
    _data[_starting_position.first][_starting_position.second] = _legend_density[_reactor].first; 
}


// Code to evaluate von neumman neighborhood where r = 1 with periodic bounds.
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

    // std::cout << "North neighbour is: " << north << std::endl;
    // std::cout << "East neighbour is: " << east << std::endl;
    // std::cout << "South neighbour is: " << south << std::endl;
    // std::cout << "West neighbour is: " << west << std::endl;

    return neighborhood;
}

// Code to evaluate moore neighborhood where r = 1 with periodic bounds.
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

std::vector<int> CellularAutomata::get_neighborhood(int x, int y,int neighborhood_num){
  switch(neighborhood_num) {
    case 1:
      return moore_neighborhood(x,y);
    case 2:
      return vn_neighborhood(x,y);
    default:
      return moore_neighborhood(x,y);
  }
}

void CellularAutomata::run(int num_steps, int rule_num, int neighborhood_num){
  for(int i=0; i < num_steps; i++){
    step(rule_num, neighborhood_num);
    std::cout << "Step " << i << ": " << std::endl;
    print();
  }
}

//logic for taking a single step of the CA simluation todo: document the funciton
void CellularAutomata::step(int rule_num, int neighborhood_num){
  for(int x = 0; x < _columns; x++){
    for(int y = 0; y < _rows; y++){
      std::vector<int> neighborhood = get_neighborhood(x,y,neighborhood_num);
      _data[x][y] = transition_function(x,y,rule_num,neighborhood);
    }
  }
}


int CellularAutomata::transition_function(int x, int y, int rule_num, std::vector<int> neighborhood){
  switch(rule_num) {
    case 1:
      return majority_rule(x, y, neighborhood);
    case 2:
      return purity_rule(x,y,neighborhood);
    default:
      return _data[x][y];
  }
}

// logic for the majority rule todo:  add additional function documentation
int CellularAutomata::majority_rule(int x, int y, std::vector<int> neighborhood){
  int sum = 0;
  for(int i = 0; i < neighborhood.size(); i++){
    sum += neighborhood[i];
  }

  return round((double)sum/neighborhood.size());
}

// logic for the purity rule todo:  add additional function documentation
int CellularAutomata::purity_rule(int x, int y, std::vector<int> neighborhood){
  int sum = 0;
  int current_val = _data[x][y];
  for(int i = 0; i < neighborhood.size(); i++){
    sum += (current_val+neighborhood[i]);
  }

  return sum % _num_states;
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
