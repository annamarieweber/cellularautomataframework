#include <iostream>
#include <vector>
#include <map>
#include <utility>

class CellularAutomata
{
    private:
        // Holds the dimensions of the Cellular Automata.
        int _size;

        // Holds the data for the Cellular Automata as a vector of vectors.
        std::vector<std::vector<int>> _data;

        // Holds the legend information for the Cellular Automata. Where the string passed in is the name of the state, and the integer is the value for that state.
        std::map<std::string, int> _legend;

        // Holds the legend information of the Cellular Automata as well as densities for each state. Where the string is the name of the state, the pair contains the value for that state (integer) and density (float, from 0.0-1.0).
        std::map<std::string, std::pair<int, float>> _legend_density;

        // Number of rows in the cellular automata, or its height.
        int _rows;

        // Number of columns in the cellular automata, or its width.
        int _columns;

        // The name of the state which is a product of any rules (ex. a tree burns to become charred, so charred would be the product).
        std::string _product;

        // The name of the state which is reacting with others to change them (ex. fire burns a tree so it becomes charred, so fire would be the reactor).
        std::string _reactor;

        // A pair of integers which signify the starting position to place the reactor state.
        std::pair<int, int> _starting_position;
        
    public:
        // Constructor for the class, requires all data for the Cellular Automata to be passed in.
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::vector<std::vector<int>> data, std::string product, std::string reactor, std::pair<int, int> starting_position);

        // Another constructor for the class, calls the initialization to set up the Cellular Automata randomly.
        CellularAutomata(int rows, int columns, std::map<std::string, int> legend, std::string product, std::string reactor, std::pair<int, int> starting_position);

        // Another constructor for the class, calls the initialization to set up the Cellular Automata using density values passed in.
        CellularAutomata(int rows, int columns, std::map<std::string, std::pair<int, float>> legend, std::string product, std::string reactor, std::pair<int, int> starting_position);

        // Intiatlize function to create a cellular automata randomly.
        void Initialize_Rand();

        // Intialize function to create a cellular automata using density values.
        void Initialize_Density();

        // Code to evaluate von neumaan neighborhood where r=1.
        void vn_neighborhood(int row, int column);

        // Code to evaluate moore neighborhood where r=1.
        void moore_neighborhood(int row, int column);

        // Getter function to retrieve the data of the Cellular Automata.
        std::vector<std::vector<int>> get_data();

        // Gives information on the stats of the states in the Cellular Automata. 
        void get_stats();

        void step(int rule_num);

        void run(int num_steps, int rule_num);

        // Function to print out the Cellular Automata.
        void print();
};
