#include "CellularAutomata.h"
#include "ComputeEngine.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    // Example 1:
    // Political Cellular Automata example with majority rule and moore neighborhood made with densities
    std::cout << "Creating Political Cellular Automata example using majority rule and Moore neighborhood with densities: " << std::endl;
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
    ComputeEngine simulation = ComputeEngine(3,1,1,&politics_example);

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
    std::cout << std::endl;


    // Example 2:
    // Political Cellular Automata example with majority rule and von neumaann neighborhood made randomly
    std::cout << "Creating Political Cellular Automata example using majority rule and Von Neumaann neighborhood randomly: " << std::endl;
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
    std::cout << std::endl;


    // Example 3:
    // Political Cellular Automata example with parity rule and Moore neighborhood made randomly
    std::cout << "Creating Political Cellular Automata example using parity rule and moore neighborhood randomly: " << std::endl;
    // Adding NULL for the reactor and product states is important because there are no reactor and product states.
    CellularAutomata politics_example_rand_2(50, 50, political_legend, "NULL", "NULL", std::pair<int, int> {5, 5});
    
    // Print Cellular Automata
    std::cout << "Cellular Automata intial configuration:" << std::endl;
    politics_example_rand_2.print();
    std::cout << std::endl;

    // Get stats on the starting states
    std::cout << "Cellular Automata intial states:" << std::endl;
    politics_example_rand_2.get_stats();
    std::cout << std::endl;

    // create simulation
    ComputeEngine simulation_rand_2 = ComputeEngine(100,2,1,&politics_example_rand_2);

    // 100 steps with parity rule and Moore neighborhood
    std::cout << std::endl;
    std::cout << "Running the simulation for 100 steps with parity rules and Moore neighborhood..." << std::endl;
    std::cout << std::endl;
    simulation_rand_2.run();

    // Print Cellular Automata after 100 steps
    std::cout << "Cellular Automata configuration after 100 steps:" << std::endl;
    politics_example_rand_2.print();
    std::cout << std::endl;

    // Get stats after 100 steps
    std::cout << "Cellular Automata states after 100 steps:" << std::endl;
    politics_example_rand_2.get_stats();
    std::cout << std::endl;
    std::cout << std::endl;


    // Example 3:
    // Political Cellular Automata example with parity rule and Von Neumaann neighborhood made randomly
    std::cout << "Creating Political Cellular Automata example using parity rule and Von Neumaann neighborhood randomly: " << std::endl;
    // Adding NULL for the reactor and product states is important because there are no reactor and product states.
    CellularAutomata politics_example_rand_3(50, 50, political_legend, "NULL", "NULL", std::pair<int, int> {5, 5});
    
    // Print Cellular Automata
    std::cout << "Cellular Automata intial configuration:" << std::endl;
    politics_example_rand_3.print();
    std::cout << std::endl;

    // Get stats on the starting states
    std::cout << "Cellular Automata intial states:" << std::endl;
    politics_example_rand_3.get_stats();
    std::cout << std::endl;

    // create simulation
    ComputeEngine simulation_rand_3 = ComputeEngine(100,2,2,&politics_example_rand_3);

    // 100 steps with parity rule and Moore neighborhood
    std::cout << std::endl;
    std::cout << "Running the simulation for 100 steps with parity rules and Moore neighborhood..." << std::endl;
    std::cout << std::endl;
    simulation_rand_3.run();

    // Print Cellular Automata after 100 steps
    std::cout << "Cellular Automata configuration after 100 steps:" << std::endl;
    politics_example_rand_3.print();
    std::cout << std::endl;

    // Get stats after 100 steps
    std::cout << "Cellular Automata states after 100 steps:" << std::endl;
    politics_example_rand_3.get_stats();
    std::cout << std::endl;
}