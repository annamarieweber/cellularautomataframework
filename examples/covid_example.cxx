#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    // COVID example with majority rule and moore neighborhood
    std::cout << "Creating COVID Cellular Automata example using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> covid_legend_density{{"empty", {0, 0.5}}, {"uninfected", {1, 0.5}}, {"infected", {2, 0.0}}, {"dead", {3, 0.0}}};
    CellularAutomata covid_example(15, 15, covid_legend_density, "dead", "infected", std::pair<int, int> {5, 5});
    // Print Cellular Automata
    covid_example.print();

    // Get stats on the starting states
    covid_example.get_stats();

    // 3 steps with majority rule and moore neighborhood
    covid_example.run(3, 1, 1);

    // Get stats after 3 steps
    covid_example.get_stats();

}