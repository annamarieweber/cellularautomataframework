#include "CellularAutomata.h"
#include "ComputeEngine.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.5}}, {"tree", {1, 0.5}}, {"fire", {2, 0.0}}, {"char", {3, 0.0}}};
    CellularAutomata Test1(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});
    //30 steps with majority rule and moore neighborhood;
    Test1.print();

    //Create Simulation 
    ComputeEngine sim1 = ComputeEngine(30,1,1,&Test1);
    
    //run simulation
    sim1.run(); 

    // Testing the creation of a cellular automata when data is directly passed in
    CellularAutomata Test2(10, 10, test_legend_density, "char", "fire", (std::pair<int, int>) {5, 5});
    Test2.print();   

    //30 steps with purity rule and moore neighborhood;
    
    //Create simulation
    ComputeEngine sim2 = ComputeEngine(30,2,1, &Test2);

    //run simulation
    sim2.run();
}