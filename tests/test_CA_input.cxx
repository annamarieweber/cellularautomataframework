#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    std::vector<int> test = {0, 1, 0, 1, 0, 1, 0, 1, 2};
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};
    CellularAutomata Test(3, 3, test_legend, test, "char", "fire", std::pair<int, int> {2, 2});
    Test.vn_neighborhood(2, 2);
    std::cout << std::endl;
    Test.print();
    Test.vn_neighborhood(0, 0);

    std::cout << std::endl;
    std::cout << std::endl;
    CellularAutomata Test_2(10, 10, test_legend, "char", "fire", std::pair<int, int> {3, 3});
    Test_2.print();
    Test_2.vn_neighborhood(5,5);
}