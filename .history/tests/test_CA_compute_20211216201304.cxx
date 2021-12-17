/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021

  test_CA_compute.cxx makes calls to a different functions implemented in the heapsort object file.

*/

#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.1}}, {"tree", {1, 0.04}}, {"fire", {2, 0.7}}, {"char", {3, 0.16}}};
    CellularAutomata Test1(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});
    //3 steps with majority rule and moore neighborhood;
    Test1.run(30,1,1); 

    // Testing the creation of a cellular automata when data is directly passed in
    CellularAutomata Test2(10, 10, test_legend_density, "char", "fire", (std::pair<int, int>) {5, 5});
    Test2.print();   

    //3 steps with purity rule and moore neighborhood;
    Test2.run(30,2,1); 
}