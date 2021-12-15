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

    // Creating Cellular Automata Randomly
    std::cout << "Creating Cellular Automata Randomly: " << std::endl;
    CellularAutomata Test_1(10, 10, test_legend, "char", "fire", std::pair<int, int> {5, 5});

    // Testing the Cellular Automata printing to terminal.
    Test_1.print();
    std::cout << std::endl;

    // Testing getting stats on the Cellular Automata.
    Test_1.get_stats();
    std::cout << std::endl;

    // Testing retrieving vector containing data from Cellular Automata.
    std::cout << "Getting the randomly created data from the Cellular Automata above..." << std::endl;
    std::vector<std::vector<int>> test_1_data = Test_1.get_data();

    // Using the data retrieved to create another Cellular Automata.
    std::cout << "Creating a new Cellular Automata with the generated data from the Cellular Automata above (they will have identical values):" << std::endl;
    CellularAutomata Test_2(10, 10, test_legend, test_1_data, "char", "fire", std::pair<int, int> {5, 5});

    // Printing the new Cellular Automata to terminal. Should be identical to the Cellular Automata printed above. However if I wanted I could change the initial starting point for the new version, thus changing them ever so slightly. This could be useful if someone wanted to generate the same starting matrix but and an additional intial starting position to see different effects (see below).
    Test_2.print();
    std::cout << std::endl;

    std::cout << "Creating a new Cellular Automata with the generated data from the Cellular Automata above but changing the starting position to 0,0" << std::endl;
    std::cout << "This new Cellular Automata has a fire starting at 0,0 as well as in the middle at 5,5 like the other 2. That is the only difference." << std::endl;
    CellularAutomata Test_5(10, 10, test_legend, test_1_data, "char", "fire", std::pair<int, int> {0, 0});
    Test_5.print();
    std::cout << std::endl;

    // Test #2
    // Creating Cellular Automata using Density
    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.5}}, {"tree", {1, 0.5}}, {"fire", {2, 0.0}}, {"char", {3, 0.0}}};
    CellularAutomata Test_3(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});

    // Testing the Cellular Automata printing to terminal.
    Test_3.print();
    std::cout << std::endl;

    // Testing getting stats on the Cellular Automata.
    Test_3.get_stats();
    std::cout << std::endl;

    // Test #3
    // Creating cellular automata randomly with many states.
    std::map<std::string, int> test_legend3{{"empty", 0}, {"tree", 1}, {"shrub", 2}, {"flower", 3}, {"fire", 4}, {"char", 5},};
    CellularAutomata Test_4(30, 30, test_legend3, "char", "fire", std::pair<int, int> {2, 2});
    Test_4.print();
    std::cout << std::endl;
    
    // Getting the state of cell 2,2. This should be fire (4), because we are intializing it at 2,2.
    int cell_state_int = Test_4.get_cell(2 ,2);
    std::cout << "The integer value for the state at 2,2 is: " << cell_state_int << std::endl;
    std::cout << std::endl;

    // Getting the number of rows in the cellular automata
    int rows = Test_4.get_rows();
    std::cout << "The number of rows are: " << rows << std::endl;
    std::cout << std::endl;

    // Getting the number of columns in the cellular automata
    int columns = Test_4.get_columns();
    std::cout << "The number of columns are: " << columns << std::endl;
    std::cout << std::endl;

    // Getting the size of the cellular automata (rows x columns)
    int size = Test_4.get_size();
    std::cout << "The size is: " << size << std::endl;
    std::cout << std::endl;

    // Getting the number of states in the cellular automata
    int states = Test_4.get_num_states();
    std::cout << "The number of states are: " << states << std::endl;
    std::cout << std::endl;
}