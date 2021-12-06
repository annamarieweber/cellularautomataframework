#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    std::cout << "Creating Cellular Automata given data: " << std::endl;
    std::vector<std::vector<int>> test = {{1, 1, 1}, {1, 0, 1}, {0, 1, 2}};
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};
    CellularAutomata Test(3, 3, test_legend, test, "char", "fire", std::pair<int, int> {2, 2});
    Test.print();    
    Test.vn_neighborhood(2, 2);
    std::cout << std::endl;
    Test.vn_neighborhood(0, 0);
    std::cout << std::endl;
    std::cout << "Testing Moore Neighborhood funtionality around 5,5:" << std::endl;
    Test.moore_neighborhood(1, 1);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Creating Cellular Automata Randomly: " << std::endl;
    CellularAutomata Test_2(10, 10, test_legend, "char", "fire", std::pair<int, int> {5, 5});
    Test_2.print();
    Test_2.vn_neighborhood(5,5);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.5}}, {"tree", {1, 0.5}}, {"fire", {2, 0.0}}, {"char", {3, 0.0}}};
    CellularAutomata Test_3(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});
    Test_3.print();
    Test_3.vn_neighborhood(5,5);
    std::cout << std::endl;
    std::cout << std::endl;
}