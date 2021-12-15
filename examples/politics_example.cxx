#include "CellularAutomata.h"
#include "ComputeEngine.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    // Political Cellular Automata example with majority rule and moore neighborhood
    std::cout << "Creating Political Cellular Automata example using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> political_legend_density{{"Republican", {0, 0.5}}, {"Democrat", {1, 0.5}}};
    CellularAutomata politics_example(15, 15, political_legend_density, "Republican", "Democrat", std::pair<int, int> {5, 5});
    // Print Cellular Automata
    politics_example.print();

    // Get stats on the starting states
    politics_example.get_stats();

    // create simulation
    ComputeEngine simulation = ComputeEngine(3,1,2,&politics_example);

    // 3 steps with majority rule and Von Neumaan neighborhood
    simulation.run();

    // Get stats after 3 steps
    politics_example.get_stats();
}