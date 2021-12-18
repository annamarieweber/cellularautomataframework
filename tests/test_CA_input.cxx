#include "CellularAutomata.h"
#include "myutils.h"
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    // Testing the creation of a cellular automata when data is directly passed in.

    std::cout << "Creating Cellular Automata given data: " << std::endl;
    std::vector<std::vector<int>> test = {{1, 1, 1}, {1, 0, 1}, {0, 1, 2}};
    std::map<std::string, int> test_legend{{"empty", 0}, {"tree", 1}, {"fire", 2}, {"char", 3}};
    CellularAutomata Test(3, 3, test_legend, test, "char", "fire", std::pair<int, int> {2, 2});
    // Printing the cellular automata to terminal.
    Test.print();  
    std::cout << std::endl;

    // Testing von neumaan neighborhood analysis.
    std::cout << "Testing Von Neumaan Neighborhood funtionality around 1,1:" << std::endl;
    // Storing the von neumaan neighborhood inside of a vector as it is the return type of the method vn_neighborhood.
    std::vector<int> vn_neighbourhood_test = Test.vn_neighborhood(1, 1);
    // Printing the von neumaan neighborhood from the vector. The first element is north, second is west, third is east and fourth is south.
    
        std::cout << "North neighbour is: " << vn_neighbourhood_test[0] << std::endl;
        std::cout << "East neighbour is: " << vn_neighbourhood_test[2] << std::endl;
        std::cout << "South neighbour is: " << vn_neighbourhood_test[3] << std::endl;
        std::cout << "West neighbour is: " << vn_neighbourhood_test[1] << std::endl;

    std::cout << std::endl;
    
    std::cout << "Testing Von Neumaan Neighborhood funtionality and periodic bounds around 0,0:" << std::endl;
    // Storing the von neumaan neighborhood inside of a vector as it is the return type of the method vn_neighborhood.
    std::vector<int> vn_neighbourhood_test2 = Test.vn_neighborhood(0, 1);
    // Printing the von neumaan neighborhood from the vector. The first element is north, second is west, third is east and fourth is south.
    
        std::cout << "North neighbour is: " << vn_neighbourhood_test2[0] << std::endl;
        std::cout << "East neighbour is: " << vn_neighbourhood_test2[2] << std::endl;
        std::cout << "South neighbour is: " << vn_neighbourhood_test2[3] << std::endl;
        std::cout << "West neighbour is: " << vn_neighbourhood_test2[1] << std::endl;

    std::cout << std::endl;

    // Testing moore neighborhood analysis
    std::cout << "Testing Moore Neighborhood funtionality around 1,1:" << std::endl;
    // Storing the moore neighborhood inside of a vector as it is the return type of the method moore_neighborhood.
    std::vector<int> moore_neighbourhood_test = Test.moore_neighborhood(1, 1);
    // Printing the moore neighborhood from the vector. The elements of the vector are in the following order: northwest, north, northeast, west, east, south_west, south, southeast.
    
        std::cout << "North West neighbour is: " << moore_neighbourhood_test[0] << std::endl;
        std::cout << "North neighbour is: " << moore_neighbourhood_test[1] << std::endl;
        std::cout << "North East neighbour is: " << moore_neighbourhood_test[2] << std::endl;
        std::cout << "East neighbour is: " << moore_neighbourhood_test[4] << std::endl;
        std::cout << "South East neighbour is: " << moore_neighbourhood_test[7] << std::endl;    
        std::cout << "South neighbour is: " << moore_neighbourhood_test[6] << std::endl;
        std::cout << "South West neighbour is: " << moore_neighbourhood_test[5] << std::endl;
        std::cout << "West neighbour is: " << moore_neighbourhood_test[3] << std::endl;

    std::cout << std::endl;

    std::cout << "Testing Moore Neighborhood funtionality and periodic bounds around 0,1:" << std::endl;
    // Storing the moore neighborhood inside of a vector as it is the return type of the method moore_neighborhood.
    std::vector<int> moore_neighbourhood_test2 = Test.moore_neighborhood(0, 1);
    // Printing the moore neighborhood from the vector. The elements of the vector are in the following order: northwest, north, northeast, west, east, south_west, south, southeast.
    
        std::cout << "North West neighbour is: " << moore_neighbourhood_test2[0] << std::endl;
        std::cout << "North neighbour is: " << moore_neighbourhood_test2[1] << std::endl;
        std::cout << "North East neighbour is: " << moore_neighbourhood_test2[2] << std::endl;
        std::cout << "East neighbour is: " << moore_neighbourhood_test2[4] << std::endl;
        std::cout << "South East neighbour is: " << moore_neighbourhood_test2[7] << std::endl;    
        std::cout << "South neighbour is: " << moore_neighbourhood_test2[6] << std::endl;
        std::cout << "South West neighbour is: " << moore_neighbourhood_test2[5] << std::endl;
        std::cout << "West neighbour is: " << moore_neighbourhood_test2[3] << std::endl;

    std::cout << std::endl;

    // Testing the creation of a cellular automata when data is generated randomly, using the legend created above.

    std::cout << "Creating Cellular Automata Randomly: " << std::endl;
    CellularAutomata Test_2(10, 10, test_legend, "char", "fire", std::pair<int, int> {5, 5});
    // Printing the cellular automata to terminal.
    Test_2.print();
    std::cout << std::endl;

    // Testing von neumaan neighborhood analysis.
    std::cout << "Testing Von Neumaan Neighborhood funtionality around 5,5:" << std::endl;
    // Storing the von neumaan neighborhood inside of a vector as it is the return type of the method vn_neighborhood.
    std::vector<int> vn_neighbourhood_test3 = Test_2.vn_neighborhood(5, 5);
    // Printing the von neumaan neighborhood from the vector. The first element is north, second is west, third is east and fourth is south.
    
        std::cout << "North neighbour is: " << vn_neighbourhood_test3[0] << std::endl;
        std::cout << "East neighbour is: " << vn_neighbourhood_test3[2] << std::endl;
        std::cout << "South neighbour is: " << vn_neighbourhood_test3[3] << std::endl;
        std::cout << "West neighbour is: " << vn_neighbourhood_test3[1] << std::endl;

    std::cout << std::endl;
    
    std::cout << "Testing Von Neumaan Neighborhood funtionality and periodic bounds around 0,0:" << std::endl;
    // Storing the von neumaan neighborhood inside of a vector as it is the return type of the method vn_neighborhood.
    std::vector<int> vn_neighbourhood_test4 = Test_2.vn_neighborhood(0, 5);
    // Printing the von neumaan neighborhood from the vector. The first element is north, second is west, third is east and fourth is south.
    
        std::cout << "North neighbour is: " << vn_neighbourhood_test4[0] << std::endl;
        std::cout << "East neighbour is: " << vn_neighbourhood_test4[2] << std::endl;
        std::cout << "South neighbour is: " << vn_neighbourhood_test4[3] << std::endl;
        std::cout << "West neighbour is: " << vn_neighbourhood_test4[1] << std::endl;

    std::cout << std::endl;

    // Testing moore neighborhood analysis
    std::cout << "Testing Moore Neighborhood funtionality around 5,5:" << std::endl;
    // Storing the moore neighborhood inside of a vector as it is the return type of the method moore_neighborhood.
    std::vector<int> moore_neighbourhood_test3 = Test_2.moore_neighborhood(5, 5);
    // Printing the moore neighborhood from the vector. The elements of the vector are in the following order: northwest, north, northeast, west, east, south_west, south, southeast.
    
        std::cout << "North West neighbour is: " << moore_neighbourhood_test3[0] << std::endl;
        std::cout << "North neighbour is: " << moore_neighbourhood_test3[1] << std::endl;
        std::cout << "North East neighbour is: " << moore_neighbourhood_test3[2] << std::endl;
        std::cout << "East neighbour is: " << moore_neighbourhood_test3[4] << std::endl;
        std::cout << "South East neighbour is: " << moore_neighbourhood_test3[7] << std::endl;    
        std::cout << "South neighbour is: " << moore_neighbourhood_test3[6] << std::endl;
        std::cout << "South West neighbour is: " << moore_neighbourhood_test3[5] << std::endl;
        std::cout << "West neighbour is: " << moore_neighbourhood_test3[3] << std::endl;

    std::cout << std::endl;

    std::cout << "Testing Moore Neighborhood funtionality and periodic bounds around 0,5:" << std::endl;
    // Storing the moore neighborhood inside of a vector as it is the return type of the method moore_neighborhood.
    std::vector<int> moore_neighbourhood_test4 = Test_2.moore_neighborhood(0, 5);
    // Printing the moore neighborhood from the vector. The elements of the vector are in the following order: northwest, north, northeast, west, east, south_west, south, southeast.
    
        std::cout << "North West neighbour is: " << moore_neighbourhood_test4[0] << std::endl;
        std::cout << "North neighbour is: " << moore_neighbourhood_test4[1] << std::endl;
        std::cout << "North East neighbour is: " << moore_neighbourhood_test4[2] << std::endl;
        std::cout << "East neighbour is: " << moore_neighbourhood_test4[4] << std::endl;
        std::cout << "South East neighbour is: " << moore_neighbourhood_test4[7] << std::endl;    
        std::cout << "South neighbour is: " << moore_neighbourhood_test4[6] << std::endl;
        std::cout << "South West neighbour is: " << moore_neighbourhood_test4[5] << std::endl;
        std::cout << "West neighbour is: " << moore_neighbourhood_test4[3] << std::endl;

    std::cout << std::endl;

    // Testing the creation of a cellular automata when data is generated based on density values with a legend containing density values.

    std::cout << "Creating Cellular Automata using Density: " << std::endl;
    std::map<std::string, std::pair<int, float>> test_legend_density{{"empty", {0, 0.5}}, {"tree", {1, 0.5}}, {"fire", {2, 0.0}}, {"char", {3, 0.0}}};
    CellularAutomata Test_3(10, 10, test_legend_density, "char", "fire", std::pair<int, int> {5, 5});
    // Printing the cellular automata to terminal.
    Test_3.print();
    std::cout << std::endl;

    // Testing von neumaan neighborhood analysis.
    std::cout << "Testing Von Neumaan Neighborhood funtionality around 0,5:" << std::endl;
    // Storing the von neumaan neighborhood inside of a vector as it is the return type of the method vn_neighborhood.
    std::vector<int> vn_neighbourhood_test5 = Test_3.vn_neighborhood(5, 5);
    // Printing the von neumaan neighborhood from the vector. The first element is north, second is west, third is east and fourth is south.
    
        std::cout << "North neighbour is: " << vn_neighbourhood_test5[0] << std::endl;
        std::cout << "East neighbour is: " << vn_neighbourhood_test5[2] << std::endl;
        std::cout << "South neighbour is: " << vn_neighbourhood_test5[3] << std::endl;
        std::cout << "West neighbour is: " << vn_neighbourhood_test5[1] << std::endl;

    std::cout << std::endl;
    
    std::cout << "Testing Von Neumaan Neighborhood funtionality and periodic bounds around 0,0:" << std::endl;
    // Storing the von neumaan neighborhood inside of a vector as it is the return type of the method vn_neighborhood.
    std::vector<int> vn_neighbourhood_test6 = Test_3.vn_neighborhood(0, 5);
    // Printing the von neumaan neighborhood from the vector. The first element is north, second is west, third is east and fourth is south.
    
        std::cout << "North neighbour is: " << vn_neighbourhood_test6[0] << std::endl;
        std::cout << "East neighbour is: " << vn_neighbourhood_test6[2] << std::endl;
        std::cout << "South neighbour is: " << vn_neighbourhood_test6[3] << std::endl;
        std::cout << "West neighbour is: " << vn_neighbourhood_test6[1] << std::endl;

    std::cout << std::endl;

    // Testing moore neighborhood analysis
    std::cout << "Testing Moore Neighborhood funtionality around 5,5:" << std::endl;
    // Storing the moore neighborhood inside of a vector as it is the return type of the method moore_neighborhood.
    std::vector<int> moore_neighbourhood_test5 = Test_3.moore_neighborhood(5, 5);
    // Printing the moore neighborhood from the vector. The elements of the vector are in the following order: northwest, north, northeast, west, east, south_west, south, southeast.
    
        std::cout << "North West neighbour is: " << moore_neighbourhood_test5[0] << std::endl;
        std::cout << "North neighbour is: " << moore_neighbourhood_test5[1] << std::endl;
        std::cout << "North East neighbour is: " << moore_neighbourhood_test5[2] << std::endl;
        std::cout << "East neighbour is: " << moore_neighbourhood_test5[4] << std::endl;
        std::cout << "South East neighbour is: " << moore_neighbourhood_test5[7] << std::endl;    
        std::cout << "South neighbour is: " << moore_neighbourhood_test5[6] << std::endl;
        std::cout << "South West neighbour is: " << moore_neighbourhood_test5[5] << std::endl;
        std::cout << "West neighbour is: " << moore_neighbourhood_test5[3] << std::endl;

    std::cout << std::endl;

    std::cout << "Testing Moore Neighborhood funtionality and periodic bounds around 0,5:" << std::endl;
    // Storing the moore neighborhood inside of a vector as it is the return type of the method moore_neighborhood.
    std::vector<int> moore_neighbourhood_test6 = Test_3.moore_neighborhood(0, 5);
    // Printing the moore neighborhood from the vector. The elements of the vector are in the following order: northwest, north, northeast, west, east, south_west, south, southeast.
    
        std::cout << "North West neighbour is: " << moore_neighbourhood_test6[0] << std::endl;
        std::cout << "North neighbour is: " << moore_neighbourhood_test6[1] << std::endl;
        std::cout << "North East neighbour is: " << moore_neighbourhood_test6[2] << std::endl;
        std::cout << "East neighbour is: " << moore_neighbourhood_test6[4] << std::endl;
        std::cout << "South East neighbour is: " << moore_neighbourhood_test6[7] << std::endl;    
        std::cout << "South neighbour is: " << moore_neighbourhood_test6[6] << std::endl;
        std::cout << "South West neighbour is: " << moore_neighbourhood_test6[5] << std::endl;
        std::cout << "West neighbour is: " << moore_neighbourhood_test6[3] << std::endl;

    std::cout << std::endl;

    // Testing the various getter and setter functions as part of the library.

    // Creating cellular automata randomly with many states.
    std::map<std::string, int> test_legend3{{"empty", 0}, {"tree", 1}, {"shrub", 2}, {"flower", 3}, {"fire", 4}, {"char", 5},};
    CellularAutomata Test4(20, 20, test_legend3, "char", "fire", std::pair<int, int> {2, 2});
    Test4.print();
    std::cout << std::endl;
    
    // Getting the state of cell 2,2. This should be fire (4), because we are intializing it at 2,2.
    int cell_state_int = Test4.get_cell(2 ,2);
    std::cout << "The integer value for the state at 2,2 is: " << cell_state_int << std::endl;
    std::cout << std::endl;

    // Updating the state of cell 2,2 to flower which is represented by 3.
    std::cout << "Updating cell 2,2..." << std::endl;
    Test4.update_cell(2, 2, 5);
    int updated_cell_state_int = Test4.get_cell(2 ,2);
    std::cout << "After updated the cell, the integer value for the state at 2,2 is: " << updated_cell_state_int << std::endl;
    std::cout << std::endl;

    // Getting the number of rows in the cellular automata
    int rows = Test4.get_rows();
    std::cout << "The number of rows are: " << rows << std::endl;
    std::cout << std::endl;

    // Getting the number of columns in the cellular automata
    int columns = Test4.get_columns();
    std::cout << "The number of columns are: " << columns << std::endl;
    std::cout << std::endl;

    // Getting the size of the cellular automata (rows x columns)
    int size = Test4.get_size();
    std::cout << "The size is: " << size << std::endl;
    std::cout << std::endl;

    // Getting the number of states in the cellular automata
    int states = Test4.get_num_states();
    std::cout << "The number of states are: " << states << std::endl;
    std::cout << std::endl;
}