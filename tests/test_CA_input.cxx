#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    std::vector<int> test = {0, 1, 2, 3, 0, 1, 2, 3, 0};
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};
    CellularAutomata Test(3, 3, test_legend, test);
    Test.vn_neighborhood(2, 2);
    std::cout << std::endl;
    Test.vn_neighborhood(0, 0);

    std::cout << std::endl;
    std::cout << std::endl;
    CellularAutomata Test_2(3, 3, test_legend);
    Test_2.print();
    Test_2.vn_neighborhood(2,2);
}