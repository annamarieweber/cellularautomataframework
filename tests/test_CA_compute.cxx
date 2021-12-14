#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    // Testing the creation of a cellular automata when data is directly passed in
    std::cout << "Creating Cellular Automata given data: " << std::endl;
    std::vector<std::vector<int> > test = {{3, 2, 1, 2}, {1,3, 3, 1}, {0, 3, 1, 1},{3,0, 2, 0}};
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};
    
    CellularAutomata Test1(4, 4, test_legend, test, "char", "fire", (std::pair<int, int>) {2, 2});
    Test1.print();   

    //3 steps with majority rule and moore neighborhood;
    Test1.run(3,1,1); 

    // Testing the creation of a cellular automata when data is directly passed in
    CellularAutomata Test2(4, 4, test_legend, test, "char", "fire", (std::pair<int, int>) {2, 2});
    Test2.print();   

    //3 steps with purity rule and moore neighborhood;
    Test2.run(3,2,1); 


}