#include <iostream>
#include <utility>
#include <math.h> 
#include "CellularAutomata.h"
#include "ComputeEngine.h"
#include "myutils.h"


// Constructors

/**
 * @brief Construct a new Compute Engine object
 * 
 * @param neighborhood_type the int identifier for the type of neighborhood to use
 * @param rule_type the int identifier for the type of rule to use
 * @param steps the number of steps to run the simulation for
 * @param ca the cellular automata to run the simulation on
 */
ComputeEngine::ComputeEngine(int neighborhood_type, int rule_type, int steps, CellularAutomata ca){
  _neighborhood_type = neighborhood_type;
  _rule_type = rule_type;
  _num_steps = steps;
  _ca = ca;
}

// Public Methods

/**
 * @brief Runs simulation with params provided to ComputeEngine
 * 
 */
void ComputeEngine::run(){
   for(int i=0; i < _num_steps; i++){
    step();
    std::cout << "Step " << i << ": " << std::endl;
    _ca.print();
  }
}

/**
 * @brief Runs a single step in the CA simulation using params provided to the compute engine
 */
void ComputeEngine::step(){
  for(int x = 0; x < _ca.get_columns(); x++){
    for(int y = 0; y < _ca.get_rows(); y++){
      //get the vector representing the neighborhood for cell at x,y
      std::vector<int> neighborhood = get_neighborhood(x,y);
      //update CA cell with the value returned by the appropriate transition function
      _ca.update_cell(x,y,transition_function(x,y,neighborhood));
    }
  }
}

// Private Methods

/**
 * @brief Gets the neighborhood for the cell at x,y based on int neighborhood type
 * 
 * @param x the x position of the cell
 * @param y the y position of the cell
 * @return std::vector<int> an array representing the neighborhood 
 */
std::vector<int> ComputeEngine::get_neighborhood(int x, int y){
  switch(_neighborhood_type) {
    case 1:
      return _ca.moore_neighborhood(x,y);
    case 2:
      return _ca.vn_neighborhood(x,y);
    default:
      return _ca.moore_neighborhood(x,y);
  }
}

/**
 * @brief Selects the appropriate transition function to use for calculating the next state for a cell and runs it
 * 
 * @param x the x position of the cell
 * @param y the y position of the cell
 * @param neighborhood a vector of integers representing the cells neighborhood
 * @return int the next value for the cell
 */
int ComputeEngine::transition_function(int x, int y, std::vector<int> neighborhood){
  switch(_rule_type) {
    case 1:
      return majority_rule(x, y, neighborhood);
    case 2:
      return purity_rule(x,y,neighborhood);
    default:
      return _ca.get_cell(x,y);
  }
}


// COMPUTE RULES

/**
 * @brief Calculates the next value for cell using the majority rule
 * 
 * @param x the x position of the cell
 * @param y the y position of the cell
 * @param neighborhood a vector of integers representing the cells neighborhood
 * @return int the next value for the cell
 */
int CellularAutomata::majority_rule(int x, int y, std::vector<int> neighborhood){
  int sum = 0;
  for(int i = 0; i < neighborhood.size(); i++){
    sum += neighborhood[i];
  }

  return round((double)sum/neighborhood.size());
}

/**
 * @brief Calculates the next value for cell using the majority rule
 * 
 * @param x the x position of the cell
 * @param y the y position of the cell
 * @param neighborhood a vector of integers representing the cells neighborhood
 * @return int the next value for the cell
 */
int CellularAutomata::purity_rule(int x, int y, std::vector<int> neighborhood){
  int sum = 0;
  int current_val = _data[x][y];
  for(int i = 0; i < neighborhood.size(); i++){
    sum += (current_val+neighborhood[i]);
  }

  return sum % _num_states;
}

