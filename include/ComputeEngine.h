#include "CellularAutomata.h"

class ComputeEngine {
  private:
    int _neighborhood_type;
    int _rule_type;
    int _num_steps;
    CellularAutomata _ca;

    // logic for the majority rule todo:  add additional function documentation
    int majority_rule(int x, int y, std::vector<int> neighborhood);
    // logic for the purity rule todo:  add additional function documentation
    int purity_rule(int x, int y, std::vector<int> neighborhood);
    //code to get the appropriate neighborhood
    std::vector<int> get_neighborhood(int x, int y);
    // code to apply transition rule using neighborhood data
    int transition_function(int x, int y, std::vector<int> neighborhood);

  public:
    ComputeEngine(int neighborhood_type, int rule_type, int steps, CellularAutomata ca);
    // Code to run Cellular Automata Simulation
    void run();
    //logic for taking a single step of the CA simluation todo: document the funciton
    void step();
};
