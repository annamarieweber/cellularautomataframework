#include "CellularAutomata.h"
#include "ComputeEngine.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    // Test #1
    // Testing the creation of a cellular automata when data is generated using densities passed in
    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.5}}, {"tree", {1, 0.5}}, {"fire", {2, 0.0}}, {"char", {3, 0.0}}};
    CellularAutomata Test1(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});
    
    // Print out the intial matrix for the Cellular Automata.   
    std::cout << "The intial matrix state: " << std::endl;
    Test1.print();

    //Create Simulation 
    //30 steps with majority rule and moore neighborhood;
    ComputeEngine sim1 = ComputeEngine(30,1,1,&Test1);
    
    //run simulation
    std::cout << std::endl;
    std::cout << "Running the simulation for 30 steps with majority rules and Moore neighborhood..." << std::endl;
    std::cout << std::endl;
    sim1.run(); 

    // Print out the final matrix for the Cellular Automata.
    std::cout << "The Final matrix state: " << std::endl;
    Test1.print();
    std::cout << std::endl;
    std::cout << std::endl;

    // Test #2
    // Testing the creation of a cellular automata when data is generated using densities passed in
    CellularAutomata Test2(15, 15, test_legend_density, "char", "fire", (std::pair<int, int>) {5, 5});
    
    // Print out the intial matrix for the Cellular Automata.   
    std::cout << "The intial matrix state: " << std::endl;
    Test2.print();

    //30 steps with majority rule and von neumaan neighborhood;
    //Create simulation
    ComputeEngine sim2 = ComputeEngine(30,1,2, &Test2);

    //run simulation
    std::cout << std::endl;
    std::cout << "Running the simulation for 30 steps with majority rules and Von Neumaan neighborhood..." << std::endl;
    std::cout << std::endl;
    sim2.run();

    // Print out the final matrix for the Cellular Automata.
    std::cout << "The Final matrix state: " << std::endl;
    Test2.print();
    std::cout << std::endl;
    std::cout << std::endl;

    // Test #3
    // Testing the creation of a cellular automata when data is generated randomly.
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};
    CellularAutomata Test3(30, 30, test_legend, "char", "fire", (std::pair<int, int>) {5, 5});
    
    // Print out the intial matrix for the Cellular Automata.   
    std::cout << "The intial matrix state: " << std::endl;
    Test3.print();

    // 45 steps with majority rule and von neumaann neighborhood;
    // Create simulation
    ComputeEngine sim3 = ComputeEngine(42,1,2, &Test3);

    //run simulation
    std::cout << std::endl;
    std::cout << "Running the simulation for 42 steps with majority rules and Von Neumaann neighborhood..." << std::endl;
    std::cout << std::endl;
    sim3.run();

    // Print out the final matrix for the Cellular Automata.
    std::cout << "The Final matrix state: " << std::endl;
    Test3.print();
    std::cout << std::endl;
    std::cout << std::endl;

    // Test #4
    // Testing the creation of a cellular automata when data is generated randomly.
    std::map<std::string, int> test_legend_p{{"empty", 0}, {"tree", 1}};
    CellularAutomata Test4(50, 50, test_legend_p, "NULL", "NULL", (std::pair<int, int>) {5, 5});
    
    // Print out the intial matrix for the Cellular Automata.   
    std::cout << "The intial matrix state: " << std::endl;
    Test4.print();

    // 50 steps with parity rule and moore neighborhood;
    // Create simulation
    ComputeEngine sim4 = ComputeEngine(50,2,1, &Test4);

    //run simulation
    std::cout << std::endl;
    std::cout << "Running the simulation for 50 steps with parity rules and Moore neighborhood..." << std::endl;
    std::cout << std::endl;
    sim4.run();

    // Print out the final matrix for the Cellular Automata.
    std::cout << "The Final matrix state: " << std::endl;
    Test4.print();
    std::cout << std::endl;
    std::cout << std::endl;

    // Test #5
    // Testing the creation of a cellular automata when data is generated randomly.
    CellularAutomata Test5(22, 22, test_legend_p, "NULL", "NULL", (std::pair<int, int>) {5, 5});
    
    // Print out the intial matrix for the Cellular Automata.   
    std::cout << "The intial matrix state: " << std::endl;
    Test5.print();

    // 100 steps with parity rule and von neumaann neighborhood;
    // Create simulation
    ComputeEngine sim5 = ComputeEngine(100,2,2, &Test5);

    //run simulation
    std::cout << std::endl;
    std::cout << "Running the simulation for 100 steps with majority rules and Moore neighborhood..." << std::endl;
    std::cout << std::endl;
    sim5.run();

    // Print out the final matrix for the Cellular Automata.
    std::cout << "The Final matrix state: " << std::endl;
    Test5.print();
    std::cout << std::endl;
    std::cout << std::endl;
}