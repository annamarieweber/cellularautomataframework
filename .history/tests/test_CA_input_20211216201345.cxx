/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021

  test_CA_input.cxx makes calls to a different functions implemented in the input services cellular automata object file.

*/

#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>


int main(void)
{
    // Testing the creation of a cellular automata when data is directly passed in
    std::cout << "Creating Cellular Automata given data: " << std::endl;
    std::vector<std::vector<int>> test = {{1, 1, 1}, {1, 0, 1}, {0, 1, 2}};
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};
    CellularAutomata Test(3, 3, test_legend, test, "char", "fire", std::pair<int, int> {2, 2});
    Test.print();    
    // Testing von neumaan neighborhood analysis
    std::cout << "Testing Von Neumaan Neighborhood funtionality around 2,2:" << std::endl;
    Test.vn_neighborhood(2, 2);
    std::cout << std::endl;
    std::cout << "Testing Von Neumaan Neighborhood funtionality and periodic bounds around 0,0:" << std::endl;
    Test.vn_neighborhood(0, 0);
    std::cout << std::endl;
    std::cout << "Testing Moore Neighborhood funtionality around 5,5:" << std::endl;
    // Testing moore neighborhood analysis
    Test.moore_neighborhood(1, 1);
    std::cout << std::endl;
    std::cout << std::endl;

    // Testint the creation of a cellular automata when data is directly passed in
    std::cout << "Creating Cellular Automata Randomly: " << std::endl;
    CellularAutomata Test_2(10, 10, test_legend, "char", "fire", std::pair<int, int> {5, 5});
    Test_2.print();
    // Testing von neumaan neighborhood analysis
    std::cout << "Testing Von Neumaan Neighborhood funtionality around 5, 5:" << std::endl;
    Test_2.vn_neighborhood(5,5);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.5}}, {"tree", {1, 0.5}}, {"fire", {2, 0.0}}, {"char", {3, 0.0}}};
    CellularAutomata Test_3(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});
    Test_3.print();
    Test_3.vn_neighborhood(5,5);
    std::cout << std::endl;
    std::cout << "Testing Moore Neighborhood funtionality and periodic bounds around 0,5:" << std::endl;
    // Testing moore neighborhood analysis
    Test_3.moore_neighborhood(0,5);
    std::cout << std::endl;
    std::cout << std::endl;
}