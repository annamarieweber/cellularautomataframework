/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021
  This file, CellularAutomata.h, contains an API to the ComputeEngine class.
  being used in Chem 274-B final project.
*/

#ifndef _CELLULAR_AUTOMATA_
#include "CellularAutomata.h"
#endif
#include <vector>

class ComputeEngine {
  private:
    int _neighborhood_type;
    int _rule_type;
    int _num_steps;
    CellularAutomata* _ca;
  
    /**
   * @brief Calculates the next value for cell using the majority rule
   * 
   * @param x the x position of the cell
   * @param y the y position of the cell
   * @param neighborhood a vector of integers representing the cells neighborhood
   * @return int the next value for the cell
   */
    int majority_rule(int x, int y, std::vector<int> neighborhood);

    /**
   * @brief Calculates the next value for cell using the majority rule
   * 
   * @param x the x position of the cell
   * @param y the y position of the cell
   * @param neighborhood a vector of integers representing the cells neighborhood
   * @return int the next value for the cell
   */
    int purity_rule(int x, int y, std::vector<int> neighborhood);

    /**
   * @brief Gets the neighborhood for the cell at x,y based on int neighborhood type
   * 
   * @param x the x position of the cell
   * @param y the y position of the cell
   * @return std::vector<int> an array representing the neighborhood 
   */
    std::vector<int> get_neighborhood(int x, int y);

    /**
   * @brief Selects the appropriate transition function to use for calculating the next state for a cell and runs it
   * 
   * @param x the x position of the cell
   * @param y the y position of the cell
   * @param neighborhood a vector of integers representing the cells neighborhood
   * @return int the next value for the cell
   */
    int transition_function(int x, int y, std::vector<int> neighborhood);

  public:
    /**
   * @brief Construct a new Compute Engine object
   * 
   * @param neighborhood_type the int identifier for the type of neighborhood to use
   * @param rule_type the int identifier for the type of rule to use
   * @param steps the number of steps to run the simulation for
   * @param ca the cellular automata to run the simulation on
   */
    ComputeEngine(int neighborhood_type, int rule_type, int steps, CellularAutomata* ca);

    /**
   * @brief Runs simulation with params provided to ComputeEngine
   * 
   */
    void run();

    /**
   * @brief Runs a single step in the CA simulation using params provided to the compute engine
   */
    void step();
};
