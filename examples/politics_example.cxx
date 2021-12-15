#include "CellularAutomata.h"
#include "ComputeEngine.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    
    // Political Cellular Automata example with majority rule and moore neighborhood made with densities
    std::cout << "Creating Political Cellular Automata example using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> political_legend_density{{"Republican", {0, 0.3}}, {"Democrat", {1, 0.7}}};
    // Adding NULL for the reactor and product states is important because there are no reactor and product states.
    CellularAutomata politics_example(15, 15, political_legend_density, "NULL", "NULL", std::pair<int, int> {5, 5});
    
    // Print Cellular Automata
    std::cout << "Cellular Automata intial configuration:" << std::endl;
    politics_example.print();
    std::cout << std::endl;

    // Get stats on the starting states
    std::cout << "Cellular Automata intial states:" << std::endl;
    politics_example.get_stats();
    std::cout << std::endl;

    // create simulation
    ComputeEngine simulation = ComputeEngine(3,1,2,&politics_example);

    // 3 steps with majority rule and Von Neumaan neighborhood
    simulation.run();

    // Print Cellular Automata after 3 steps
    std::cout << "Cellular Automata configuration after 3 steps:" << std::endl;
    politics_example.print();
    std::cout << std::endl;

    // Get stats after 3 steps
    std::cout << "Cellular Automata states after 3 steps:" << std::endl;
    politics_example.get_stats();
    std::cout << std::endl;

    // Political Cellular Automata example with majority rule and moore neighborhood made randomly
    std::cout << "Creating Political Cellular Automata example using Randomly: " << std::endl;
    std::map<std::string, int> political_legend{{"Conservative", 0}, {"Liberal", 1}};
    // Adding NULL for the reactor and product states is important because there are no reactor and product states.
    CellularAutomata politics_example_rand(15, 15, political_legend, "NULL", "NULL", std::pair<int, int> {5, 5});
    
    // Print Cellular Automata
    std::cout << "Cellular Automata intial configuration:" << std::endl;
    politics_example_rand.print();
    std::cout << std::endl;

    // Get stats on the starting states
    std::cout << "Cellular Automata intial states:" << std::endl;
    politics_example_rand.get_stats();
    std::cout << std::endl;

    // create simulation
    ComputeEngine simulation_rand = ComputeEngine(3,1,2,&politics_example_rand);

    // 3 steps with majority rule and Von Neumaan neighborhood
    simulation_rand.run();

    // Print Cellular Automata after 3 steps
    std::cout << "Cellular Automata configuration after 3 steps:" << std::endl;
    politics_example_rand.print();
    std::cout << std::endl;

    // Get stats after 3 steps
    std::cout << "Cellular Automata states after 3 steps:" << std::endl;
    politics_example_rand.get_stats();
    std::cout << std::endl;
}