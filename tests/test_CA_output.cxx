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

    // Test #4
    // Creating cellular automata randomly with a large amount of rows and columns.
    // Creating a 50x50 matrix, printing and getting its statistics
    // Depending on your terminal size, the larger Cellular Automata may appear distorted, by changing your terminal size you will rescale them and it will appear easier to see.
    
    std::map<std::string, int> test_legend4{{"empty", 0}, {"tree", 1}, {"shrub", 2}, {"flower", 3}, {"fire", 4}, {"char", 5},};
    CellularAutomata Test_5a(50, 50, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 50x50 cellular automaton and retreiving its statistics:" << std::endl;
    Test_5a.print();
    Test_5a.get_stats();
    std::cout << std::endl;

    // Creating a 100x100 matrix, printing and getting its statistics, reusing the legend created above.
    CellularAutomata Test_6(100, 100, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 100x100 cellular automaton and retreiving its statistics:" << std::endl;
    Test_6.print();
    Test_6.get_stats();
    std::cout << std::endl;

    // Creating a 1000x1000 matrix, printing and getting its statistics, reusing the legend created above.
    CellularAutomata Test_7(1000, 1000, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 1000x1000 cellular automaton and retreiving its statistics:" << std::endl;

    Test_7.print();
    Test_7.get_stats();
    std::cout << std::endl;

    // Creating a 500x500 matrix, printing and getting its statistics, reusing the legend created above.
    CellularAutomata Test_8(500, 500, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 500x500 cellular automaton and retreiving its statistics:" << std::endl;
    Test_8.print();
    Test_8.get_stats();
    std::cout << std::endl;

    // Test #5
    // Creating cellular automata randomly with unequal rows and columns (non-square matrices).
    // Creating a 20x50 matrix, printing and getting its statistics
    // Depending on your terminal size, the larger Cellular Automata may appear distorted, by changing your terminal size you will rescale them and it will appear easier to see.
    CellularAutomata Test_9(20, 50, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 20x50 cellular automaton and retreiving its statistics:" << std::endl;
    Test_9.print();
    Test_9.get_stats();
    std::cout << std::endl;

    // Creating a 15x201 matrix, printing and getting its statistics
    CellularAutomata Test_10(15, 201, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 15x201 cellular automaton and retreiving its statistics:" << std::endl;
    Test_10.print();
    Test_10.get_stats();
    std::cout << std::endl;

    // Creating a 37x74 matrix, printing and getting its statistics
    CellularAutomata Test_11(37, 74, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 37x74 cellular automaton and retreiving its statistics:" << std::endl;
    Test_11.print();
    Test_11.get_stats();
    std::cout << std::endl;

    // Creating a 243x112 matrix, printing and getting its statistics
    CellularAutomata Test_12(243, 112, test_legend4, "char", "fire", std::pair<int, int> {2, 2});
    std::cout << "Testing the creation of a 243x112 cellular automaton and retreiving its statistics:" << std::endl;
    Test_12.print();
    Test_12.get_stats();
    std::cout << std::endl;
    std::cout << "Depending on your terminal size, the larger Cellular Automata may appear distorted, by changing your terminal size you will rescale them and it will appear easier to see." << std::endl;
    std::cout << std::endl;
}