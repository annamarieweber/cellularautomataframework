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

    // logic for the majority rule todo:  add additional function documentation
    int majority_rule(int x, int y, std::vector<int> neighborhood);
    // logic for the purity rule todo:  add additional function documentation
    int purity_rule(int x, int y, std::vector<int> neighborhood);
    //code to get the appropriate neighborhood
    std::vector<int> get_neighborhood(int x, int y);
    // code to apply transition rule using neighborhood data
    int transition_function(int x, int y, std::vector<int> neighborhood);

  public:
    ComputeEngine(int neighborhood_type, int rule_type, int steps, CellularAutomata* ca);
    // Code to run Cellular Automata Simulation
    void run();
    //logic for taking a single step of the CA simluation todo: document the funciton
    void step();
};
