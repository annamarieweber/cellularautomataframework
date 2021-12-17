/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021

  test_CA_output.cxx makes calls to a different functions implemented in the output services for cellular automata object file.

*/

#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    // Test #1
    // Data needed to create CA
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};

    // Creating Cellular Automata 
    std::cout << "Creating Cellular Automata Randomly: " << std::endl;
    CellularAutomata Test_2(10, 10, test_legend, "char", "fire", std::pair<int, int> {5, 5});

    // Testing the Cellular Automata printing to terminal.
    Test_2.print();
    std::cout << std::endl;
    std::cout << std::endl;

    // Testing getting stats on the Cellular Automata.
    Test_2.get_stats();
    std::cout << std::endl;
    std::cout << std::endl;

    // Test #2
    // Creating Cellular Automata 
    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.5}}, {"tree", {1, 0.5}}, {"fire", {2, 0.0}}, {"char", {3, 0.0}}};
    CellularAutomata Test_3(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});

    // Testing the Cellular Automata printing to terminal.
    Test_3.print();
    std::cout << std::endl;
    std::cout << std::endl;

    // Testing getting stats on the Cellular Automata.
    Test_3.get_stats();
}