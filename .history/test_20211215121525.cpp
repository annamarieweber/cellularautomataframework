#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

int main() {
    _rows = 5;
    
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    std::vector<std::vector<int>> Matrix(5, std::vector<int>(7,0));

    for (auto it1 = Matrix.begin(); it1 != Matrix.end(); it1++) {
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++) {
            *it2 = dis(gen); // dereference iterator, set the value
            std::cout << std::setw(4) << *it2;
        }
        std::cout << '\n';
    }
}
